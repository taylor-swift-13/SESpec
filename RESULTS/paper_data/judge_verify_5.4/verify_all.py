#!/usr/bin/env python3
"""Unified strength verifier: postcond + per-loop, per-case directory.

For each (A, B) pair in the dual-valid CSV we synthesize:

    harness/<case_id>/postcond.c          - A vs B function contract mutual impl
    harness/<case_id>/loop1.c             - mutual impl for invariants of loop 1
    harness/<case_id>/loop2.c             - ... loop 2
    ...

Each helper `logic`/`predicate` declaration goes into its own /*@ */ block
(some WP setups dislike multi-declaration blocks).

Aggregation per case (across postcond + every matched loop):
    A_stronger   - every A=>B direction succeeds AND at least one B=>A fails
    B_stronger   - symmetric
    equal        - every direction succeeds both ways
    incomparable - failures on both sides
    inconclusive - no failures but some directions inconclusive
    n/a          - no comparable component (no contract, no matched loop)

A per-harness cache keyed on SHA256(content) + cmd avoids re-running WP when
the harness body has not changed.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import os
import re
import subprocess
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

ROOT = Path("/home/yangfp/SESpec")
DATA = ROOT / "RESULTS/paper_data"
OUT = DATA / "judge_verify_5.4"
HARNESS_DIR = OUT / "harness"
CACHE_FILE = OUT / "wp_cache.json"
OUT.mkdir(exist_ok=True)
HARNESS_DIR.mkdir(exist_ok=True)

# --------- regexes & keyword sets ---------
ANNOT_RE = re.compile(r"/\*@(.*?)\*/", re.DOTALL)
INCLUDE_RE = re.compile(r"^\s*#\s*include\s+[<\"][^>\"]+[>\"]\s*$", re.MULTILINE)
QUANT_HEAD_RE = re.compile(r"\\(forall|exists|let)\b")
DECL_RE = re.compile(r"\b(logic|predicate|inductive|axiomatic|axiom|lemma|type)\b")
IDENT_RE = re.compile(r"\\?[A-Za-z_][A-Za-z0-9_]*")

FUNC_RE = re.compile(
    r"""
    ^\s*
    (?P<rettype>(?:const\s+)?(?:unsigned\s+|signed\s+)?
                (?:void|int|char|short|long\s+long(?:\s+int)?|long\s+int|long|
                   float|double|size_t|ssize_t|
                   uint8_t|uint16_t|uint32_t|uint64_t|
                   int8_t|int16_t|int32_t|int64_t|_Bool|bool)
                (?:\s*\*+)?(?:\s*const)?(?:\s*\*+)?)
    \s+
    (?P<name>\w+)
    \s*\(
    (?P<params>[^)]*)
    \)
    \s*(;|\{)
    """,
    re.VERBOSE | re.MULTILINE,
)

ACSL_KEYWORDS = {
    "true", "false", "integer", "real", "boolean", "result", "old",
    "at", "Pre", "Post", "LoopEntry", "LoopCurrent", "Here", "nothing",
    "valid", "valid_read", "separated", "exists", "forall", "let", "in",
    "max", "min", "abs", "sum", "block_length", "offset",
    "base_addr", "type", "logic", "predicate", "axiomatic", "lemma",
    "ensures", "requires", "assigns", "loop", "invariant", "variant",
    "decreases", "behavior", "complete", "assumes", "assert",
}
C_KEYWORDS = {
    "int", "long", "short", "signed", "unsigned", "char", "float", "double",
    "void", "const", "volatile", "static", "extern", "register", "auto",
    "struct", "union", "enum", "typedef", "sizeof", "if", "else", "while",
    "for", "do", "return", "break", "continue", "goto", "switch", "case",
    "default", "NULL", "null", "_Bool", "bool",
}

TRIVIAL_CONTRACT = "\n  requires \\true;\n  assigns \\nothing;\n  ensures \\true;\n"

# --------- annotation parsing ---------

def split_annotations(text):
    return [(m.start(), m.end(), m.group(1)) for m in ANNOT_RE.finditer(text)]


def extract_includes(text):
    return sorted(set(m.group(0).strip() for m in INCLUDE_RE.finditer(text)))


def is_contract_body(body):
    """True if this annotation body is a function-level contract."""
    stripped = re.sub(r"\bloop\s+(invariant|assigns|variant)\b", "_LP_", body)
    return bool(
        re.search(
            r"\b(requires|ensures|assigns|allocates|frees|behavior|complete|disjoint|decreases)\b",
            stripped,
        )
    )


def split_invariants(body):
    """Split a loop annotation body into individual `loop invariant <expr>` clauses,
    respecting quantifier `;` (e.g., `\\forall T x; P(x)`) and paren depth."""
    out, n, i = [], len(body), 0
    while i < n:
        m = re.search(r"loop\s+invariant\s+", body[i:])
        if not m:
            break
        start = i + m.end()
        j, depth, pending = start, 0, 0
        while j < n:
            if depth == 0:
                qm = QUANT_HEAD_RE.match(body, j)
                if qm:
                    pending += 1
                    j = qm.end()
                    continue
            c = body[j]
            if c in "([":
                depth += 1
            elif c in ")]":
                depth -= 1
                if depth < 0:
                    break
            elif c == ";" and depth == 0:
                if pending > 0:
                    pending -= 1
                    j += 1
                    continue
                break
            j += 1
        expr = re.sub(r"\s+", " ", body[start:j].strip())
        if expr:
            out.append(expr)
        i = j + 1
    return out


def split_helper_decls(body):
    """Split a multi-decl helper annotation body into individual decl strings.

    Each `logic`/`predicate`/`inductive`/`axiomatic`/`axiom`/`lemma`/`type`
    declaration becomes its own string. Axiomatic blocks are kept intact.
    """
    decls, n, i = [], len(body), 0
    while i < n:
        m = DECL_RE.search(body, i)
        if not m:
            break
        kind = m.group(1)
        start = m.start()
        if kind == "axiomatic":
            brace = body.find("{", start)
            if brace < 0:
                break
            j, depth = brace + 1, 1
            while j < n and depth:
                if body[j] == "{":
                    depth += 1
                elif body[j] == "}":
                    depth -= 1
                j += 1
            decls.append(body[start:j].strip())
            i = j
        else:
            j, depth = start, 0
            while j < n:
                c = body[j]
                if c in "([{":
                    depth += 1
                elif c in ")]}":
                    depth -= 1
                elif c == ";" and depth == 0:
                    j += 1
                    break
                j += 1
            decls.append(body[start:j].strip())
            i = j
    return decls


def parse_spec(path: Path):
    """Return {contract, fname, rettype, params, loops, helpers, includes}."""
    text = path.read_text(errors="replace")
    annots = split_annotations(text)

    # Functions outside annotations
    funcs = []
    for m in FUNC_RE.finditer(text):
        if any(s <= m.start() < e for s, e, _ in annots):
            continue
        funcs.append(m)
    if not funcs:
        raise ValueError(f"no function declaration in {path}")

    def preceding_contract(fm):
        chosen = None
        for s, e, body in annots:
            if e <= fm.start() and is_contract_body(body):
                between = text[e: fm.start()]
                if re.match(r"^\s*$", between):
                    chosen = body
        return chosen

    cdef = [fm for fm in funcs if fm.group(0).rstrip().endswith("{")]
    cdecl = [fm for fm in funcs if not fm.group(0).rstrip().endswith("{")]

    contract, func_match = None, None
    for fm in cdef + cdecl:
        c = preceding_contract(fm)
        if c is not None:
            contract = c.strip()
            func_match = fm
            break
    if func_match is None:
        func_match = (cdef or cdecl or funcs)[0]
        for s, e, body in annots:
            if is_contract_body(body):
                contract = body.strip()

    # Helpers: one per logic/predicate/... declaration, deduplicated by normalized form
    helpers, seen = [], set()
    for _, _, body in annots:
        for d in split_helper_decls(body):
            key = re.sub(r"\s+", " ", d)
            if key in seen:
                continue
            seen.add(key)
            helpers.append(d)

    # Loops: each annotation with loop invariants; ordered by position
    loops = []
    for s, _, body in annots:
        if "loop invariant" in body:
            invs = split_invariants(body)
            if invs:
                loops.append(invs)

    return {
        "path": str(path),
        "fname": func_match.group("name"),
        "rettype": func_match.group("rettype").strip(),
        "params": func_match.group("params").strip(),
        "contract": contract,
        "loops": loops,
        "helpers": helpers,
        "includes": extract_includes(text),
    }


def param_names(params):
    if not params or params.strip() == "void":
        return []
    out = []
    for p in params.split(","):
        p = re.sub(r"\[[^\]]*\]\s*$", "", p.strip())
        m = re.search(r"(\w+)\s*$", p)
        if m:
            out.append(m.group(1))
    return out


# --------- harness builders ---------

def build_postcond_harness(A, B, helpers, helper_names):
    includes = sorted(set(A["includes"] + B["includes"] + ["#include <limits.h>"]))
    rettype = A["rettype"] or B["rettype"]
    params = A["params"] or B["params"]
    pnames = param_names(params)
    args = ", ".join(pnames)
    void_ret = rettype.strip() == "void"
    body_a = f"    stub_A({args});" if void_ret else f"    return stub_A({args});"
    body_b = f"    stub_B({args});" if void_ret else f"    return stub_B({args});"

    a_contract = A["contract"] or TRIVIAL_CONTRACT
    b_contract = B["contract"] or TRIVIAL_CONTRACT

    lines = list(includes) + [""]
    for h in helpers:
        lines.append(f"/*@ {h} */")
    if helpers:
        lines.append("")
    lines.append(f"/*@ {a_contract} */")
    lines.append(f"{rettype} stub_A({params});")
    lines.append("")
    lines.append(f"/*@ {b_contract} */")
    lines.append(f"{rettype} stub_B({params});")
    lines.append("")
    lines.append(f"/*@ {b_contract} */")
    lines.append(f"{rettype} check_A_implies_B({params}) {{")
    lines.append(body_a)
    lines.append("}")
    lines.append("")
    lines.append(f"/*@ {a_contract} */")
    lines.append(f"{rettype} check_B_implies_A({params}) {{")
    lines.append(body_b)
    lines.append("}")
    return "\n".join(lines) + "\n"


def classify_vars(invariants, exclude):
    """For each non-excluded identifier appearing in any invariant, decide
    whether it's used as a pointer (subscript / arrow / deref) -> int*, else int.
    Returns dict: ident -> True (pointer) or False (int)."""
    kinds = {}
    for inv in invariants:
        for m in IDENT_RE.finditer(inv):
            name = m.group(0)
            if name.startswith("\\"):
                continue
            if name in ACSL_KEYWORDS or name in C_KEYWORDS or name in exclude:
                continue
            if name.isdigit():
                continue
            esc = re.escape(name)
            is_ptr = (
                re.search(rf"\b{esc}\s*\[", inv) is not None
                or re.search(rf"\b{esc}\s*->", inv) is not None
                or re.search(rf"(?<![\w\)\]])\*\s*{esc}\b", inv) is not None
            )
            kinds[name] = kinds.get(name, False) or is_ptr
    return kinds


def build_loop_harness(A_inv, B_inv, helpers, helper_names, includes):
    """One harness file for one matched loop pair."""
    all_inv = A_inv + B_inv
    var_kinds = classify_vars(all_inv, exclude=helper_names)
    if not var_kinds:
        # No variables to receive as parameters; emit a 0-arg function and let
        # WP figure it out (rare).
        params = "void"
    else:
        params = ", ".join(
            (f"int *{v}" if is_ptr else f"int {v}")
            for v, is_ptr in sorted(var_kinds.items())
        )

    A_conj = " && ".join(f"({i})" for i in A_inv) if A_inv else "\\true"
    B_conj = " && ".join(f"({i})" for i in B_inv) if B_inv else "\\true"

    lines = list(includes) + [""]
    for h in helpers:
        lines.append(f"/*@ {h} */")
    if helpers:
        lines.append("")

    lines.append(f"/*@ requires {A_conj};")
    lines.append("    assigns \\nothing;")
    lines.append("*/")
    lines.append(f"void check_A_implies_B({params}) {{")
    for b in B_inv:
        lines.append(f"    /*@ assert ({b}); */")
    lines.append("}")
    lines.append("")
    lines.append(f"/*@ requires {B_conj};")
    lines.append("    assigns \\nothing;")
    lines.append("*/")
    lines.append(f"void check_B_implies_A({params}) {{")
    for a in A_inv:
        lines.append(f"    /*@ assert ({a}); */")
    lines.append("}")
    return "\n".join(lines) + "\n"


def helper_names_from(helpers):
    names = set()
    for h in helpers:
        for m in re.finditer(r"\b(?:logic\s+\w+|predicate|inductive)\s+(\w+)\s*[\(\{]?", h):
            names.add(m.group(1))
        for m in re.finditer(r"\blogic\s+\w+\s+(\w+)\s*\(", h):
            names.add(m.group(1))
    return names


# --------- WP runner with content-hash cache ---------

def _load_cache():
    if CACHE_FILE.exists():
        try:
            return json.loads(CACHE_FILE.read_text())
        except Exception:
            return {}
    return {}


def _save_cache(cache):
    tmp = CACHE_FILE.with_suffix(".json.tmp")
    tmp.write_text(json.dumps(cache, indent=2, sort_keys=True))
    tmp.replace(CACHE_FILE)


def harness_hash(content, fn_names):
    h = hashlib.sha256()
    h.update(content.encode())
    h.update(b"\0FN\0")
    h.update(",".join(fn_names).encode())
    return h.hexdigest()


def run_wp(c_file: Path, fn_names, timeout, cache, new_entries, force=False):
    """Run WP once, chaining one `-wp -wp-fct` per name via `-then`. Returns
    {fn_name: (status, proved, total)} where status in
    {proved, failed, empty, timeout, error}.

    `cache` is read-only (shared across workers). New entries are written into
    `new_entries` (per-task local dict) so the main process can merge them
    after futures complete -- this avoids the file-write race that lost ~85%
    of entries in the parallel run.
    """
    content = c_file.read_text()
    key = harness_hash(content, fn_names)
    if not force and key in cache:
        return {nm: tuple(v) for nm, v in cache[key].items()}
    if key in new_entries:
        return {nm: tuple(v) for nm, v in new_entries[key].items()}

    cmd = ["frama-c", str(c_file), "-no-unicode"]
    for idx, nm in enumerate(fn_names):
        if idx == 0:
            cmd += ["-wp", "-wp-prover", "alt-ergo,z3",
                    "-wp-timeout", "5", "-wp-par", "1",
                    "-wp-fct", nm]
        else:
            cmd += ["-then", "-wp", "-wp-fct", nm]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True,
                           timeout=timeout, env=os.environ)
    except subprocess.TimeoutExpired:
        out = {nm: ("timeout", 0, 0) for nm in fn_names}
        new_entries[key] = {nm: list(v) for nm, v in out.items()}
        return out

    out_text = (r.stdout or "") + "\n" + (r.stderr or "")
    matches = re.findall(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", out_text)
    result = {}
    if len(matches) == len(fn_names):
        for nm, (p, t) in zip(fn_names, matches):
            p, t = int(p), int(t)
            if t == 0:
                cat = "empty"
            elif p == t:
                cat = "proved"
            else:
                cat = "failed"
            result[nm] = (cat, p, t)
    else:
        for nm in fn_names:
            result[nm] = ("error", 0, 0)
    new_entries[key] = {nm: list(v) for nm, v in result.items()}
    return result


# --------- aggregation ---------

def aggregate(components):
    """components: list of dicts with keys
        {kind, AB: (status,p,t), BA: (status,p,t), name}
    where status in {proved, failed, empty, timeout, error}.

    Returns (verdict, detail-string)."""
    def cat(side):
        # collapse per component
        if side[0] == "proved":
            return "ok"
        if side[0] == "failed":
            return "fail"
        if side[0] == "empty":
            return "ok"   # nothing to prove ≈ vacuous
        return "bad"      # timeout / error

    ab_cats = [cat(c["AB"]) for c in components]
    ba_cats = [cat(c["BA"]) for c in components]

    def all_ok(xs):
        return xs and all(x == "ok" for x in xs)

    def any_fail(xs):
        return any(x == "fail" for x in xs)

    def any_bad(xs):
        return any(x == "bad" for x in xs)

    a_covers_b = all_ok(ab_cats)
    b_covers_a = all_ok(ba_cats)

    if a_covers_b and b_covers_a:
        v = "equal"
    elif a_covers_b and any_fail(ba_cats):
        v = "A_stronger"
    elif b_covers_a and any_fail(ab_cats):
        v = "B_stronger"
    elif a_covers_b and any_bad(ba_cats):
        v = "A_stronger?"
    elif b_covers_a and any_bad(ab_cats):
        v = "B_stronger?"
    elif any_fail(ab_cats) and any_fail(ba_cats):
        v = "incomparable"
    else:
        v = "inconclusive"
    return v


# --------- per-case driver ---------

def remap_path(p):
    pp = Path(p)
    if pp.exists():
        return pp
    return Path(str(p).replace("/paper_data_final/", "/paper_data/"))


def process_case(case_id, rows, timeout, force, cache):
    """Build harness/<case_id>/{postcond.c,loop1.c,...}, run WP on each,
    aggregate, return (info, new_cache_entries)."""
    verdicts = [r["verdict"] for r in rows]
    real = [v for v in verdicts if v not in ("error", "parse_error")]
    judge = Counter(real or verdicts).most_common(1)[0][0]

    sp = remap_path(rows[0]["sespec_path"])
    bp = remap_path(rows[0]["baseline_path"])
    info = {
        "sespec_case_id": case_id,
        "judge_verdict": judge,
        "fc_verdict": "n/a",
        "postcond": "",
        "loop_details": "",
        "n_loops_A": 0,
        "n_loops_B": 0,
        "harness_dir": "",
    }
    new_entries = {}
    if not sp.exists() or not bp.exists():
        info["fc_verdict"] = "missing_files"
        return info, new_entries

    try:
        A = parse_spec(sp)
        B = parse_spec(bp)
    except Exception as e:
        info["fc_verdict"] = "parse_error"
        info["postcond"] = str(e)[:200]
        return info, new_entries

    case_dir = HARNESS_DIR / str(case_id)
    case_dir.mkdir(exist_ok=True)
    info["harness_dir"] = str(case_dir)
    info["n_loops_A"] = len(A["loops"])
    info["n_loops_B"] = len(B["loops"])

    helpers = []
    seen = set()
    for h in A["helpers"] + B["helpers"]:
        k = re.sub(r"\s+", " ", h)
        if k in seen:
            continue
        seen.add(k)
        helpers.append(h)
    hnames = helper_names_from(helpers)
    shared_includes = sorted(set(A["includes"] + B["includes"] + ["#include <limits.h>"]))
    components = []

    has_contract = bool(A["contract"]) or bool(B["contract"])
    if has_contract:
        post_file = case_dir / "postcond.c"
        post_file.write_text(build_postcond_harness(A, B, helpers, hnames))
        res = run_wp(post_file, ["check_A_implies_B", "check_B_implies_A"],
                     timeout=timeout, cache=cache, new_entries=new_entries,
                     force=force)
        ab = res.get("check_A_implies_B", ("error", 0, 0))
        ba = res.get("check_B_implies_A", ("error", 0, 0))
        components.append({"kind": "postcond", "name": "postcond",
                           "AB": ab, "BA": ba})
        info["postcond"] = f"AB={ab[0]}({ab[1]}/{ab[2]}) BA={ba[0]}({ba[1]}/{ba[2]})"

    pair_n = min(len(A["loops"]), len(B["loops"]))
    loop_detail = []
    for li in range(pair_n):
        lp_file = case_dir / f"loop{li+1}.c"
        lp_file.write_text(
            build_loop_harness(A["loops"][li], B["loops"][li],
                               helpers, hnames, shared_includes)
        )
        res = run_wp(lp_file, ["check_A_implies_B", "check_B_implies_A"],
                     timeout=timeout, cache=cache, new_entries=new_entries,
                     force=force)
        ab = res.get("check_A_implies_B", ("error", 0, 0))
        ba = res.get("check_B_implies_A", ("error", 0, 0))
        components.append({"kind": "loop", "name": f"loop{li+1}",
                           "AB": ab, "BA": ba})
        loop_detail.append(
            f"L{li+1}:AB={ab[0]}({ab[1]}/{ab[2]}),BA={ba[0]}({ba[1]}/{ba[2]})"
        )
    info["loop_details"] = "; ".join(loop_detail)

    if not components:
        info["fc_verdict"] = "no_components"
        return info, new_entries
    info["fc_verdict"] = aggregate(components)
    return info, new_entries


# --------- driver ---------

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv",
                    default=str(DATA / "judge/vs_autospec/gpt-5.4-mini.csv"))
    ap.add_argument("--out",
                    default=str(OUT / "results.csv"))
    ap.add_argument("--timeout", type=int, default=180,
                    help="seconds per WP invocation per file")
    ap.add_argument("--workers", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--cases", default="",
                    help="comma-separated case_ids to run (subset)")
    ap.add_argument("--only-build", action="store_true",
                    help="generate harness files but do not run WP")
    ap.add_argument("--force", action="store_true",
                    help="ignore cache; re-run WP")
    args = ap.parse_args()

    raw = list(csv.DictReader(open(args.csv)))
    grouped = defaultdict(list)
    for r in raw:
        grouped[r["sespec_case_id"]].append(r)
    cids = sorted(grouped, key=lambda x: int(x) if x.isdigit() else 1 << 30)
    if args.cases:
        sel = set(args.cases.split(","))
        cids = [c for c in cids if c in sel]
    if args.limit:
        cids = cids[: args.limit]
    print(f"unique pairs: {len(cids)}", flush=True)

    if args.only_build:
        cache = {}
        for cid in cids:
            rows = grouped[cid]
            try:
                sp = remap_path(rows[0]["sespec_path"])
                bp = remap_path(rows[0]["baseline_path"])
                if not sp.exists() or not bp.exists():
                    continue
                A = parse_spec(sp)
                B = parse_spec(bp)
                helpers, seen = [], set()
                for h in A["helpers"] + B["helpers"]:
                    k = re.sub(r"\s+", " ", h)
                    if k in seen:
                        continue
                    seen.add(k)
                    helpers.append(h)
                hnames = helper_names_from(helpers)
                shared = sorted(set(A["includes"] + B["includes"] + ["#include <limits.h>"]))
                d = HARNESS_DIR / str(cid)
                d.mkdir(exist_ok=True)
                if A["contract"] or B["contract"]:
                    (d / "postcond.c").write_text(
                        build_postcond_harness(A, B, helpers, hnames))
                for li in range(min(len(A["loops"]), len(B["loops"]))):
                    (d / f"loop{li+1}.c").write_text(
                        build_loop_harness(A["loops"][li], B["loops"][li],
                                           helpers, hnames, shared))
            except Exception as e:
                print(f"  build {cid}: {e}", flush=True)
        print(f"wrote harnesses into {HARNESS_DIR}")
        return

    cache = _load_cache()
    results = []
    with ProcessPoolExecutor(max_workers=args.workers) as pool:
        futs = {pool.submit(process_case, cid, grouped[cid], args.timeout,
                            args.force, cache): cid
                for cid in cids}
        for i, fut in enumerate(as_completed(futs)):
            r, new_entries = fut.result()
            cache.update(new_entries)
            results.append(r)
            if (i + 1) % 10 == 0 or i + 1 == len(cids):
                print(f"  [{i+1}/{len(cids)}] case={r['sespec_case_id']} "
                      f"judge={r['judge_verdict']} fc={r['fc_verdict']} "
                      f"(loops A/B={r['n_loops_A']}/{r['n_loops_B']})",
                      flush=True)
            if (i + 1) % 25 == 0:
                _save_cache(cache)
    _save_cache(cache)

    fields = ["sespec_case_id", "judge_verdict", "fc_verdict",
              "postcond", "loop_details", "n_loops_A", "n_loops_B",
              "harness_dir"]
    with open(args.out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in sorted(results, key=lambda r: int(r["sespec_case_id"]) if r["sespec_case_id"].isdigit() else 1 << 30):
            w.writerow(r)
    print(f"wrote {args.out}")

    # summary
    bucket = Counter()
    agree = total = 0
    for r in results:
        if r["fc_verdict"] in ("missing_files", "parse_error", "no_components"):
            bucket["skipped:" + r["fc_verdict"]] += 1
            continue
        total += 1
        bucket[(r["judge_verdict"], r["fc_verdict"])] += 1
        if r["judge_verdict"] == r["fc_verdict"]:
            agree += 1
    print(f"agreement: {agree}/{total} = {agree/total*100 if total else 0:.1f}%")
    for k, v in bucket.most_common():
        print(f"  {k}: {v}")


if __name__ == "__main__":
    main()
