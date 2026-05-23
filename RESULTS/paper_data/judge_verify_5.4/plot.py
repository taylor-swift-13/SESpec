#!/usr/bin/env python3
"""Plot LLM judge vs Frama-C/WP refinement on the dual-valid pairs,
reading verdicts from results.csv (produced by verify_all.py)."""
import csv
from collections import Counter
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

CSV = Path("/home/yangfp/SESpec/RESULTS/paper_data/judge_verify_5.4/results.csv")
OUT_PDF = Path("/home/yangfp/SESpec/paper/images/fc_vs_judge_strength.pdf")
OUT_PNG = OUT_PDF.with_suffix(".png")

LABELS = ["A_stronger", "B_stronger", "equal", "incomparable"]
DISPLAY = ["SESpec stronger", "AutoSpec stronger", "Equal", "Incomparable"]
COLORS = ["#2E7D32", "#C62828", "#6A1B9A", "#9E9E9E"]


def collapse(v):
    if v.endswith("?"):
        v = v[:-1]
    if v == "inconclusive":
        return "incomparable"
    return v


def main():
    rows = list(csv.DictReader(open(CSV)))
    skip = {"missing_files", "parse_error", "no_components"}
    rows = [r for r in rows if r["fc_verdict"] not in skip]

    judge_c = Counter(r["judge_verdict"] for r in rows)
    fc_c = Counter(collapse(r["fc_verdict"]) for r in rows)
    judge = [judge_c.get(l, 0) for l in LABELS]
    fc = [fc_c.get(l, 0) for l in LABELS]
    total = sum(judge)
    if sum(fc) != total:
        # accommodate verdicts outside LABELS (e.g., "inconclusive" not collapsed)
        leftover = sum(fc_c.values()) - sum(fc)
        if leftover:
            fc[-1] += leftover  # lump into incomparable bucket visually
    print("judge:", dict(zip(LABELS, judge)))
    print("fc   :", dict(zip(LABELS, fc)))
    print("total:", total)

    fig, ax = plt.subplots(figsize=(7.0, 1.9))
    methods = ["LLM judge\n(gpt-5.4)", "Frama-C/WP\nrefinement"]
    data = [judge, fc]
    left = [0, 0]
    for ci, cat in enumerate(DISPLAY):
        vals = [data[0][ci], data[1][ci]]
        bars = ax.barh(methods, vals, left=left, color=COLORS[ci],
                       edgecolor="white", linewidth=0.6, label=cat)
        for bi, b in enumerate(bars):
            v = vals[bi]
            if v == 0:
                continue
            pct = 100 * v / total
            if pct >= 4:
                ax.text(left[bi] + v / 2, bi, f"{v}\n{pct:.1f}%",
                        ha="center", va="center", fontsize=8,
                        color="white", fontweight="bold")
            else:
                ax.text(left[bi] + v / 2, bi, f"{v}", ha="center",
                        va="center", fontsize=7, color="white")
        left = [left[0] + vals[0], left[1] + vals[1]]

    ax.set_xlim(0, total)
    ax.set_xlabel(f"pairs (out of {total} dual-valid, gpt-5.4-mini)")
    ax.invert_yaxis()
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.32),
              ncol=4, frameon=False, fontsize=8)
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.tick_params(axis="y", length=0)
    plt.tight_layout()
    OUT_PDF.parent.mkdir(parents=True, exist_ok=True)
    plt.savefig(OUT_PDF, bbox_inches="tight")
    plt.savefig(OUT_PNG, dpi=200, bbox_inches="tight")
    print(f"wrote {OUT_PDF} and {OUT_PNG}")


if __name__ == "__main__":
    main()
