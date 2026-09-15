#!/usr/bin/env python3
"""Fill gpt-5.4-mini AutoSpec cost gaps without overwriting archived runs."""

import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time


ROOT = Path(__file__).resolve().parents[1]
DATA = ROOT / "RESULTS/paper_data"
OUT = DATA / "rq7_cost/reanalysis/reruns/autospec/gpt-5.4-mini"
AUTOSPEC = Path(os.environ.get(
    "RQ7_AUTOSPEC_ROOT", "/home/yangfp/TRASH/SESpecTrash/represent/external/autospec"
))
PYTHON = Path("/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python")
WRAPPER = ROOT / "tools/rq7_autospec_step.py"
MODEL = "gpt-5.4-mini"
MAX_STEPS = 20
MAX_SECONDS = 1800
TOKENS = re.compile(r"tokens_usage\s*=\s*(\d+)")
RETURN = re.compile(r"\bret\s*=\s*(True|False)")
USAGE = re.compile(r"^AUTOSPEC_API_USAGE=(\{.*\})$", re.MULTILINE)
LOGGED_TOKENS = re.compile(r"(?:^|\n)\s*(?:INFO:root:)?total_tokens:\s*(\d+)")


def source_for(case_id):
    source = DATA / "rq5_validity/runs/specgen" / MODEL / str(case_id) / "summary.json"
    stem = json.loads(source.read_text())["archive_case_id"]
    path = AUTOSPEC / "benchmark/represent_matrix" / f"{stem}.c"
    if not path.is_file():
        raise FileNotFoundError(path)
    return stem, path


def original_calls(case_id):
    source = DATA / "rq5_validity/runs/autospec" / MODEL / str(case_id) / "summary.json"
    if source.exists():
        return int(json.loads(source.read_text())["api_calls"])
    stem, _ = source_for(case_id)
    archive = AUTOSPEC.parent.parent / "results/smoke/autospec/one_shot" / MODEL / stem / "summary.json"
    return int(json.loads(archive.read_text())["step_count"])


def child_env(key):
    env = os.environ.copy()
    env.update({
        "RQ7_AUTOSPEC_ROOT": str(AUTOSPEC),
        "RQ7_API_KEY": key,
        "RQ7_BASE_URL": "https://api.openlux.ai/v1",
        "ROOT_DIR": str(AUTOSPEC),
        "LLVM_COMPILER": "clang",
        "VERI_LIB_PATH": str(AUTOSPEC / "llvm"),
        "ASAN_OPTIONS": "detect_leaks=0",
        "PYTHONPATH": str(AUTOSPEC),
        "LD_LIBRARY_PATH": str(AUTOSPEC / "clang+llvm/lib"),
    })
    env["PATH"] = ":".join([
        "/home/yangfp/.opam/frama-c.27.1/bin",
        str(AUTOSPEC / "clang+llvm/bin"),
        str(AUTOSPEC / "llvm/bin"),
        env.get("PATH", ""),
    ])
    return env


def run_case(case_id, key):
    target = OUT / str(case_id)
    summary_file = target / "summary.json"
    if target.exists():
        old = json.loads(summary_file.read_text()) if summary_file.is_file() else None
        if old and old.get("complete") and old.get("tokens", 0) > 0:
            return case_id, "already_complete", old
        archive_number = 1
        while (OUT / f"{case_id}_incomplete_{archive_number}").exists():
            archive_number += 1
        target.rename(OUT / f"{case_id}_incomplete_{archive_number}")
    stem, source = source_for(case_id)
    target.mkdir(parents=True, exist_ok=True)
    input_file = target / "input" / f"{stem}.c"
    input_file.parent.mkdir(exist_ok=True)
    shutil.copy2(source, input_file)
    env = child_env(key)
    steps = []
    begin = time.monotonic()
    valid = False
    complete = True
    for index in range(1, min(MAX_STEPS, original_calls(case_id)) + 1):
        remaining = MAX_SECONDS - (time.monotonic() - begin)
        if remaining <= 1:
            complete = False
            break
        step_dir = target / "steps" / f"step_{index:03d}"
        step_dir.mkdir(parents=True, exist_ok=True)
        command = [str(PYTHON), str(WRAPPER), "-f", str(input_file),
                   "-t", "0", "-o", str(step_dir), "-m", MODEL]
        step_start = time.monotonic()
        for retry in range(3):
            try:
                result = subprocess.run(command, cwd=AUTOSPEC, env=env,
                                        capture_output=True, text=True,
                                        timeout=max(1, int(remaining)))
                code = result.returncode
                log = result.stdout + "\n" + result.stderr
            except subprocess.TimeoutExpired as error:
                code = 124
                stdout = error.stdout.decode(errors="replace") if isinstance(error.stdout, bytes) else (error.stdout or "")
                stderr = error.stderr.decode(errors="replace") if isinstance(error.stderr, bytes) else (error.stderr or "")
                log = stdout + "\n" + stderr + "\n[TIMEOUT]"
            log = log.replace(key, "[redacted]")
            if "The upstream stream ended before the response was complete" not in log:
                break
            (target / f"step_{index:03d}_stream_retry_{retry + 1}.log").write_text(log)
            if time.monotonic() - begin >= MAX_SECONDS - 5:
                break
        (target / f"step_{index:03d}.log").write_text(log)
        token_match = TOKENS.findall(log)
        ret_match = RETURN.findall(log)
        if token_match:
            token_count = int(token_match[-1])
        else:
            usage = [json.loads(value) for value in USAGE.findall(log)]
            logged = LOGGED_TOKENS.findall(log)
            token_count = (sum(int(value["total_tokens"]) for value in usage)
                           if usage else sum(map(int, logged)) if logged else None)
        step_valid = bool(ret_match and ret_match[-1] == "True")
        steps.append({"step": index, "seconds": time.monotonic() - step_start,
                      "tokens": token_count, "returncode": code,
                      "valid_pass": step_valid})
        (target / "progress.json").write_text(json.dumps(steps, indent=2) + "\n")
        if token_count is None or token_count <= 0:
            complete = False
            break
        if code != 0:
            break
        if step_valid:
            valid = True
            break
    seconds = time.monotonic() - begin
    summary = {"case_id": case_id, "model": MODEL, "complete": complete,
               "valid_pass": valid, "seconds": seconds,
               "tokens": sum(step["tokens"] or 0 for step in steps),
               "api_calls": len(steps), "steps": steps,
               "source": str(source), "input": str(input_file)}
    summary_file.write_text(json.dumps(summary, indent=2) + "\n")
    return case_id, "complete" if complete else "incomplete", summary


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--workers", type=int, default=6)
    parser.add_argument("--cases", type=int, nargs="*")
    args = parser.parse_args()
    key = os.environ.get("OPENAI_API_KEY")
    if not key:
        raise RuntimeError("OPENAI_API_KEY must be supplied through the environment")
    summary = json.loads((DATA / "rq7_cost/reanalysis/summary.json").read_text())
    cases = args.cases if args.cases is not None else summary["methods"]["AutoSpec"]["token_missing_case_ids"]
    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        futures = {pool.submit(run_case, case_id, key): case_id for case_id in cases}
        for future in as_completed(futures):
            case_id, status, result = future.result()
            print(json.dumps({"case_id": case_id, "status": status,
                              "seconds": round(result["seconds"], 1),
                              "tokens": result["tokens"],
                              "api_calls": result["api_calls"]}), flush=True)


if __name__ == "__main__":
    main()
