#!/usr/bin/env python3
"""Loop-invariant strength comparison between SESpec(A) and AutoSpec(B).

For each dual-valid pair we extract `loop invariant <expr>;` clauses from both
files, grouped *per annotation block* (one block = one loop in ACSL). A's loops
are matched to B's loops by positional index, then for each matched pair we ask
Frama-C/WP to discharge one assert per opposing invariant:

  check_AB_L<i>:  requires Phi_A_Li; body asserts each b in B_Li
  check_BA_L<i>:  requires Phi_B_Li; body asserts each a in A_Li

A's spec is "at least as strong" as B iff every B-invariant in every loop is
provable from Phi_A. Symmetric for the other direction.

Critical fix vs. the prior implementation:
- The previous regex `loop\\s+invariant\\s+(.+?);` was non-greedy and matched the
  *quantifier-head semicolon* inside `\\forall T x; P(x)`, silently truncating
  every quantified invariant. We now hand-parse, tracking quantifier `;`s.
- Per-loop matching (instead of one giant cross-file conjunction).
- Per-invariant asserts (one failed clause no longer poisons the whole side).
- Variable types are inferred per identifier from how it is *used* in the
  invariant, not "if any identifier in this invariant is pointer-y, all are".
- Verdict distinguishes inconclusive (timeout/error) from strictly incomparable.
"""
import argparse
import csv
import os
import re
import subprocess
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

ROOT = Path("/home/yangfp/SESpec")
DATA = ROOT / "RESULTS/paper_data"
OUT = DATA / "judge_verify_5.4"
HARNESS_DIR = OUT / "harness_loop"
HARNESS_DIR.mkdir(exist_ok=True)

ANNOT_RE = re.compile(r"/\*@(.*?)\*/", re.DOTALL)
INCLUDE_RE = re.compile(r"^\s*#include\s+[<\"][^>\"]+[>\"]\s*$", re.MULTILINE)
IDENT_RE = re.compile(r"\\?[A-Za-z_][A-Za-z0-9_]*")
QUANT_HEAD_RE = re.compile(r"\\(forall|exists|let)\b")

