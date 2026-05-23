#!/usr/bin/env python3
"""Aggregate per-case results across (5 methods × 4 models) and refresh paper artifacts.

Data source (unified layout under RESULTS/paper_data/):
  - RESULTS/paper_data/{Method}/{model}/{case}/summary.json  (all 4 models)

Outputs:
  - RESULTS/paper_data/aggregate.csv          (one row per method×model, scope=full_400)
  - paper/FSEchapters/large_experiment_table.tex
"""
from __future__ import annotations

import csv
import json
import re
from pathlib import Path
from typing import Optional

REPO_ROOT = Path(__file__).resolve().parents[2]
PD = REPO_ROOT / "RESULTS" / "paper_data"
PAPER_TEX = REPO_ROOT / "paper" / "FSEchapters" / "large_experiment_table.tex"
AGG_OUT = PD / "aggregate.csv"

# Canonical method id → (display name, paper_data subdir name).
# After the reorganization, each method has a unified <Method>/<model>/<case>/ tree.
METHODS = [
    ("AutoSpec",         "AutoSpec (C/ACSL)",                          "AutoSpec"),
    ("LLM-C",            r"\toolname\ w/o refine w/o symbolic execution (Pure LLM)", "LLM-C"),
    ("SESpec_no_refine", r"\toolname\ w/o refine",                     "SESpec_no_refine"),
    ("SESpec",           r"\textbf{\toolname}",                        "SESpec"),
    ("SpecGen",          "SpecGen (Java/JML)",                         "SpecGen"),
]
MODELS = ["gpt-4o", "gpt-5-mini", "gpt-5.4-mini", "gpt-5"]
# Method-level cost averages (Time/Tokens/Calls) in the paper's main table are
# weighted across these 3 models only; gpt-5 contributes to the per-(method,model)
# Valid rows but is excluded from method-level cost weighting. Keeping this
# mirrors the published numbers (e.g. AutoSpec Time = 498.4 = 3-model weighted).
COST_AVG_MODELS = ["gpt-4o", "gpt-5-mini", "gpt-5.4-mini"]

# Methods that genuinely make one API call per case (no iteration)
ONE_SHOT_METHODS = {"LLM-C", "SpecGen"}


def truthy(v) -> bool:
    if isinstance(v, bool):
        return v
    if isinstance(v, str):
        return v.strip().lower() in {"true", "1", "yes", "pass"}
    return False


def num(v) -> float:
    if v is None or v == "":
        return 0.0
    try:
        return float(v)
    except (TypeError, ValueError):
        return 0.0


def case_root(method_id: str, model: str) -> Path:
    """Return the parent dir containing per-case subdirs for this (method, model)."""
    _, _, dirname = next(m for m in METHODS if m[0] == method_id)
    return PD / dirname / model


def normalize_summary(d: dict) -> dict:
    """Map possible schemas (legacy autospec/sespec_400 vs modern sespec_400_gpt5) to one shape."""
    if "valid_pass" in d:
        passed = bool(d.get("valid_pass"))
    elif "result" in d:
        passed = str(d.get("result", "")).strip().lower() == "pass"
    elif "passed" in d:
        passed = bool(d.get("passed"))
    else:
        passed = False

    sec = d.get("total_seconds")
    if sec is None:
        sec = d.get("seconds")
    if sec is None:
        sec = d.get("total_execution_time") or 0
    # AutoSpec gpt-5 modern summary: 'total_seconds' == 'total_solve_seconds'
    # (OpenJML verify time only); add 'llms_query_seconds' so total reflects
    # wall time comparable to 3-model legacy 'seconds' which includes both.
    if d.get("project") == "autospec":
        llm_s = d.get("llms_query_seconds")
        solve_s = d.get("total_solve_seconds")
        if llm_s is not None and solve_s is not None and abs((sec or 0) - solve_s) < 0.01:
            sec = (solve_s or 0) + (llm_s or 0)

    tok = d.get("total_tokens")
    if tok is None:
        tok = d.get("tokens") or 0
    cc = d.get("call_count")
    if cc is None:
        cc = d.get("api_calls")
    return {
        "passed": str(bool(passed)),
        "total_seconds": sec or 0,
        "total_tokens": tok or 0,
        "call_count": cc,  # may be None
    }


def load_summaries(root: Path) -> list[dict]:
    """Load every case_dir/summary.json under root."""
    rows = []
    if not root.is_dir():
        return rows
    for case_dir in sorted(root.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else 1 << 30):
        sp = case_dir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        norm = normalize_summary(d)
        norm["case_id"] = case_dir.name
        rows.append(norm)
    return rows


