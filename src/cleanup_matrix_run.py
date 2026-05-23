#!/usr/bin/env python3
"""Delete run_id directories under a matrix_root whose summary.json shows
syntax/validity/satisfy not all `pass`.

Usage:
    python cleanup_matrix_run.py <matrix_root> [--dry-run]
"""
from __future__ import annotations

import argparse
import json
import shutil
import sys
from pathlib import Path


def run_passes(summary_path: Path) -> bool:
    try:
        s = json.loads(summary_path.read_text())
    except Exception:
        return False
    return (
        s.get("syntax_status") == "pass"
        and s.get("validity_status") == "pass"
        and s.get("satisfy_status") == "pass"
    )


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("matrix_root")
    p.add_argument("--dry-run", action="store_true")
    args = p.parse_args()

    root = Path(args.matrix_root).resolve()
    if not root.is_dir():
        print(f"not a directory: {root}", file=sys.stderr)
        return 2

    summaries = sorted(root.glob("*/*/*/*/*/summary.json"))
    # layout: <label>/<bench>/<model>/<case_id>/<run_id>/summary.json
    kept = deleted = orphan = 0
    for sp in summaries:
        run_dir = sp.parent
        if run_passes(sp):
            kept += 1
            continue
        deleted += 1
        print(f"DROP {run_dir.relative_to(root)}")
        if not args.dry_run:
            shutil.rmtree(run_dir)

    # Also drop empty run dirs that have no summary.json (interrupted runs).
    for case_dir in root.glob("*/*/*/*"):
        if not case_dir.is_dir():
            continue
        for run_dir in case_dir.iterdir():
            if not run_dir.is_dir():
                continue
            if not (run_dir / "summary.json").exists():
                orphan += 1
                print(f"DROP-ORPHAN {run_dir.relative_to(root)}")
                if not args.dry_run:
                    shutil.rmtree(run_dir)

    # Prune now-empty case dirs.
    for case_dir in root.glob("*/*/*/*"):
        if case_dir.is_dir() and not any(case_dir.iterdir()):
            print(f"RMDIR {case_dir.relative_to(root)}")
            if not args.dry_run:
                case_dir.rmdir()

    print(f"\nkept={kept} deleted={deleted} orphan_runs={orphan}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
