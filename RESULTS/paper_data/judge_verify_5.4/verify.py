#!/usr/bin/env python3
"""Verify SESpec(A) vs AutoSpec(B) judge verdicts using Frama-C/WP.

For each dual-valid pair (243 distinct case_ids in
RESULTS/paper_data/judge/vs_autospec/gpt-5.4-mini.csv) we synthesize ONE .c file
containing two checks:

  - check_A_implies_B: wrapper has B's contract; body calls a stub satisfying A.
                       Provable <=> any function satisfying A also satisfies B.
  - check_B_implies_A: symmetric.

Frama-C/WP results are mapped to one of {equal, A_stronger, B_stronger,
incomparable, unknown} and compared to the judge majority verdict.
"""
import argparse
import csv
import os
import re
import subprocess
import sys
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

ROOT = Path("/home/yangfp/SESpec")
DATA = ROOT / "RESULTS/paper_data"
OUT = ROOT / "RESULTS/judge_verify_5.4"
HARNESS_DIR = OUT / "harness"
OUT.mkdir(exist_ok=True)
HARNESS_DIR.mkdir(exist_ok=True)

ANNOT_RE = re.compile(r"/\*@(.*?)\*/", re.DOTALL)
INCLUDE_RE = re.compile(r"^\s*#include\s+[<\"][^>\"]+[>\"]\s*$", re.MULTILINE)

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


def is_contract_block(body):
    """True iff this annotation looks like a function-level contract.

    Loop annotations (`loop invariant`, `loop assigns`, `loop variant`) are NOT
    function contracts: they belong inside the loop body. We strip those
    clauses before scanning so a `loop assigns x;` doesn't get mistaken for a
    function-level `assigns`.
    """
    stripped = re.sub(r"\bloop\s+(invariant|assigns|variant)\b", "_LOOPCLAUSE_", body)
    return bool(
        re.search(
            r"\b(requires|ensures|assigns|allocates|frees|behavior|complete|disjoint|decreases)\b",
            stripped,
        )
    )


def is_logic_block(body):
    return bool(
        re.search(r"\b(logic|predicate|inductive|axiom|axiomatic|lemma|type)\b", body)
    )


def split_annotations(src):
    return [(m.start(), m.end(), m.group(1)) for m in ANNOT_RE.finditer(src)]


def extract_includes(src):
    return sorted(set(m.group(0).strip() for m in INCLUDE_RE.finditer(src)))


def parse_spec_file(path):
    text = Path(path).read_text(errors="replace")
    annots = split_annotations(text)

    funcs = []
    for m in FUNC_RE.finditer(text):
        if any(s <= m.start() < e for s, e, _ in annots):
            continue
        funcs.append(m)
    if not funcs:
        raise ValueError(f"no function declaration found in {path}")

    def preceding_contract(fm):
        cidx, cbody, cstart = None, None, None
        for i, (s, e, body) in enumerate(annots):
            if e <= fm.start() and is_contract_block(body):
                between = text[e : fm.start()]
                if re.match(r"^\s*$", between):
                    cidx, cbody, cstart = i, body, s
        return cidx, cbody, cstart

    candidates_def = [fm for fm in funcs if fm.group(0).rstrip().endswith("{")]
    candidates_decl = [fm for fm in funcs if not fm.group(0).rstrip().endswith("{")]
    contract, contract_idx, contract_start, func_match = None, None, None, None
    for fm in candidates_def + candidates_decl:
        cidx, cbody, cstart = preceding_contract(fm)
        if cbody is not None:
            func_match = fm
            contract = cbody.strip()
            contract_idx = cidx
            contract_start = cstart
            break
    if func_match is None:
        func_match = (candidates_def or candidates_decl or funcs)[0]
        for i, (s, e, body) in enumerate(annots):
            if is_contract_block(body):
                contract = body.strip()
                contract_idx = i
                contract_start = s

    rettype = func_match.group("rettype").strip()
    fname = func_match.group("name")
    params = func_match.group("params").strip()

    # Prologue = everything before the contract block (or, if no contract found, before the function).
    cutoff = contract_start if contract_start is not None else func_match.start()
    prologue_raw = text[:cutoff]

    # Drop function definitions (with body) inside prologue: keep only their forward decl.
    # Brace-balanced removal of bodies that appear after a `)` followed by `{`.
    def strip_bodies(s):
        out = []
        i = 0
        n = len(s)
        while i < n:
            ch = s[i]
            out.append(ch)
            if ch == "{":
                # find matching close
                depth = 1
                j = i + 1
                while j < n and depth > 0:
                    if s[j] == "{":
                        depth += 1
                    elif s[j] == "}":
                        depth -= 1
                    j += 1
                # replace whole body with ";"
                # remove the just-appended "{" too
                out.pop()
                out.append(";")
                i = j
                continue
            i += 1
        return "".join(out)

    prologue_clean = strip_bodies(prologue_raw)

    # Remove the main function declaration line if it appears in the prologue (it would clash with
    # our renamed stub).
    fname_re = re.compile(
        rf"(?:^|\n)\s*(?:const\s+|unsigned\s+|signed\s+)?[\w\s\*]+\b{re.escape(fname)}\s*\([^)]*\)\s*;",
        re.MULTILINE,
    )
    prologue_clean = fname_re.sub("", prologue_clean)

    return {
        "path": str(path),
        "rettype": rettype,
        "fname": fname,
        "params": params,
        "contract": contract,
        "prologue": prologue_clean,
        "includes": extract_includes(text),
    }


