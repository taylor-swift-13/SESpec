#!/usr/bin/env python3
"""Re-run failed cases from a previous matrix run.

Walks `MATRIX_DIR`, identifies (label, bench, model, case_id) tuples whose
latest summary.json has `judge_score == 1` (treated as "complete"), and
re-runs every other tuple via sespec_matrix.py — once per (label, bench,
model) chunk with the missing case-ids passed via --cases.

Edit the constants at the top of the file if needed. The defaults match
the matrix run at /home/yangfp/SESpec/src/results/matrix_runs/20260503_050609,
all five models, all three labels, refine_count=0 / pass_count=1, and
--skip-support-check forwarded to sespec_matrix.

Run from anywhere — the script `cd`s into SRC_DIR before invoking matrix.
"""
from __future__ import annotations

import json
import os
import re
import subprocess
import sys
from datetime import datetime
from pathlib import Path

MATRIX_DIR = Path("/home/yangfp/SESpec/src/results/matrix_runs/20260503_050609")
SRC_DIR    = Path("/home/yangfp/SESpec/src")
PYTHON     = "/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
API_KEY    = "sk-afVplv2oRlR8SnMlC3K0ndGKOIsaBN5O3zxrD1B7zWzgNWGA"

LABELS  = ["sespec_default", "sespec_no_repair", "sespec_no_se_no_repair"]
MODELS  = ["gpt-5-nano", "gpt-5-mini", "gpt-4o", "gpt-5.4-mini", "gpt-5.4-nano"]
WORKERS = 24

# Extra flags forwarded verbatim to sespec_matrix.py.
EXTRA_FLAGS = [
    "--refine-count", "10",
    "--pass-count", "1",
]


def load_done(matrix_dir: Path) -> set[tuple[str, str, str, str]]:
    """Walk the matrix-run tree and return tuples whose latest summary
    indicates judge_score == 1 (a fully-judged correct run)."""
    done: set[tuple[str, str, str, str]] = set()
    if not matrix_dir.is_dir():
        print(f"warning: {matrix_dir} not found — treating as empty", file=sys.stderr)
        return done

    for label_dir in matrix_dir.iterdir():
        if not label_dir.is_dir() or label_dir.name.startswith("_"):
            continue
        label = label_dir.name
        for bench_dir in label_dir.iterdir():
            if not bench_dir.is_dir():
                continue
            bench = bench_dir.name
            for model_dir in bench_dir.iterdir():
                if not model_dir.is_dir():
                    continue
                model = model_dir.name
                for case_dir in model_dir.iterdir():
                    if not case_dir.is_dir():
                        continue
                    runs = sorted(
                        (d for d in case_dir.iterdir() if d.is_dir()),
                        key=lambda p: p.name,
                    )
                    if not runs:
                        continue
                    summary = runs[-1] / "summary.json"
                    if not summary.is_file():
                        continue
                    try:
                        s = json.loads(summary.read_text(encoding="utf-8"))
                    except Exception:
                        continue
                    if s.get("judge_score") == 1:
                        done.add((label, bench, model, case_dir.name))
    return done


_UNSUPPORTED_CALLEES = ("malloc", "calloc", "realloc", "free")


def _has_unsupported_callee(c_path: Path) -> bool:
    """True if the source file calls a stdlib allocator / freer that the
    pipeline can't model (it'd treat them as user functions and crash with
    'Can not Found Function malloc')."""
    try:
        text = c_path.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return False
    # Drop comments before checking, so commented occurrences don't trigger.
    text = re.sub(r"/\*[\s\S]*?\*/|//[^\n]*", "", text)
    return any(re.search(rf"\b{name}\s*\(", text) for name in _UNSUPPORTED_CALLEES)


def enumerate_inputs(input_root: Path, allowed_benches: set[str] | None = None):
    """Map bench → (kept_case_ids, skipped_case_ids).
    Skipped cases call malloc/free/etc. and crash main.py — we treat them as
    failed in the aggregate (write a stub failure summary.json) instead of
    feeding them into sespec_matrix."""
    benches: dict[str, tuple[list[str], list[str]]] = {}
    if not input_root.is_dir():
        return benches
    for bench_dir in sorted(input_root.iterdir()):
        if not bench_dir.is_dir():
            continue
        if allowed_benches is not None and bench_dir.name not in allowed_benches:
            continue
        kept, skipped = [], []
        for f in sorted(bench_dir.glob("*.c")):
            (skipped if _has_unsupported_callee(f) else kept).append(f.stem)
        if skipped:
            print(f"  {bench_dir.name}: {len(skipped)} cases with malloc/free/etc. → counted as failed",
                  file=sys.stderr)
        benches[bench_dir.name] = (kept, skipped)
    return benches


