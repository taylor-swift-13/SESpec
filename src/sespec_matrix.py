#!/usr/bin/env python3
"""Batch-run sespec main.py over a (label × bench × case × model) matrix.

Each run lands under results/matrix_runs/<matrix_run_id>/<label>/<bench>/<model>/<case_id>/<run_id>/
with command.log, summary.json, and copies of the per-run artifacts (final spec
plus the QCP/ACSL loop annotation files). An aggregate summary.csv is written at
the matrix-run root.

Example:
    OPENAI_API_KEY=... python sespec_matrix.py \
        --bench motivation_example --cases 1 --models gpt-5-nano \
        --labels sespec_default --workers 1
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import shutil
import subprocess
import sys
import time
import uuid
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional

SRC = Path(__file__).resolve().parent
INPUT_ROOT = SRC / "input"
RESULTS_ROOT = SRC / "results"
TMP_DIR = RESULTS_ROOT / "tmp"
MATRIX_ROOT_DEFAULT = RESULTS_ROOT / "matrix_runs"

# label -> base "main" config overrides applied to every per-run config.
# Add new presets here; the label string is preserved verbatim in the output tree.
PRESETS: Dict[str, Dict] = {
    "sespec_default": {
        "auto_annotation": True,
        "refine_count": 5,
        "pass_count": 1,
        "think": False,
        "use_se": True,
        "debug": False,
    },
}

C_KEYWORDS = {
    "if", "else", "while", "for", "do", "switch", "case", "default",
    "return", "sizeof", "typedef", "struct", "union", "enum", "goto",
    "break", "continue",
}
FUNC_DEF_RE = re.compile(
    r"^[ \t]*(?:static[ \t]+)?(?:[A-Za-z_]\w*[ \t\*]+)+"
    r"(?P<name>[A-Za-z_]\w*)[ \t]*\([^;{}]*\)\s*\{",
    re.MULTILINE,
)


def detect_function_name(c_path: Path) -> str:
    """Pick the verification target: prefer literal `foo`, else the last def."""
    text = c_path.read_text(encoding="utf-8", errors="ignore")
    text = re.sub(r"/\*[\s\S]*?\*/", "", text)
    text = re.sub(r"//.*", "", text)
    names = [m.group("name") for m in FUNC_DEF_RE.finditer(text)
             if m.group("name") not in C_KEYWORDS]
    if not names:
        raise RuntimeError(f"No top-level function found in {c_path}")
    return "foo" if "foo" in names else names[-1]


def make_run_id() -> str:
    return f"{datetime.now().strftime('%Y%m%d_%H%M%S')}_{os.getpid()}_{uuid.uuid4().hex[:8]}"


def make_per_run_config(label: str, bench: str, case_id: str, model: str,
                        function_name: str, run_id: str,
                        label_settings: Dict) -> Path:
    cfg = {
        "main": {
            "root_dir": bench,
            "function_name": function_name,
            **label_settings,
        },
        "llm": {"api_model": model},
        "preconditions": {function_name: "emp"},
    }
    TMP_DIR.mkdir(parents=True, exist_ok=True)
    name = f"{label}_{bench}_{case_id}_{model}_{run_id}.json"
    path = TMP_DIR / name
    path.write_text(json.dumps(cfg, indent=2))
    return path


WORKSPACE_RE = re.compile(r"workspace_root=(\S+)")
SVS_RE = re.compile(
    r"syntax(?:_round)?\s*=\s*(\w+)\s*,\s*valid(?:_round)?\s*=\s*(\w+)\s*,\s*satisfy(?:_round)?\s*=\s*(\w+)"
)
TOTAL_TIME_RE = re.compile(r"Total execution time:\s*([\d.]+)\s*seconds")
TOKEN_RES = {
    "prompt_tokens":     re.compile(r"Total prompt tokens[^:]*:\s*([\d,]+)"),
    "completion_tokens": re.compile(r"Total completion tokens[^:]*:\s*([\d,]+)"),
    "total_tokens":      re.compile(r"Total tokens:\s*([\d,]+)"),
    "call_count":        re.compile(r"Total API calls:\s*(\d+)"),
}


def _parse_int(s: Optional[str]) -> Optional[int]:
    if not s or s.lower() == "none":
        return None
    try:
        return int(s.replace(",", ""))
    except ValueError:
        return None


def parse_metrics(stdout: str) -> Dict:
    out = {
        "workspace_root": None,
        "syntax_round": None, "valid_round": None, "satisfy_round": None,
        "total_seconds": None,
        "prompt_tokens": None, "completion_tokens": None,
        "total_tokens": None, "call_count": None,
    }
    m = WORKSPACE_RE.search(stdout)
    if m:
        out["workspace_root"] = m.group(1)
    m = SVS_RE.search(stdout)
    if m:
        out["syntax_round"] = _parse_int(m.group(1))
        out["valid_round"] = _parse_int(m.group(2))
        out["satisfy_round"] = _parse_int(m.group(3))
    m = TOTAL_TIME_RE.search(stdout)
    if m:
        out["total_seconds"] = float(m.group(1))
    for key, regex in TOKEN_RES.items():
        m = regex.search(stdout)
        if m:
            out[key] = _parse_int(m.group(1))
    return out


def _copy_if_exists(src: Path, dst: Path) -> bool:
    if src.exists():
        shutil.copyfile(src, dst)
        return True
    return False


def run_one(task: Dict) -> Dict:
    label = task["label"]
    bench = task["bench"]
    case_id = task["case_id"]
    model = task["model"]
    label_settings = task["label_settings"]
    matrix_root: Path = task["matrix_root"]
    python_exe = task["python_exe"]

    src_c = INPUT_ROOT / bench / f"{case_id}.c"
    if not src_c.exists():
        return {
            "label": label, "bench": bench, "case_id": case_id, "model": model,
            "skip": True, "skip_reason": f"input not found: {src_c}",
            "success": False,
        }

    try:
        function_name = detect_function_name(src_c)
    except Exception as e:
        return {
            "label": label, "bench": bench, "case_id": case_id, "model": model,
            "skip": True, "skip_reason": f"function detect failed: {e}",
            "success": False,
        }

    run_id = make_run_id()
    cfg_path = make_per_run_config(label, bench, case_id, model,
                                   function_name, run_id, label_settings)

    out_dir = matrix_root / label / bench / model / case_id / run_id
    out_dir.mkdir(parents=True, exist_ok=True)

    cmd = [str(python_exe), "main.py", "--config", str(cfg_path)]
    started = time.time()
    proc = subprocess.run(cmd, cwd=str(SRC), capture_output=True, text=True)
    wall_seconds = time.time() - started

    (out_dir / "command.log").write_text(
        f"$ {' '.join(cmd)}\n\n[stdout]\n{proc.stdout}\n[stderr]\n{proc.stderr}\n"
    )

    metrics = parse_metrics(proc.stdout)
    workspace_root = metrics["workspace_root"]

    log_path = out_dir / f"{function_name}.log"
    output_path = out_dir / f"{function_name}.c"
    qcp_path = out_dir / f"{function_name}.qcp.c"
    loop_path = out_dir / f"{function_name}.loop.c"

    if workspace_root and Path(workspace_root).is_dir():
        ws = Path(workspace_root)
        _copy_if_exists(ws / "run.log", log_path)
        _copy_if_exists(ws / "output" / f"{function_name}.c", output_path)
        _copy_if_exists(ws / "2_output" / f"{function_name}.c", qcp_path)
        _copy_if_exists(ws / "3_output" / f"{function_name}.c", loop_path)

    syntax_pass = metrics["syntax_round"] is not None
    valid_pass = metrics["valid_round"] is not None
    satisfy_pass = metrics["satisfy_round"] is not None
    success = proc.returncode == 0 and satisfy_pass

    if success:
        failure_reason = "pass"
    elif proc.returncode != 0:
        failure_reason = f"returncode_{proc.returncode}"
    elif not syntax_pass:
        failure_reason = "no_syntax"
    elif not valid_pass:
        failure_reason = "no_valid"
    else:
        failure_reason = "no_satisfy"

    project, _, preset = label.partition("_")

    summary = {
        "project": project or "sespec",
        "preset": preset or "default",
        "label": label,
        "model": model,
        "root_dir": bench,
        "bench": bench,
        "case_id": case_id,
        "function_name": function_name,
        "source_path": str(src_c),
        "returncode": proc.returncode,
        "command": cmd,
        "run_id": run_id,
        "workspace_root": workspace_root,
        "log_path": str(log_path) if log_path.exists() else None,
        "output_path": str(output_path) if output_path.exists() else None,
        "loop_qcp_path": str(qcp_path) if qcp_path.exists() else None,
        "loop_acsl_path": str(loop_path) if loop_path.exists() else None,
        "iteration": 1,
        "success": success,
        "valid_pass": valid_pass,
        "syntax_ok": syntax_pass,
        "first_pass_syntax": syntax_pass,
        "first_pass_valid": valid_pass,
        "syntax_round": metrics["syntax_round"],
        "valid_round": metrics["valid_round"],
        "satisfy_round": metrics["satisfy_round"],
        "syntax_status": "pass" if syntax_pass else "fail",
        "validity_status": "pass" if valid_pass else "fail",
        "satisfy_status": "pass" if satisfy_pass else "fail",
        "failure_reason": failure_reason,
        "total_seconds": metrics["total_seconds"] if metrics["total_seconds"] is not None else wall_seconds,
        "prompt_tokens": metrics["prompt_tokens"],
        "completion_tokens": metrics["completion_tokens"],
        "total_tokens": metrics["total_tokens"],
        "call_count": metrics["call_count"],
        "judge_score": None,
    }
    (out_dir / "summary.json").write_text(json.dumps(summary, indent=2))
    return summary


def aggregate_csv(summaries: List[Dict], csv_path: Path) -> None:
    fields = [
        "label", "bench", "model", "total", "success", "valid", "syntax",
        "satisfy", "skip", "success_rate", "valid_rate", "satisfy_rate",
        "judge_count", "complete", "complete_score", "complete_rate",
        "total_seconds", "total_tokens",
    ]
    skipped_per_group: Dict = {}
    runs_per_group: Dict = {}
    for s in summaries:
        key = (s.get("label"), s.get("bench") or s.get("root_dir"), s.get("model"))
        if s.get("skip"):
            skipped_per_group[key] = skipped_per_group.get(key, 0) + 1
            continue
        runs_per_group.setdefault(key, []).append(s)

    with csv_path.open("w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(fields)
        for key, runs in runs_per_group.items():
            label, bench, model = key
            total = len(runs)
            success = sum(1 for r in runs if r.get("success"))
            valid = sum(1 for r in runs if r.get("valid_pass"))
            syntax = sum(1 for r in runs if r.get("syntax_ok"))
            satisfy = sum(1 for r in runs if r.get("satisfy_status") == "pass")
            skip = skipped_per_group.get(key, 0)
            secs = sum((r.get("total_seconds") or 0) for r in runs)
            toks = sum((r.get("total_tokens") or 0) for r in runs)
            denom = total if total else 1
            writer.writerow([
                label, bench, model,
                total, success, valid, syntax, satisfy, skip,
                f"{success/denom:.4f}", f"{valid/denom:.4f}", f"{satisfy/denom:.4f}",
                0, 0, "0.0000", "0.0000",
                f"{secs:.2f}", toks,
            ])


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--bench", nargs="+", required=True,
                   help="One or more bench names (subfolders under input/)")
    p.add_argument("--cases", nargs="+", required=True,
                   help="One or more case ids (e.g. 1 2 26)")
    p.add_argument("--models", nargs="+", required=True,
                   help="One or more model names (passed to llm.api_model)")
    p.add_argument("--labels", nargs="+", default=["sespec_default"],
                   help="One or more preset labels (default: sespec_default)")
    p.add_argument("--workers", type=int, default=1, help="Parallel runs")
    p.add_argument("--python-exe", default=sys.executable,
                   help="Python interpreter used to launch main.py")
    p.add_argument("--matrix-root", default=None,
                   help="Override output root (default: results/matrix_runs/<run_id>)")
    p.add_argument("--use-se", dest="use_se", action="store_true", default=None,
                   help="Force-enable symbolic execution for loop-free postconds")
    p.add_argument("--no-se", dest="use_se", action="store_false",
                   help="Force-disable symbolic execution; use LLM for all postconds")
    return p.parse_args()


def main() -> int:
    args = parse_args()

    if args.matrix_root:
        matrix_root = Path(args.matrix_root)
    else:
        matrix_root = MATRIX_ROOT_DEFAULT / make_run_id()
    matrix_root.mkdir(parents=True, exist_ok=True)

    tasks = []
    for label in args.labels:
        if label not in PRESETS:
            print(f"⚠ unknown label '{label}'; falling back to sespec_default settings",
                  file=sys.stderr)
        settings = dict(PRESETS.get(label, PRESETS["sespec_default"]))
        if args.use_se is not None:
            settings["use_se"] = args.use_se
        for bench in args.bench:
            for case_id in args.cases:
                for model in args.models:
                    tasks.append({
                        "label": label,
                        "bench": bench,
                        "case_id": str(case_id),
                        "model": model,
                        "label_settings": settings,
                        "matrix_root": matrix_root,
                        "python_exe": args.python_exe,
                    })

    print(f"📋 Matrix: {len(tasks)} run(s) → {matrix_root}", flush=True)
    summaries: List[Dict] = []

    if args.workers <= 1:
        for i, t in enumerate(tasks, 1):
            print(f"[{i}/{len(tasks)}] ▶ {t['label']}/{t['bench']}/{t['case_id']}/{t['model']}",
                  flush=True)
            s = run_one(t)
            tag = "skip" if s.get("skip") else ("ok" if s.get("success") else "fail")
            print(f"[{i}/{len(tasks)}] {tag} ({s.get('failure_reason', s.get('skip_reason'))})",
                  flush=True)
            summaries.append(s)
    else:
        with ThreadPoolExecutor(max_workers=args.workers) as pool:
            futures = {pool.submit(run_one, t): t for t in tasks}
            for fut in as_completed(futures):
                t = futures[fut]
                s = fut.result()
                tag = "skip" if s.get("skip") else ("ok" if s.get("success") else "fail")
                print(f"{tag} {t['label']}/{t['bench']}/{t['case_id']}/{t['model']} "
                      f"({s.get('failure_reason', s.get('skip_reason'))})",
                      flush=True)
                summaries.append(s)

    csv_path = matrix_root / "summary.csv"
    aggregate_csv(summaries, csv_path)

    total = sum(1 for s in summaries if not s.get("skip"))
    succ = sum(1 for s in summaries if s.get("success"))
    skipped = sum(1 for s in summaries if s.get("skip"))
    print(f"\n📊 {succ}/{total} succeeded ({skipped} skipped) → {csv_path}")
    return 0 if succ == total else 1


if __name__ == "__main__":
    sys.exit(main())
