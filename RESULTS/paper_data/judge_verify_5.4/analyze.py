#!/usr/bin/env python3
"""Analyze verification results from verify_all.py.

Reads results.csv (per-case verdicts after aggregating postcond + every
loop) and prints:
  - Confusion matrix between judge verdict and Frama-C verdict.
  - Strict agreement (judge == fc, ignoring `?`/inconclusive).
  - Loose agreement (treats `A_stronger?` as `A_stronger`, etc).
  - Per-bucket breakdown for any non-matrix verdicts.
"""
import csv
import sys
from collections import Counter
from pathlib import Path

DEFAULT_CSV = Path("/home/yangfp/SESpec/RESULTS/paper_data/judge_verify_5.4/results.csv")


def collapse(v):
    """Collapse `A_stronger?` -> `A_stronger` for loose agreement."""
    if v.endswith("?"):
        return v[:-1]
    return v


def main():
    src = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_CSV
    rows = list(csv.DictReader(open(src)))
    print(f"total rows: {len(rows)}")

    skip_labels = {"missing_files", "parse_error", "no_components"}
    skipped = [r for r in rows if r["fc_verdict"] in skip_labels]
    if skipped:
        print(f"skipped (parse/missing/no_components): {len(skipped)}")
        skip_counts = Counter(r["fc_verdict"] for r in skipped)
        for k, v in skip_counts.most_common():
            print(f"  {k}: {v}")

    rows = [r for r in rows if r["fc_verdict"] not in skip_labels]
    labels = ["A_stronger", "B_stronger", "equal", "incomparable"]
    fc_extra = ["A_stronger?", "B_stronger?", "inconclusive"]

    confusion = {j: Counter() for j in labels}
    other = Counter()
    for r in rows:
        j, f = r["judge_verdict"], r["fc_verdict"]
        if j in confusion:
            confusion[j][f] += 1
        else:
            other[(j, f)] += 1

    all_cols = labels + fc_extra
    print("\nConfusion matrix (rows = judge, cols = Frama-C):")
    width = 14
    header = " " * 16 + "".join(f"{l:>{width}}" for l in all_cols) + "  | total"
    print(header)
    print("-" * len(header))
    col_totals = Counter()
    grand = 0
    strict = loose = 0
    for j in labels:
        row_total = sum(confusion[j].values())
        line = f"{j:>14}: " + "".join(f"{confusion[j][f]:>{width}}" for f in all_cols) + f"  | {row_total}"
        print(line)
        for f in all_cols:
            col_totals[f] += confusion[j][f]
        grand += row_total
        strict += confusion[j][j]
        loose += sum(v for f, v in confusion[j].items() if collapse(f) == j)
    line = f"{'col total':>14}: " + "".join(f"{col_totals[f]:>{width}}" for f in all_cols) + f"  | {grand}"
    print(line)

    print(f"\nStrict agreement (judge == fc):           {strict}/{grand} = "
          f"{strict/grand*100 if grand else 0:.1f}%")
    print(f"Loose agreement (collapse `?` to match):  {loose}/{grand} = "
          f"{loose/grand*100 if grand else 0:.1f}%")

    if other:
        print("\nUncategorized judge verdicts:")
        for k, v in other.most_common():
            print(f"  {k}: {v}")


if __name__ == "__main__":
    main()
