#!/usr/bin/env python3
"""Summarize SESpec matrix run directories from per-case summary.json files."""

from __future__ import annotations

import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path


def _load_summary(path: Path) -> dict:
    with path.open(encoding="utf-8") as handle:
        data = json.load(handle)
    data["_summary_path"] = path
    return data


def _parts_for_summary(root: Path, summary_path: Path) -> tuple[str, str, str, str]:
    rel = summary_path.relative_to(root)
    parts = rel.parts
    if len(parts) >= 6:
        label, bench, model, case = parts[:4]
        return label, bench, model, case
    return "", "", "", ""


def _truthy(value) -> bool:
    if isinstance(value, bool):
        return value
    if isinstance(value, (int, float)):
        return value != 0
    if isinstance(value, str):
        return value.strip().lower() in {"1", "true", "pass", "yes"}
    return False


def summarize(root: Path) -> list[dict]:
    rows: dict[tuple[str, str, str], dict] = defaultdict(lambda: {
        "label": "",
        "bench": "",
        "model": "",
        "total": 0,
        "valid_pass": 0,
        "syntax_pass": 0,
        "validity_pass": 0,
        "satisfy_pass": 0,
        "complete_pass": 0,
        "no_target_pass": 0,
        "syntax_fail": 0,
        "api_error": 0,
        "missing_candidate": 0,
        "avg_seconds": 0.0,
        "max_seconds": 0.0,
    })

    for summary_path in sorted(root.rglob("summary.json")):
        data = _load_summary(summary_path)
        label, bench, model, _case = _parts_for_summary(root, summary_path)
        key = (label, bench, model)
        row = rows[key]
        row["label"] = label
        row["bench"] = bench
        row["model"] = model
        row["total"] += 1

        syntax_status = data.get("syntax_status") or data.get("syntax")
        validity_status = data.get("validity_status") or data.get("validity")
        satisfy_status = data.get("satisfy_status") or data.get("satisfy")
        failure_reason = str(data.get("failure_reason") or "")
        valid_pass = _truthy(data.get("valid_pass")) or (
            syntax_status == "pass" and validity_status == "pass" and satisfy_status == "pass"
        )
        judge_score = data.get("judge_score")
        elapsed = float(
            data.get("total_seconds")
            or data.get("total_execution_time")
            or data.get("elapsed_seconds")
            or 0.0
        )

        row["valid_pass"] += int(valid_pass)
        row["syntax_pass"] += int(syntax_status == "pass")
        row["validity_pass"] += int(validity_status == "pass")
        row["satisfy_pass"] += int(satisfy_status == "pass")
        row["complete_pass"] += int(judge_score == 1 or str(judge_score) == "1")
        row["no_target_pass"] += int(valid_pass and failure_reason == "no_target")
        row["syntax_fail"] += int(syntax_status == "fail" or failure_reason == "syntax_error")
        row["api_error"] += int("api" in failure_reason.lower())
        row["missing_candidate"] += int("missing_candidate" in failure_reason.lower())
        row["avg_seconds"] += elapsed
        row["max_seconds"] = max(row["max_seconds"], elapsed)

    output_rows = []
    for row in rows.values():
        total = row["total"]
        if total:
            row["avg_seconds"] = round(row["avg_seconds"] / total, 3)
            row["valid_pass_rate"] = round(row["valid_pass"] / total, 6)
            row["complete_pass_rate"] = round(row["complete_pass"] / total, 6)
            row["no_target_rate"] = round(row["no_target_pass"] / total, 6)
        output_rows.append(row)
    return sorted(output_rows, key=lambda item: (item["label"], item["bench"], item["model"]))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("run_root", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()

    root = args.run_root.resolve()
    rows = summarize(root)
    output = args.output.resolve() if args.output else root / "summary.csv"
    output.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = [
        "label",
        "bench",
        "model",
        "total",
        "valid_pass",
        "valid_pass_rate",
        "complete_pass",
        "complete_pass_rate",
        "no_target_pass",
        "no_target_rate",
        "syntax_pass",
        "validity_pass",
        "satisfy_pass",
        "syntax_fail",
        "api_error",
        "missing_candidate",
        "avg_seconds",
        "max_seconds",
    ]
    with output.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)
    print(output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
