#!/usr/bin/env python3
"""Stage sespec_no_repair × gpt-5 results into RESULTS/paper_data/sespec_400_gpt5/.

Merges two matrix_root sources:
  * baseline_root: take cases whose newest summary.json has valid_pass=True
  * rerun_root   : take cases listed in --rerun-cases (or the run_ids in --rerun-root)

Outputs:
  RESULTS/paper_data/sespec_400_gpt5/
    inputs/<case>.c                     # copies of src/input/sespec/<case>.c
    sespec_no_repair/
      per_case.csv                      # 400 rows; same columns as the existing CSV
      aggregate_row.csv                 # 1 row; columns aligned with paper aggregate.csv
      README.md                         # provenance + summary
      gpt-5/<case>/                     # summary.json + foo*.{c,loop.c,qcp.c,log}

Existing sespec_no_repair/ is archived to _archive_pre_<ts>/ before overwriting.
"""
from __future__ import annotations

import argparse
import csv
import json
import shutil
import sys
import time
from pathlib import Path
from typing import Iterable, Optional

REPO_ROOT = Path(__file__).resolve().parents[2]
INPUT_DIR = REPO_ROOT / "src" / "input" / "sespec"
PAPER_DATA_ROOT = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5"

# per_case.csv columns (must match existing file exactly)
PER_CASE_COLS = [
    "model", "case_id", "function_name", "passed", "failure_reason",
    "syntax_status", "validity_status", "satisfy_status",
    "total_seconds", "total_tokens", "call_count",
]
# aggregate.csv columns (must match paper/Results/sespec_400/aggregate.csv)
AGG_COLS = [
    "method", "model", "runs", "syntax_pass", "syntax_pct",
    "valid", "valid_pct", "spec_fail", "syntax_fail",
    "avg_seconds", "avg_tokens", "avg_api_calls",
]


def newest_summary(case_dir: Path) -> Optional[Path]:
    """Return the newest summary.json under a case_dir (case_dir/<run_id>/summary.json)."""
    candidates = sorted(case_dir.rglob("summary.json"),
                        key=lambda p: p.stat().st_mtime)
    return candidates[-1] if candidates else None


def load_summary(path: Path) -> dict:
    with path.open(encoding="utf-8") as f:
        return json.load(f)


def truthy(v) -> bool:
    if isinstance(v, bool):
        return v
    if isinstance(v, str):
        return v.strip().lower() in {"true", "pass", "1", "yes"}
    if isinstance(v, (int, float)):
        return v != 0
    return False


def collect_case_summaries(matrix_root: Path, cases: Iterable[str]) -> dict:
    """case_id -> (summary_dict, summary_path) for the given cases under matrix_root."""
    label_root = matrix_root / "sespec_no_repair" / "sespec" / "gpt-5"
    if not label_root.is_dir():
        raise SystemExit(f"label root missing: {label_root}")
    out = {}
    for c in cases:
        case_dir = label_root / str(c)
        sp = newest_summary(case_dir)
        if sp is None:
            print(f"  WARN: no summary for case {c} under {label_root}", file=sys.stderr)
            continue
        out[str(c)] = (load_summary(sp), sp)
    return out


def copy_run_artifacts(summary_path: Path, dest_case_dir: Path) -> None:
    """Copy summary.json + sibling foo*.{c,loop.c,qcp.c,log} into dest_case_dir.

    Skips command.log. Creates dest_case_dir.
    """
    dest_case_dir.mkdir(parents=True, exist_ok=True)
    src_run_dir = summary_path.parent
    for f in src_run_dir.iterdir():
        if not f.is_file():
            continue
        if f.name == "command.log":
            continue
        shutil.copy2(f, dest_case_dir / f.name)


def make_per_case_row(case_id: str, data: dict) -> dict:
    return {
        "model": "gpt-5",
        "case_id": case_id,
        "function_name": data.get("function_name", ""),
        "passed": str(bool(data.get("valid_pass"))),
        "failure_reason": data.get("failure_reason", "") or "",
        "syntax_status": data.get("syntax_status", "") or "",
        "validity_status": data.get("validity_status", "") or "",
        "satisfy_status": data.get("satisfy_status", "") or "",
        "total_seconds": data.get("total_seconds", ""),
        "total_tokens": data.get("total_tokens", "") if data.get("total_tokens") is not None else "",
        "call_count": data.get("call_count", "") if data.get("call_count") is not None else "",
    }