def _write_unsupported_stub(matrix_root: Path, label: str, bench: str, model: str, case_id: str) -> None:
    """Write a summary.json marking this case as failed (success=False) so
    that downstream aggregation counts it as wrong, not as skipped."""
    run_id = datetime.now().strftime("%Y%m%d_%H%M%S") + f"_unsupported_{case_id}"
    out_dir = matrix_root / label / bench / model / case_id / run_id
    out_dir.mkdir(parents=True, exist_ok=True)
    stub = {
        "project": "sespec",
        "preset": label.replace("sespec_", ""),
        "label": label,
        "model": model,
        "bench": bench,
        "root_dir": bench,
        "case_id": case_id,
        "function_name": None,
        "success": False,
        "valid_pass": False,
        "syntax_ok": False,
        "satisfy_status": "fail",
        "validity_status": "fail",
        "syntax_status": "fail",
        "failure_reason": "unsupported_callee_malloc",
        "judge_score": 0,
        "total_seconds": 0,
        "total_tokens": 0,
        "skip": False,
    }
    (out_dir / "summary.json").write_text(json.dumps(stub, indent=2))


def main() -> int:
    # Set FILTER_DONE=False to re-run every (label, bench, model, case) tuple,
    # ignoring the previous matrix run's per-case judge_score.
    FILTER_DONE = False

    done = load_done(MATRIX_DIR) if FILTER_DONE else set()
    print(f"already-complete tuples: {len(done)} (filter={FILTER_DONE})", file=sys.stderr)

    # Only iterate benches that actually appear in MATRIX_DIR — i.e. only
    # the ones the previous matrix run targeted. Skips bench dirs in
    # input/ that weren't part of that run.
    allowed = {
        b.name
        for label_dir in MATRIX_DIR.iterdir() if label_dir.is_dir() and not label_dir.name.startswith("_")
        for b in label_dir.iterdir() if b.is_dir()
    }
    print(f"matrix-run benches: {sorted(allowed)}", file=sys.stderr)

    benches_cases = enumerate_inputs(SRC_DIR / "input", allowed_benches=allowed)
    total_kept = sum(len(k) for k, _ in benches_cases.values())
    total_skipped = sum(len(s) for _, s in benches_cases.values())
    print(f"benches: {len(benches_cases)}, total runnable cases: {total_kept}, "
          f"unsupported (counted as failed): {total_skipped}", file=sys.stderr)

    # All invocations share one matrix_root so outputs land in a single
    # directory you can browse / aggregate after the run.
    from datetime import datetime
    rerun_id = datetime.now().strftime("%Y%m%d_%H%M%S") + "_rerun_incomplete"
    matrix_root = SRC_DIR / "results" / "matrix_runs" / rerun_id
    matrix_root.mkdir(parents=True, exist_ok=True)
    print(f"output root: {matrix_root}", file=sys.stderr)

    env = os.environ.copy()
    env["OPENAI_API_KEY"] = API_KEY

    # Bring frama-c (and the rest of the opam switch) onto PATH so
    # sespec_matrix's child main.py invocations can find it.
    try:
        opam_env = subprocess.check_output(
            ["opam", "env", "--switch=frama-c.27.1", "--set-switch"],
            text=True,
        )
        for line in opam_env.splitlines():
            m = re.match(r"^([A-Z_][A-Z0-9_]*)='([^']*)'", line)
            if m:
                env[m.group(1)] = m.group(2)
    except Exception as e:
        print(f"warning: failed to load opam env: {e}", file=sys.stderr)

    invocations = 0
    total_cases = 0
    stub_count = 0
    for label in LABELS:
        for bench, (kept, skipped) in benches_cases.items():
            for model in MODELS:
                # Stub the unsupported cases (malloc/free) as failures so
                # they show up in the aggregate summary.
                for case_id in skipped:
                    if (label, bench, model, case_id) in done:
                        continue
                    _write_unsupported_stub(matrix_root, label, bench, model, case_id)
                    stub_count += 1

                todo = [c for c in kept if (label, bench, model, c) not in done]
                if not todo:
                    continue
                cmd = [
                    PYTHON, "sespec_matrix.py",
                    "--bench", bench,
                    "--cases", *todo,
                    "--models", model,
                    "--labels", label,
                    "--workers", str(WORKERS),
                    "--matrix-root", str(matrix_root),
                    *EXTRA_FLAGS,
                ]
                print(f"[{invocations}] {label}/{bench}/{model}: "
                      f"{len(todo)} cases", file=sys.stderr)
                invocations += 1
                total_cases += len(todo)
                subprocess.run(cmd, cwd=str(SRC_DIR), env=env, check=False)

    print(f"done: {invocations} matrix invocations, {total_cases} runnable cases, "
          f"{stub_count} stubbed-as-failed (unsupported)", file=sys.stderr)
    print(f"results in: {matrix_root}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
