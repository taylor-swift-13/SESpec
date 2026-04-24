from __future__ import annotations

import csv
import json
from collections import defaultdict
from pathlib import Path

from represent.runners.common import ROOT


def parse_seconds(value) -> float:
    if isinstance(value, (int, float)):
        return float(value)
    if not value:
        return 0.0
    text = str(value)
    if "day" in text:
        day_part, text = text.split(", ", 1)
        days = int(day_part.split()[0])
    else:
        days = 0
    parts = text.split(":")
    if len(parts) != 3:
        return 0.0
    hours = float(parts[0])
    minutes = float(parts[1])
    seconds = float(parts[2])
    return days * 86400 + hours * 3600 + minutes * 60 + seconds


def main() -> None:
    summaries = list((ROOT / "represent" / "results").rglob("summary.json"))
    grouped = defaultdict(lambda: {"total": 0, "valid_pass": 0, "seconds": 0.0, "tokens": 0})
    for path in summaries:
        item = json.loads(path.read_text(encoding="utf-8"))
        key = (item.get("project", "unknown"), item.get("model", "unknown"))
        grouped[key]["total"] += 1
        grouped[key]["valid_pass"] += 1 if item.get("valid_pass", item.get("success")) else 0
        grouped[key]["seconds"] += parse_seconds(item.get("total_seconds") or item.get("total_solve_time"))
        grouped[key]["tokens"] += int(item.get("total_tokens", 0))

    out_path = ROOT / "represent" / "results" / "summary" / "pass1_metrics.csv"
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle)
        writer.writerow(["project", "model", "total", "valid_pass", "valid_pass_rate", "total_seconds", "avg_seconds", "total_tokens"])
        for (project, model), stats in sorted(grouped.items()):
            total = stats["total"] or 1
            writer.writerow([
                project,
                model,
                stats["total"],
                stats["valid_pass"],
                f"{stats['valid_pass'] / total:.4f}",
                f"{stats['seconds']:.2f}",
                f"{stats['seconds'] / total:.2f}",
                stats["tokens"],
            ])
    print(out_path)


if __name__ == "__main__":
    main()