ACSL_KEYWORDS = {
    "true", "false", "integer", "real", "boolean", "result", "old",
    "at", "Pre", "Post", "LoopEntry", "LoopCurrent", "Here", "nothing",
    "valid", "valid_read", "separated", "exists", "forall", "let", "in",
    "result", "max", "min", "abs", "sum", "block_length", "offset",
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


def extract_includes(src):
    return sorted(set(m.group(0).strip() for m in INCLUDE_RE.finditer(src)))


def _split_invariants_in_body(body):
    """Split an annotation body into `loop invariant <expr>` clauses.

    Walks character-by-character so that `;` inside `\\forall T x; P(x)` (and
    `\\exists` / `\\let`) is treated as a quantifier separator, not a clause
    terminator. `(` / `[` depth is tracked to ignore any `;` inside parens.
    """
    out = []
    n = len(body)
    i = 0
    while i < n:
        m = re.search(r"loop\s+invariant\s+", body[i:])
        if not m:
            break
        start = i + m.end()
        j = start
        depth = 0
        pending = 0
        while j < n:
            if depth == 0:
                qm = QUANT_HEAD_RE.match(body, j)
                if qm:
                    pending += 1
                    j = qm.end()
                    continue
            c = body[j]
            if c == '(' or c == '[':
                depth += 1
            elif c == ')' or c == ']':
                depth -= 1
                if depth < 0:
                    break
            elif c == ';' and depth == 0:
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


def parse_loop_blocks(text):
    """Return [(annotation_offset, [invariants])] for blocks that contain at
    least one `loop invariant`. Each entry corresponds to one loop in ACSL.
    """
    blocks = []
    for m in ANNOT_RE.finditer(text):
        body = m.group(1)
        if "loop invariant" not in body:
            continue
        invs = _split_invariants_in_body(body)
        if invs:
            blocks.append((m.start(), invs))
    return blocks


def extract_logic_blocks(text):
    blocks = []
    for m in ANNOT_RE.finditer(text):
        body = m.group(1)
        if re.search(r"\b(logic|predicate|inductive|axiomatic|lemma)\b", body):
            blocks.append(body.strip())
    return blocks


def identifiers_in(expr):
    out = set()
    for m in IDENT_RE.finditer(expr):
        name = m.group(0)
        if name.startswith("\\"):
            continue
        if name in ACSL_KEYWORDS or name in C_KEYWORDS:
            continue
        if name.isdigit():
            continue
        out.add(name)
    return out


def classify_vars(invariants):
    """Map identifier -> True (pointer) / False (int), based on usage."""
    kinds = {}
    for inv in invariants:
        for name in identifiers_in(inv):
            esc = re.escape(name)
            is_ptr = (
                re.search(rf"\b{esc}\s*\[", inv) is not None
                or re.search(rf"\b{esc}\s*->", inv) is not None
                or re.search(rf"(?<![\w\)\]])\*\s*{esc}\b", inv) is not None
            )
            kinds[name] = kinds.get(name, False) or is_ptr
    return kinds


def remap_path(p):
    pp = Path(p)
    if pp.exists():
        return pp
    return Path(str(p).replace("/paper_data_final/", "/paper_data/"))


def build_loop_harness(A_path, B_path):
    A_text = A_path.read_text(errors="replace")
    B_text = B_path.read_text(errors="replace")
    A_blocks = parse_loop_blocks(A_text)
    B_blocks = parse_loop_blocks(B_text)
    A_inv_all = [iv for _, ivs in A_blocks for iv in ivs]
    B_inv_all = [iv for _, ivs in B_blocks for iv in ivs]

    if not A_blocks or not B_blocks:
        return None, A_inv_all, B_inv_all, [], "missing_loop_block"

    pair_count = min(len(A_blocks), len(B_blocks))
    matched = [(A_blocks[i][1], B_blocks[i][1]) for i in range(pair_count)]
    build_status = "ok" if len(A_blocks) == len(B_blocks) else \
        f"loop_count_mismatch (A={len(A_blocks)}, B={len(B_blocks)})"

    includes = sorted(set(
        extract_includes(A_text) + extract_includes(B_text)
        + ["#include <limits.h>"]
    ))

    helpers = []
    seen = set()
    for b in extract_logic_blocks(A_text) + extract_logic_blocks(B_text):
        key = re.sub(r"\s+", " ", b)
        if key in seen:
            continue
        seen.add(key)
        helpers.append(b)

    helper_names = set()
    for b in helpers:
        for m in re.finditer(r"\b(?:logic\s+\w+|predicate)\s+(\w+)\s*\(", b):
            helper_names.add(m.group(1))

    lines = list(includes) + [""]
    for h in helpers:
        lines.append(f"/*@{h}*/")
    if helpers:
        lines.append("")

    fn_specs = []  # [(direction, loop_idx, inv_idx, fn_name)]
    for li, (A_inv, B_inv) in enumerate(matched):
        all_inv = A_inv + B_inv
        var_kinds = classify_vars(all_inv)
        for hn in helper_names:
            var_kinds.pop(hn, None)
        if not var_kinds:
            continue
        params = ", ".join(
            (f"int *{v}" if is_ptr else f"int {v}")
            for v, is_ptr in sorted(var_kinds.items())
        )
        A_conj = " && ".join(f"({i})" for i in A_inv) if A_inv else "\\true"
        B_conj = " && ".join(f"({i})" for i in B_inv) if B_inv else "\\true"

        for bi, b in enumerate(B_inv):
            name = f"check_AB_L{li}_{bi}"
            lines.append(f"/*@ requires {A_conj};")
            lines.append("    assigns \\nothing;")
            lines.append("*/")
            lines.append(f"void {name}({params}) {{")
            lines.append(f"    /*@ assert ({b}); */")
            lines.append("}")
            lines.append("")
            fn_specs.append(("AB", li, bi, name))

        for ai, a in enumerate(A_inv):
            name = f"check_BA_L{li}_{ai}"
            lines.append(f"/*@ requires {B_conj};")
            lines.append("    assigns \\nothing;")
            lines.append("*/")
            lines.append(f"void {name}({params}) {{")
            lines.append(f"    /*@ assert ({a}); */")
            lines.append("}")
            lines.append("")
            fn_specs.append(("BA", li, ai, name))

    if not fn_specs:
        return None, A_inv_all, B_inv_all, [], "no_vars"

    return "\n".join(lines) + "\n", A_inv_all, B_inv_all, fn_specs, build_status


def run_wp(c_file, fn_specs, timeout):
    """Run WP, chaining one `-wp -wp-fct <name>` per harness function via
    `-then`, and parse one "Proved goals: X / Y" line per function.
    """
    fn_names = [name for _, _, _, name in fn_specs]
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
        return {nm: ("timeout", 0, 0) for nm in fn_names}, "timeout"

    out = r.stdout + "\n" + r.stderr
    matches = re.findall(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", out)
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
        return result, "ok"

    # WP didn't emit a line per function — likely a parse error somewhere.
    status = "wp_parse_mismatch" if r.returncode != 0 else "wp_unparsed"
    for nm in fn_names:
        result[nm] = ("error", 0, 0)
    return result, status


def aggregate_verdict(fn_specs, results):
    ab_specs = [s for s in fn_specs if s[0] == "AB"]
    ba_specs = [s for s in fn_specs if s[0] == "BA"]

    def tally(specs):
        proved = sum(1 for _, _, _, nm in specs if results.get(nm, ("",))[0] == "proved")
        failed = sum(1 for _, _, _, nm in specs if results.get(nm, ("",))[0] == "failed")
        bad = sum(1 for _, _, _, nm in specs
                  if results.get(nm, ("",))[0] in ("timeout", "error", "empty"))
        return proved, failed, bad, len(specs)

    ab_p, ab_f, ab_b, ab_t = tally(ab_specs)
    ba_p, ba_f, ba_b, ba_t = tally(ba_specs)

    a_covers_b = ab_t > 0 and ab_p == ab_t
    b_covers_a = ba_t > 0 and ba_p == ba_t

    # If no "failed" anywhere but inconclusives exist, we can't tell direction.
    if (ab_b > 0 and ab_f == 0 and not a_covers_b) or \
       (ba_b > 0 and ba_f == 0 and not b_covers_a):
        if not a_covers_b and not b_covers_a:
            verdict = "inconclusive"
        elif a_covers_b:
            verdict = "A_stronger?"  # one side known, other side inconclusive
        else:
            verdict = "B_stronger?"
    elif a_covers_b and b_covers_a:
        verdict = "equal"
    elif a_covers_b:
        verdict = "A_stronger"
    elif b_covers_a:
        verdict = "B_stronger"
    else:
        verdict = "incomparable"

    return {
        "verdict": verdict,
        "ab_proved": ab_p, "ab_failed": ab_f, "ab_bad": ab_b, "ab_total": ab_t,
        "ba_proved": ba_p, "ba_failed": ba_f, "ba_bad": ba_b, "ba_total": ba_t,
    }


def majority_verdict(verdicts):
    real = [v for v in verdicts if v not in ("error", "parse_error")]
    c = Counter(real if real else verdicts)
    return c.most_common(1)[0][0]


def process(case_id, rows, timeout):
    judge = majority_verdict([r["verdict"] for r in rows])
    sp = remap_path(rows[0]["sespec_path"])
    bp = remap_path(rows[0]["baseline_path"])
    info = {
        "sespec_case_id": case_id,
        "judge_verdict": judge,
        "fc_verdict": "n/a",
        "ab_status": "",
        "ba_status": "",
        "n_A_inv": 0,
        "n_B_inv": 0,
        "build_status": "",
        "harness": "",
    }
    if not sp.exists() or not bp.exists():
        info["fc_verdict"] = "missing_files"
        return info
    try:
        harness, A_inv, B_inv, fn_specs, build_status = build_loop_harness(sp, bp)
    except Exception as e:
        info["fc_verdict"] = "build_error"
        info["ab_status"] = str(e)[:200]
        return info
    info["n_A_inv"] = len(A_inv)
    info["n_B_inv"] = len(B_inv)
    info["build_status"] = build_status
    if harness is None:
        info["fc_verdict"] = f"no_loop_inv ({build_status})"
        info["ab_status"] = f"A_inv={len(A_inv)} B_inv={len(B_inv)}"
        return info
    f = HARNESS_DIR / f"case_{case_id}.c"
    f.write_text(harness)
    info["harness"] = str(f)
    results, _ = run_wp(f, fn_specs, timeout)
    agg = aggregate_verdict(fn_specs, results)
    info["ab_status"] = (f"{agg['ab_proved']}/{agg['ab_total']} proved, "
                        f"{agg['ab_failed']} failed, {agg['ab_bad']} inconclusive")
    info["ba_status"] = (f"{agg['ba_proved']}/{agg['ba_total']} proved, "
                        f"{agg['ba_failed']} failed, {agg['ba_bad']} inconclusive")
    info["fc_verdict"] = agg["verdict"]
    return info


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv", default=str(DATA / "judge/vs_autospec/gpt-5.4-mini.csv"))
    ap.add_argument("--out", default=str(OUT / "results_loop.csv"))
    ap.add_argument("--timeout", type=int, default=180)
    ap.add_argument("--workers", type=int, default=12)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only-build", action="store_true")
    args = ap.parse_args()

    raw = list(csv.DictReader(open(args.csv)))
    grouped = defaultdict(list)
    for r in raw:
        grouped[r["sespec_case_id"]].append(r)
    cids = sorted(grouped, key=lambda x: int(x) if x.isdigit() else 1 << 30)
    if args.limit:
        cids = cids[: args.limit]
    print(f"unique pairs: {len(cids)}", flush=True)

    if args.only_build:
        for cid in cids:
            try:
                rows = grouped[cid]
                sp = remap_path(rows[0]["sespec_path"])
                bp = remap_path(rows[0]["baseline_path"])
                if not sp.exists() or not bp.exists():
                    continue
                h, _, _, _, _ = build_loop_harness(sp, bp)
                if h is not None:
                    (HARNESS_DIR / f"case_{cid}.c").write_text(h)
            except Exception:
                continue
        print(f"wrote .c files into {HARNESS_DIR}")
        return

    results = []
    with ProcessPoolExecutor(max_workers=args.workers) as pool:
        futs = {pool.submit(process, cid, grouped[cid], args.timeout): cid for cid in cids}
        for i, fut in enumerate(as_completed(futs)):
            r = fut.result()
            results.append(r)
            if (i + 1) % 10 == 0 or i + 1 == len(cids):
                print(f"  [{i+1}/{len(cids)}] case={r['sespec_case_id']} "
                      f"judge={r['judge_verdict']} fc={r['fc_verdict']} "
                      f"(invA={r['n_A_inv']}, invB={r['n_B_inv']})", flush=True)

    fields = ["sespec_case_id", "judge_verdict", "fc_verdict",
              "ab_status", "ba_status", "n_A_inv", "n_B_inv",
              "build_status", "harness"]
    with open(args.out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in sorted(results, key=lambda r: int(r["sespec_case_id"]) if r["sespec_case_id"].isdigit() else 1 << 30):
            w.writerow(r)
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