def _stats(rows: list[dict], method_id: str) -> dict:
    total = len(rows)
    valid_rows = [r for r in rows if truthy(r.get("passed"))]
    valid = len(valid_rows)
    sum_sec = sum(num(r.get("total_seconds")) for r in valid_rows)
    sum_tok = sum(num(r.get("total_tokens")) for r in valid_rows)

    # API calls: only sespec* track this. For one-shot methods, default to 1.
    cc_vals = [num(r["call_count"]) for r in valid_rows if r.get("call_count") not in (None, "")]
    if cc_vals:
        avg_calls = round(sum(cc_vals) / valid, 2) if valid else 0.0
    elif method_id in ONE_SHOT_METHODS:
        avg_calls = 1.0
    else:
        avg_calls = None  # iterative without tracking → "—" in table

    return {
        "runs": total,
        "valid": valid,
        "valid_pct": round(valid / total * 100, 1) if total else 0.0,
        "avg_seconds_pass": round(sum_sec / valid, 2) if valid else 0.0,
        "avg_tokens_pass": round(sum_tok / valid) if valid else 0,
        "avg_api_calls_pass": avg_calls,
    }


def compute_all() -> dict:
    """method_id → model → {scope: stats}. Re-compute all 4 models from per-case
    summary.json. normalize_summary handles both legacy and modern schemas so
    every model is graded by the same criterion (auditable from source)."""
    result = {}
    for method_id, _, _ in METHODS:
        per_model = {}
        for model in MODELS:
            root = case_root(method_id, model)
            rows = load_summaries(root)
            if not rows:
                continue
            per_model[model] = {"full_400": _stats(rows, method_id)}
        if per_model:
            result[method_id] = per_model
    return result


def write_aggregate_csv(data: dict) -> None:
    fieldnames = [
        "scope", "method", "model", "runs", "valid", "valid_pct",
        "avg_seconds_pass", "avg_tokens_pass", "avg_api_calls_pass",
    ]
    rows = []
    for method_id, per_model in data.items():
        for model, scopes in per_model.items():
            for scope, s in scopes.items():
                if s["runs"] == 0:
                    continue
                rows.append({
                    "scope": scope, "method": method_id, "model": model,
                    "runs": s["runs"], "valid": s["valid"], "valid_pct": s["valid_pct"],
                    "avg_seconds_pass": s["avg_seconds_pass"],
                    "avg_tokens_pass": s["avg_tokens_pass"],
                    "avg_api_calls_pass": "" if s["avg_api_calls_pass"] is None else s["avg_api_calls_pass"],
                })
    AGG_OUT.parent.mkdir(parents=True, exist_ok=True)
    with AGG_OUT.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(sorted(rows, key=lambda r: (r["scope"], r["method"], MODELS.index(r["model"]))))
    print(f"Wrote {AGG_OUT}")


def fmt_int(n) -> str:
    if n is None or n == "":
        return "---"
    return f"{int(n):,}".replace(",", "{,}")


def fmt_float(f) -> str:
    if f is None or f == "":
        return "---"
    return f"{float(f):.1f}"