def aggregate(rows: list[dict]) -> dict:
    """Compute one aggregate row aligned with paper/.../aggregate.csv columns."""
    total = len(rows)
    syntax_pass = sum(1 for r in rows if r["syntax_status"] == "pass")
    valid = sum(1 for r in rows if r["passed"] == "True")
    spec_fail = sum(1 for r in rows
                    if r["syntax_status"] == "pass" and r["passed"] != "True")
    syntax_fail = total - syntax_pass

    def num(v):
        if v == "" or v is None:
            return 0
        return float(v)

    sum_seconds = sum(num(r["total_seconds"]) for r in rows)
    sum_tokens = sum(num(r["total_tokens"]) for r in rows)
    sum_calls = sum(num(r["call_count"]) for r in rows)

    return {
        "method": "SESpec",
        "model": "gpt-5",
        "runs": total,
        "syntax_pass": syntax_pass,
        "syntax_pct": round(syntax_pass / total * 100, 1),
        "valid": valid,
        "valid_pct": round(valid / total * 100, 1),
        "spec_fail": spec_fail,
        "syntax_fail": syntax_fail,
        "avg_seconds": round(sum_seconds / total, 2),
        "avg_tokens": round(sum_tokens / total),
        "avg_api_calls": round(sum_calls / total, 2),
    }


def stage_inputs(case_ids: list[str], dest: Path) -> int:
    dest.mkdir(parents=True, exist_ok=True)
    n = 0
    for c in case_ids:
        src = INPUT_DIR / f"{c}.c"
        if not src.exists():
            print(f"  WARN: input {src} missing", file=sys.stderr)
            continue
        target = dest / f"{c}.c"
        if not target.exists():
            shutil.copy2(src, target)
        n += 1
    return n


