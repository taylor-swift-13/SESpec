#!/usr/bin/env python3
"""Aggregate gpt-5 results across all methods and refresh paper artifacts.

Reads each method's per_case.csv under RESULTS/paper_data/sespec_400_gpt5/,
computes Valid/Time/Tokens/API-calls stats at both full_400 and arc_352 scopes,
and:
  1. Rewrites RESULTS/paper_data/sespec_400_gpt5/aggregate.csv.
  2. Emits paper/FSEchapters/large_experiment_table_gpt5.tex (supplementary table).

Per-method per_case.csv schemas:
  - autospec / specgen / bare_model_c columns:
      model, case_id, arc_stem, passed, skipped, skip_reason,
      checked_goal_count, valid_goal_count, total_seconds, total_tokens
  - sespec / sespec_no_repair columns:
      model, case_id, function_name, passed, failure_reason,
      syntax_status, validity_status, satisfy_status,
      total_seconds, total_tokens, call_count
"""
from __future__ import annotations

import csv
import json
from pathlib import Path
from typing import Optional

REPO_ROOT = Path(__file__).resolve().parents[2]
PD_ROOT = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5"
PAPER_TEX = REPO_ROOT / "paper" / "FSEchapters" / "large_experiment_table_gpt5.tex"
AGG_OUT = PD_ROOT / "aggregate.csv"

# method_id -> (display_name, per_case_dir, scope_400_or_352)
METHODS = [
    ("SESpec",            "SESpec",                          "sespec",            "full_400"),
    ("SESpec_no_repair",  "SESpec w/o refine",               "sespec_no_repair",  "full_400"),
    ("AutoSpec",          "AutoSpec (C/ACSL)",               "autospec",          "full_400"),
    ("LLM-C",             "Bare LLM (C/ACSL)",               "bare_model_c",      "full_400"),
    ("SpecGen",           "SpecGen (Java/JML)",              "specgen",           "arc_352"),
]


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


def load_per_case(csv_path: Path) -> list[dict]:
    rows = []
    with csv_path.open(encoding="utf-8") as f:
        r = csv.DictReader(f)
        for row in r:
            if row.get("model") != "gpt-5":
                continue
            rows.append(row)
    return rows


def load_summaries(method_dir_root: Path) -> list[dict]:
    """Load every gpt-5/<case>/summary.json under method_dir_root.

    Normalizes to per_case row shape: case_id, passed, total_seconds, total_tokens, call_count.
    """
    rows = []
    method_root = method_dir_root / "gpt-5"
    if not method_root.is_dir():
        return rows
    for case_dir in sorted(method_root.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else 1 << 30):
        sp = case_dir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        rows.append({
            "case_id": case_dir.name,
            "passed": str(bool(d.get("valid_pass"))),
            "total_seconds": d.get("total_seconds") or 0,
            "total_tokens": d.get("total_tokens") or 0,
            "call_count": d.get("call_count"),  # may be None
            "_raw": d,
        })
    return rows


def get_call_count(row: dict, method_dir: str) -> Optional[float]:
    """API call count: explicit in sespec*, fall back to summary.json for others."""
    if "call_count" in row and row["call_count"] not in (None, ""):
        try:
            return float(row["call_count"])
        except ValueError:
            return None
    return None  # autospec/specgen/bare_model don't track call count in per_case.csv