def write_main_table(data: dict) -> None:
    """Replace large_experiment_table.tex with 5 methods × 4 models full_400 view.

    SpecGen on gpt-5 reports arc-352 (no Java for the 48 non-arc cases); annotated in caption.
    """
    lines = []
    lines.append("% Auto-generated by src/scripts/aggregate_all_methods_all_models.py — do not hand-edit.")
    lines.append(r"\begin{table*}[t]")
    lines.append(r"\centering")
    lines.append(r"\caption{Table VII. Large-scale results on \textsc{sespec}-400. \emph{Valid} is reported per method/model pair across all four models. \emph{Time~(s)}, \emph{Tokens}, and \emph{API Calls} are method-level means weighted by valid-run count across gpt-4o, gpt-5-mini, and gpt-5.4-mini; gpt-5 contributes to the per-row \emph{Valid} column only. AutoSpec and SpecGen are reproduced baselines. Each \emph{Pass@1} cell is one full \toolname\ generation-and-refinement run; the inner refinement loop is bounded separately by Algorithm~\ref{alg:inv-repair}.}")
    lines.append(r"\label{tab:large_experiment_summary}")
    lines.append(r"\scriptsize")
    lines.append(r"\setlength{\tabcolsep}{4pt}")
    lines.append(r"\begin{adjustbox}{width=\textwidth}")
    lines.append(r"\begin{tabular}{llrrrrr}")
    lines.append(r"\toprule")
    lines.append(r"Method & Model & Valid & Valid (\%) & Time (s) & Tokens & API Calls \\")
    lines.append(r"\midrule")

    method_order = ["AutoSpec", "SpecGen", "LLM-C", "SESpec_no_refine", "SESpec"]
    for method_id in method_order:
        per_model = data.get(method_id, {})
        if not per_model:
            continue
        display = next(d for m, d, _ in METHODS if m == method_id)
        rows_for_table = []
        for model in MODELS:
            sc = per_model.get(model)
            if not sc:
                continue
            s = sc.get("full_400")
            if not s or s["runs"] == 0:
                continue
            rows_for_table.append((model, s))
        if not rows_for_table:
            continue
        # Method-level cost averages weighted by per-model valid count, restricted
        # to COST_AVG_MODELS (mirrors paper: gpt-5 contributes to per-row Valid
        # only, not to the cost column aggregates).
        cost_rows = [(m, s) for (m, s) in rows_for_table if m in COST_AVG_MODELS]
        cost_valid = sum(s["valid"] for _, s in cost_rows)
        tot_sec = sum(s["avg_seconds_pass"] * s["valid"] for _, s in cost_rows)
        tot_tok = sum(s["avg_tokens_pass"] * s["valid"] for _, s in cost_rows)
        cc_pairs = [(s["avg_api_calls_pass"], s["valid"]) for _, s in cost_rows
                    if s.get("avg_api_calls_pass") is not None]
        if cc_pairs and cost_valid:
            tot_calls = sum(c * v for c, v in cc_pairs) / sum(v for _, v in cc_pairs)
        else:
            tot_calls = None
        avg_sec = tot_sec / cost_valid if cost_valid else 0.0
        avg_tok = round(tot_tok / cost_valid) if cost_valid else 0

        n = len(rows_for_table)
        for i, (model, s) in enumerate(rows_for_table):
            method_cell = (f"\\multirow{{{n}}}{{*}}{{{display}}}" if i == 0 else "")
            if i == 0:
                sec_cell = f"\\multirow{{{n}}}{{*}}{{{fmt_float(avg_sec)}}}"
                tok_cell = f"\\multirow{{{n}}}{{*}}{{{fmt_int(avg_tok)}}}"
                calls_cell = f"\\multirow{{{n}}}{{*}}{{{fmt_float(tot_calls)}}}"
            else:
                sec_cell = tok_cell = calls_cell = ""
            line = (
                f"{method_cell} & {model} & {s['valid']} & "
                f"{fmt_float(s['valid_pct'])} & {sec_cell} & {tok_cell} & {calls_cell} \\\\"
            )
            lines.append(line)
        lines.append(r"\midrule")
    # Drop trailing \midrule, replace with \bottomrule
    if lines[-1] == r"\midrule":
        lines[-1] = r"\bottomrule"
    else:
        lines.append(r"\bottomrule")
    lines.append(r"\end{tabular}")
    lines.append(r"\end{adjustbox}")
    lines.append(r"\end{table*}")

    PAPER_TEX.parent.mkdir(parents=True, exist_ok=True)
    new_main = "\n".join(lines) + "\n"
    # Preserve any subsequent appended block (e.g. the strength_summary table
    # written by append_strength_summary_table.py). Detect it by the marker
    # `% Auto-generated by` line that begins each appended block.
    appended = ""
    if PAPER_TEX.exists():
        old = PAPER_TEX.read_text(encoding="utf-8")
        # Find the SECOND `% Auto-generated by` marker (the first belongs to
        # the main table we just rewrote).
        markers = [m.start() for m in re.finditer(r"^% Auto-generated by ", old, re.MULTILINE)]
        if len(markers) >= 2:
            appended = "\n" + old[markers[1]:]
    PAPER_TEX.write_text(new_main + appended, encoding="utf-8")
    print(f"Wrote {PAPER_TEX}" + (" (preserved appended block)" if appended else ""))


def print_summary(data: dict) -> None:
    print(f"\n{'Method':18s} {'Model':14s} {'Runs':>5s} {'Valid':>7s} {'Valid%':>7s} {'Time(s)':>9s} {'Tokens':>8s} {'Calls':>6s}")
    print("-" * 80)
    method_order = ["AutoSpec", "SpecGen", "LLM-C", "SESpec_no_refine", "SESpec"]
    for method_id in method_order:
        per_model = data.get(method_id, {})
        for model in MODELS:
            sc = per_model.get(model)
            if not sc:
                continue
            s = sc.get("full_400")
            if not s or s["runs"] == 0:
                continue
            calls = "—" if s["avg_api_calls_pass"] is None else f"{s['avg_api_calls_pass']:.2f}"
            print(f"{method_id:18s} {model:14s} {s['runs']:5d} {s['valid']:7d} "
                  f"{s['valid_pct']:6.1f}% {s['avg_seconds_pass']:9.2f} "
                  f"{s['avg_tokens_pass']:8d} {calls:>6s}")


def main() -> int:
    data = compute_all()
    print_summary(data)
    write_aggregate_csv(data)
    write_main_table(data)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