def write_readme(out_dir: Path, agg: dict, baseline_n: int, rerun_n: int,
                 baseline_root: Path, rerun_root: Path) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    md = f"""# SESpec no_repair × gpt-5

- **Preset**: `sespec_no_repair` (refine_count=0, use_se=True, use_examples=True)
- **Model**: gpt-5
- **Benchmark**: `src/input/sespec/<0..399>.c` (400 cases)

## Aggregate

| runs | syntax_pass | syntax_pct | valid | valid_pct | spec_fail | syntax_fail | avg_seconds | avg_tokens | avg_api_calls |
|------|-------------|------------|-------|-----------|-----------|-------------|-------------|------------|---------------|
| {agg['runs']} | {agg['syntax_pass']} | {agg['syntax_pct']} | {agg['valid']} | {agg['valid_pct']} | {agg['spec_fail']} | {agg['syntax_fail']} | {agg['avg_seconds']} | {agg['avg_tokens']} | {agg['avg_api_calls']} |

## Data sources

- {baseline_n} cases from baseline matrix run (valid_pass=true in original): `{baseline_root}`
- {rerun_n} cases from rerun matrix run (failed cases re-attempted with latest pipeline): `{rerun_root}`

## Layout

```
sespec_400_gpt5/
├── inputs/<case>.c
└── sespec_no_repair/
    ├── per_case.csv          # 400 rows
    ├── aggregate_row.csv     # 1 row aligned with paper aggregate.csv
    ├── README.md             # this file
    └── gpt-5/<case>/
        ├── summary.json
        ├── foo*.c / foo*.loop.c / foo*.qcp.c / foo*.log (whichever the run produced)
```
"""
    (out_dir / "README.md").write_text(md, encoding="utf-8")


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--baseline-root", type=Path, required=True,
                   help="matrix_root with the original gpt-5 no_repair run")
    p.add_argument("--rerun-root", type=Path, required=True,
                   help="matrix_root with the rerun on failed cases")
    p.add_argument("--out-root", type=Path, default=PAPER_DATA_ROOT,
                   help=f"target paper_data root (default: {PAPER_DATA_ROOT})")
    p.add_argument("--archive-existing", action="store_true",
                   help="move existing sespec_no_repair/ to _archive_pre_<ts>/")
    p.add_argument("--dry-run", action="store_true")
    args = p.parse_args()

    all_cases = [str(i) for i in range(400)]

    # 1. discover which cases the baseline already passed
    print(f"== Reading baseline {args.baseline_root}")
    baseline_all = collect_case_summaries(args.baseline_root, all_cases)
    baseline_valid_cases = {c for c, (d, _) in baseline_all.items()
                            if truthy(d.get("valid_pass"))}
    print(f"   baseline valid cases: {len(baseline_valid_cases)}")

    # 2. discover which cases the rerun covers
    print(f"== Reading rerun {args.rerun_root}")
    rerun_label_root = args.rerun_root / "sespec_no_repair" / "sespec" / "gpt-5"
    rerun_case_ids = sorted([d.name for d in rerun_label_root.iterdir() if d.is_dir()],
                            key=lambda s: int(s))
    rerun_all = collect_case_summaries(args.rerun_root, rerun_case_ids)
    print(f"   rerun cases with summaries: {len(rerun_all)} / {len(rerun_case_ids)}")

    # 3. resolve final source-per-case
    selected: dict[str, tuple[dict, Path, str]] = {}  # case -> (data, summary_path, src_tag)
    for c in all_cases:
        if c in rerun_all:
            data, sp = rerun_all[c]
            selected[c] = (data, sp, "rerun")
        elif c in baseline_valid_cases:
            data, sp = baseline_all[c]
            selected[c] = (data, sp, "baseline")
        else:
            print(f"  WARN: case {c} has neither rerun nor baseline-valid data; "
                  f"falling back to baseline summary if any", file=sys.stderr)
            if c in baseline_all:
                data, sp = baseline_all[c]
                selected[c] = (data, sp, "baseline_fallback")

    print(f"   selected cases total: {len(selected)}")
    if len(selected) != 400:
        print(f"  ERROR: expected 400, got {len(selected)}; aborting.",
              file=sys.stderr)
        return 1

    # 4. build per_case rows + aggregate
    per_case_rows = [make_per_case_row(c, selected[c][0]) for c in all_cases]
    agg = aggregate(per_case_rows)
    print(f"== Aggregate: {agg}")

    if args.dry_run:
        print("[dry-run] stopping here.")
        return 0

    # 5. archive existing if requested
    out_root = args.out_root.resolve()
    target_dir = out_root / "sespec_no_repair"
    if args.archive_existing and target_dir.exists():
        ts = time.strftime("%H%M%S")
        archive = out_root / f"_archive_pre_20260518_{ts}"
        print(f"== Archiving {target_dir} -> {archive}")
        target_dir.rename(archive)

    # 6. inputs
    inputs_dir = out_root / "inputs"
    n_in = stage_inputs(all_cases, inputs_dir)
    print(f"== Staged inputs: {n_in} -> {inputs_dir}")

    # 7. per_case.csv + aggregate_row.csv + README.md
    target_dir.mkdir(parents=True, exist_ok=True)
    with (target_dir / "per_case.csv").open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=PER_CASE_COLS)
        w.writeheader()
        w.writerows(per_case_rows)
    with (target_dir / "aggregate_row.csv").open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=AGG_COLS)
        w.writeheader()
        w.writerow(agg)
    baseline_n = sum(1 for c in all_cases if selected[c][2].startswith("baseline"))
    rerun_n = sum(1 for c in all_cases if selected[c][2] == "rerun")
    write_readme(target_dir, agg, baseline_n, rerun_n,
                 args.baseline_root, args.rerun_root)

    # 8. per-case artifacts
    gpt5_dir = target_dir / "gpt-5"
    gpt5_dir.mkdir(exist_ok=True)
    for c in all_cases:
        _, sp, _ = selected[c]
        copy_run_artifacts(sp, gpt5_dir / c)
    print(f"== Wrote per-case artifacts under {gpt5_dir}")
    print(f"\nDone. {target_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