def fetch_call_count_from_summary(method_dir: str, case_id: str) -> Optional[float]:
    """For methods without call_count in per_case.csv, look it up in summary.json.

    Only returns explicit numeric call_count / api_calls fields. AutoSpec and friends
    don't track this in a comparable way, so we return None and let callers decide
    on a default (1.0 for one-shot baselines; '—' for iterative without tracking).
    """
    sp = PD_ROOT / method_dir / "gpt-5" / case_id / "summary.json"
    if not sp.exists():
        return None
    try:
        d = json.loads(sp.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return None
    for k in ("call_count", "api_calls"):
        v = d.get(k)
        if isinstance(v, (int, float)) and v >= 0:
            return float(v)
    return None


ONE_SHOT_METHODS = {"bare_model_c", "specgen"}  # default to 1.0 calls when untracked


def _stats(rows: list[dict], method_dir: str) -> dict:
    total = len(rows)
    valid_rows = [r for r in rows if truthy(r.get("passed"))]
    valid = len(valid_rows)
    sum_sec = sum(num(r.get("total_seconds")) for r in valid_rows)
    sum_tok = sum(num(r.get("total_tokens")) for r in valid_rows)
    ccs = []
    tracked_any = False
    for r in valid_rows:
        cc = get_call_count(r, method_dir)
        if cc is None:
            cc = fetch_call_count_from_summary(method_dir, r["case_id"])
        if cc is not None:
            tracked_any = True
        elif method_dir in ONE_SHOT_METHODS:
            cc = 1.0
        if cc is not None:
            ccs.append(cc)
    avg_calls = (round(sum(ccs) / valid, 2) if valid and ccs else None)
    if not tracked_any and method_dir not in ONE_SHOT_METHODS:
        avg_calls = None  # iterative without tracking → '—' in output
    return {
        "runs": total,
        "valid": valid,
        "valid_pct": round(valid / total * 100, 1) if total else 0.0,
        "avg_seconds_pass": round(sum_sec / valid, 2) if valid else 0.0,
        "avg_tokens_pass": round(sum_tok / valid) if valid else 0,
        "avg_api_calls_pass": avg_calls,
    }


def aggregate_method(method_id: str, method_dir: str) -> dict:
    """Compute full-set stats from gpt-5/<case>/summary.json (authoritative)."""
    rows = load_summaries(PD_ROOT / method_dir)
    s = _stats(rows, method_dir)
    return {"method": method_id, "model": "gpt-5", **s}


def write_aggregate(rows: list[dict]) -> None:
    """Write RESULTS/paper_data/sespec_400_gpt5/aggregate.csv with full_400 + arc_352."""
    AGG_OUT.parent.mkdir(parents=True, exist_ok=True)
    out = []
    # full_400 scope: methods where runs==400 (sespec, sespec_no_repair, autospec, bare_model_c if applicable)
    # arc_352 scope: subset of cases also available for Java methods (specgen, bare_model_c)
    # We compute scopes per requested mapping in METHODS.
    by_id = {r["method"]: r for r in rows}

    for method_id, _, _, scope_default in METHODS:
        if method_id not in by_id:
            continue
        r = by_id[method_id]
        if r["runs"] == 0:
            continue
        out_row = {
            "scope": scope_default,
            "method": method_id,
            "model": "gpt-5",
            "runs": r["runs"],
            "valid": r["valid"],
            "valid_pct": r["valid_pct"],
            "avg_seconds_pass": r["avg_seconds_pass"],
            "avg_tokens_pass": r["avg_tokens_pass"],
            "avg_api_calls_pass": r["avg_api_calls_pass"],
        }
        out.append(out_row)

    # Also compute arc_352 restriction for the full-400 C methods so the
    # arc_352 scope is apples-to-apples with SpecGen / Bare LLM.
    arc_mapping = PD_ROOT / "arc_mapping.csv"
    arc_case_ids = set()
    if arc_mapping.exists():
        with arc_mapping.open(encoding="utf-8") as f:
            for row in csv.DictReader(f):
                arc_case_ids.add(row["sespec_new_id"])

    if arc_case_ids:
        for method_id, _disp, method_dir, scope_default in METHODS:
            if scope_default != "full_400":
                continue
            rows_all = load_summaries(PD_ROOT / method_dir)
            restricted = [r for r in rows_all if r["case_id"] in arc_case_ids]
            if not restricted:
                continue
            s = _stats(restricted, method_dir)
            out.append({
                "scope": "arc_352",
                "method": method_id,
                "model": "gpt-5",
                **s,
            })

    fieldnames = [
        "scope", "method", "model", "runs", "valid", "valid_pct",
        "avg_seconds_pass", "avg_tokens_pass", "avg_api_calls_pass",
    ]
    # Normalize None values for CSV
    for row in out:
        if row.get("avg_api_calls_pass") is None:
            row["avg_api_calls_pass"] = ""
    with AGG_OUT.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(sorted(out, key=lambda r: (r["scope"], r["method"])))
    print(f"Wrote {AGG_OUT}")


def write_latex_table(rows: list[dict]) -> None:
    """Emit a supplementary LaTeX table covering gpt-5 across all methods."""
    by_id = {r["method"]: r for r in rows}

    def fmt_int(n):
        return f"{int(n):,}".replace(",", "{,}")

    def fmt_float(f):
        return f"{f:.1f}"

    lines = []
    lines.append("% Auto-generated by src/scripts/aggregate_gpt5_methods.py — do not hand-edit.")
    lines.append(r"\begin{table*}[t]")
    lines.append(r"\centering")
    lines.append(r"\caption{Supplementary evaluation on \texttt{gpt-5} for the \textsc{sespec} benchmark. C/ACSL methods are evaluated on all 400 cases. SpecGen is reported on the arc-352 Java-aligned subset (the remaining 48 cases have no Java original).}")
    lines.append(r"\label{tab:large_experiment_summary_gpt5}")
    lines.append(r"\scriptsize")
    lines.append(r"\setlength{\tabcolsep}{4pt}")
    lines.append(r"\begin{adjustbox}{width=\textwidth}")
    lines.append(r"\begin{tabular}{lrrrrrr}")
    lines.append(r"\toprule")
    lines.append(r"Method & Runs & Valid & Valid (\%) & Time (s) & Tokens & API Calls \\")
    lines.append(r"\midrule")

    # C/ACSL block uses each method's full_400 numbers; SpecGen falls back to arc_352.
    display_rows = [
        ("AutoSpec",         "AutoSpec (C/ACSL)"),
        ("LLM-C",            r"\toolname\ w/o refine w/o SE (Pure LLM)"),
        ("SESpec_no_repair", r"\toolname\ w/o refine"),
        ("SESpec",           r"\textbf{\toolname}"),
        ("SpecGen",          "SpecGen (Java/JML)"),
    ]

    for method_id, display in display_rows:
        if method_id not in by_id:
            continue
        r = by_id[method_id]
        calls_str = "---" if r["avg_api_calls_pass"] is None else fmt_float(r["avg_api_calls_pass"])
        lines.append(
            f"{display} & {r['runs']} & {r['valid']} & "
            f"{fmt_float(r['valid_pct'])} & {fmt_float(r['avg_seconds_pass'])} & "
            f"{fmt_int(r['avg_tokens_pass'])} & {calls_str} \\\\"
        )

    lines.append(r"\bottomrule")
    lines.append(r"\end{tabular}")
    lines.append(r"\end{adjustbox}")
    lines.append(r"\end{table*}")
    PAPER_TEX.parent.mkdir(parents=True, exist_ok=True)
    PAPER_TEX.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {PAPER_TEX}")


def main() -> int:
    rows = []
    for method_id, _, method_dir, _ in METHODS:
        csv_path = PD_ROOT / method_dir / "per_case.csv"
        if not csv_path.exists():
            print(f"  WARN: missing per_case.csv for {method_id} ({csv_path})")
            continue
        r = aggregate_method(method_id, method_dir)
        rows.append(r)
        calls_disp = "  N/A" if r['avg_api_calls_pass'] is None else f"{r['avg_api_calls_pass']:5.2f}"
        print(f"  {method_id:18s} runs={r['runs']:4d}  valid={r['valid']:4d} ({r['valid_pct']:5.1f}%)  "
              f"avg_sec={r['avg_seconds_pass']:7.2f}  avg_tok={r['avg_tokens_pass']:6d}  avg_calls={calls_disp}")

    write_aggregate(rows)
    write_latex_table(rows)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