def param_names(params):
    if not params or params.strip() == "void":
        return []
    names = []
    for p in params.split(","):
        p = p.strip()
        p_clean = re.sub(r"\[[^\]]*\]\s*$", "", p)
        m = re.search(r"(\w+)\s*$", p_clean)
        if m:
            names.append(m.group(1))
    return names


def dedupe_lines(text):
    seen = set()
    out = []
    for ln in text.split("\n"):
        key = ln.strip()
        if not key:
            out.append(ln)
            continue
        if key in seen:
            continue
        seen.add(key)
        out.append(ln)
    return "\n".join(out)


def build_single_harness(A, B):
    """Build ONE .c file containing two checks (A=>B and B=>A)."""
    includes = sorted(set(A["includes"] + B["includes"] + ['#include <limits.h>']))

    rettype = A["rettype"]
    params = A["params"]
    pnames = param_names(params)
    args_call = ", ".join(pnames) if pnames else ""

    void_ret = rettype.strip() == "void"
    call_a = f"stub_A({args_call});"
    call_b = f"stub_B({args_call});"
    body_a = f"    {call_a}" if void_ret else f"    return {call_a}"
    body_b = f"    {call_b}" if void_ret else f"    return {call_b}"

    # Combine the prologues, drop duplicate includes (already in `includes`), and dedupe lines.
    INCL = re.compile(r"^\s*#\s*include\s+[<\"][^>\"]+[>\"]\s*$", re.MULTILINE)
    pA = INCL.sub("", A["prologue"])
    pB = INCL.sub("", B["prologue"])
    merged_prologue = dedupe_lines(pA + "\n" + pB)

    lines = []
    for inc in includes:
        lines.append(inc)
    lines.append("")
    lines.append(merged_prologue.rstrip())
    lines.append("")
    # stub A
    lines.append(f"/*@{A['contract']}*/")
    lines.append(f"{rettype} stub_A({params});")
    lines.append("")
    # stub B
    lines.append(f"/*@{B['contract']}*/")
    lines.append(f"{rettype} stub_B({params});")
    lines.append("")
    # check A => B  (wrapper has B's contract, body calls A-stub)
    lines.append(f"/*@{B['contract']}*/")
    lines.append(f"{rettype} check_A_implies_B({params}) {{")
    lines.append(body_a)
    lines.append("}")
    lines.append("")
    # check B => A
    lines.append(f"/*@{A['contract']}*/")
    lines.append(f"{rettype} check_B_implies_A({params}) {{")
    lines.append(body_b)
    lines.append("}")
    return "\n".join(lines) + "\n"


def run_wp_per_function(c_file, timeout):
    """Run WP once on both functions; parse per-function status from the two -then blocks."""
    cmd = [
        "frama-c",
        str(c_file),
        "-no-unicode",
        "-wp", "-wp-prover", "alt-ergo,z3", "-wp-timeout", "5", "-wp-par", "1",
        "-wp-fct", "check_A_implies_B",
        "-then",
        "-wp", "-wp-fct", "check_B_implies_A",
    ]
    try:
        r = subprocess.run(
            cmd, capture_output=True, text=True, timeout=timeout, env=os.environ
        )
    except subprocess.TimeoutExpired:
        return ("timeout", 0, 0), ("timeout", 0, 0)
    out = r.stdout + "\n" + r.stderr
    # Find the two "Proved goals: X / Y" lines (order matches -then order).
    matches = re.findall(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", out)
    if len(matches) >= 2:
        (pa, ta), (pb, tb) = matches[0], matches[1]
        pa, ta, pb, tb = int(pa), int(ta), int(pb), int(tb)
        def cat(p, t):
            if t == 0:
                return "empty"
            return "proved" if p == t else "failed"
        return (cat(pa, ta), pa, ta), (cat(pb, tb), pb, tb)
    if "No goal generated" in out or "0 goals scheduled" in out:
        return ("empty", 0, 0), ("empty", 0, 0)
    if r.returncode != 0:
        return ("error", 0, 0), ("error", 0, 0)
    return ("unknown", 0, 0), ("unknown", 0, 0)


def derive_relation(ab, ba):
    p_ab = ab[0] == "proved"
    p_ba = ba[0] == "proved"
    if p_ab and p_ba:
        return "equal"
    if p_ab and not p_ba:
        return "A_stronger"
    if p_ba and not p_ab:
        return "B_stronger"
    return "incomparable"


def majority_verdict(verdicts):
    """Pick majority verdict, ignoring error/parse_error if possible."""
    c = Counter(verdicts)
    # drop errors only if there are non-error verdicts
    real = [v for v in verdicts if v not in ("error", "parse_error")]
    if real:
        c = Counter(real)
    return c.most_common(1)[0][0]


def remap_path(p):
    """Map paper_data_final/* to RESULTS/paper_data/* if needed."""
    if Path(p).exists():
        return Path(p)
    alt = Path(str(p).replace("/paper_data_final/", "/paper_data/"))
    return alt


def process_case(case_id, rows, timeout_per_dir):
    judge = majority_verdict([r["verdict"] for r in rows])
    sespec_path = remap_path(rows[0]["sespec_path"])
    baseline_path = remap_path(rows[0]["baseline_path"])
    info = {
        "sespec_case_id": case_id,
        "judge_verdict": judge,
        "fc_verdict": "n/a",
        "ab_status": "",
        "ba_status": "",
        "harness_file": "",
    }
    if not sespec_path.exists() or not baseline_path.exists():
        info["fc_verdict"] = "missing_files"
        return info
    try:
        A = parse_spec_file(sespec_path)
        B = parse_spec_file(baseline_path)
    except Exception as e:
        info["fc_verdict"] = "parse_error"
        info["ab_status"] = str(e)[:200]
        return info
    # If either side has no contract, treat it as the trivial spec.
    if not A["contract"]:
        A["contract"] = "\n  requires \\true;\n  assigns \\nothing;\n  ensures \\true;\n"
    if not B["contract"]:
        B["contract"] = "\n  requires \\true;\n  assigns \\nothing;\n  ensures \\true;\n"
    harness = build_single_harness(A, B)
    f = HARNESS_DIR / f"case_{case_id}.c"
    f.write_text(harness)
    info["harness_file"] = str(f)
    ab, ba = run_wp_per_function(f, timeout=timeout_per_dir)
    info["ab_status"] = f"{ab[0]} ({ab[1]}/{ab[2]})"
    info["ba_status"] = f"{ba[0]} ({ba[1]}/{ba[2]})"
    info["fc_verdict"] = derive_relation(ab, ba)
    return info


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv", default=str(DATA / "judge/vs_autospec/gpt-5.4-mini.csv"))
    ap.add_argument("--out", default=str(OUT / "results.csv"))
    ap.add_argument("--timeout", type=int, default=60, help="seconds per direction")
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only-build", action="store_true", help="only build harnesses, don't run WP")
    ap.add_argument("--cases", default="", help="comma-separated case_ids to run (subset)")
    args = ap.parse_args()

    rows_raw = list(csv.DictReader(open(args.csv)))
    grouped = defaultdict(list)
    for r in rows_raw:
        grouped[r["sespec_case_id"]].append(r)
    case_ids = sorted(grouped.keys(), key=lambda x: int(x) if x.isdigit() else 1 << 30)
    if args.cases:
        sel = set(args.cases.split(","))
        case_ids = [c for c in case_ids if c in sel]
    if args.limit:
        case_ids = case_ids[: args.limit]
    print(f"unique dual-valid cases: {len(case_ids)}", flush=True)

    if args.only_build:
        # only synthesize .c files
        for cid in case_ids:
            rows = grouped[cid]
            sespec_path = remap_path(rows[0]["sespec_path"])
            baseline_path = remap_path(rows[0]["baseline_path"])
            if not sespec_path.exists() or not baseline_path.exists():
                continue
            try:
                A = parse_spec_file(sespec_path)
                B = parse_spec_file(baseline_path)
            except Exception:
                continue
            if not A["contract"]:
                A["contract"] = "\n  requires \\true;\n  assigns \\nothing;\n  ensures \\true;\n"
            if not B["contract"]:
                B["contract"] = "\n  requires \\true;\n  assigns \\nothing;\n  ensures \\true;\n"
            (HARNESS_DIR / f"case_{cid}.c").write_text(build_single_harness(A, B))
        print(f"wrote .c files into {HARNESS_DIR}")
        return

    results = []
    with ProcessPoolExecutor(max_workers=args.workers) as pool:
        futs = {
            pool.submit(process_case, cid, grouped[cid], args.timeout): cid
            for cid in case_ids
        }
        for i, fut in enumerate(as_completed(futs)):
            r = fut.result()
            results.append(r)
            if (i + 1) % 5 == 0 or i + 1 == len(case_ids):
                print(
                    f"  [{i+1}/{len(case_ids)}] case={r['sespec_case_id']} judge={r['judge_verdict']} fc={r['fc_verdict']}",
                    flush=True,
                )

    with open(args.out, "w", newline="") as fh:
        w = csv.DictWriter(
            fh,
            fieldnames=[
                "sespec_case_id",
                "judge_verdict",
                "fc_verdict",
                "ab_status",
                "ba_status",
                "harness_file",
            ],
        )
        w.writeheader()
        for row in sorted(
            results,
            key=lambda r: int(r["sespec_case_id"]) if r["sespec_case_id"].isdigit() else 1 << 30,
        ):
            w.writerow(row)
    print(f"wrote {args.out}")

    # quick summary
    agree = 0
    total = 0
    bucket = Counter()
    for r in results:
        if r["fc_verdict"] in ("missing_files", "parse_error", "no_contract"):
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
