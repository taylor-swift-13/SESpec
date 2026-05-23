#!/usr/bin/env python3
"""Run SpecGen on all 400 SESpec benchmark cases with gpt-5 (after naming bug fix).

For each sespec_id:
  - 352 cases mapped via arc_mapping.csv → /home/yangfp/Arc/represent/bench/java_flat/<arc_stem>.java
  - 48 cases via extra_java_mapping.csv → /home/yangfp/Arc/represent/bench/java_flat_extra/<class>.java

Output layout:
  RESULTS/paper_data/sespec_400_gpt5/specgen_full400/gpt-5/<case_id>/
    summary.json
    command.log                # specgen.py stdout/stderr
    log-<classname>-<ts>.txt   # SpecGen's iteration log (copied from external/logs)
    candidate.java             # input Java
"""
from __future__ import annotations

import csv
import json
import os
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path


def specgen_valid_pass(command_log_path: Path) -> bool:
    """Authoritative SpecGen verdict: specgen.py prints 'OpenJML verification: PASS'
    iff the final validate_openjml() returned an empty stderr (i.e. OpenJML reported
    NO errors AND NO warnings of any kind — strictly stricter than just checking
    for 'error:' / 'Exception' markers).
    """
    if not command_log_path.exists():
        return False
    text = command_log_path.read_text(encoding="utf-8", errors="ignore")
    return "OpenJML verification: PASS" in text

REPO_ROOT = Path(__file__).resolve().parents[2]
PD = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5"
ARC_MAPPING = PD / "arc_mapping.csv"
EXTRA_MAPPING = PD / "extra_java_mapping.csv"
OUT_ROOT = PD / "specgen_full400" / "gpt-5"
SPECGEN_DIR = Path("/home/yangfp/Arc/represent/external/specgen-artifact")
SPECGEN_LOGS = SPECGEN_DIR / "logs"
JAVA_FLAT = Path("/home/yangfp/Arc/represent/bench/java_flat")
JAVA_EXTRA = Path("/home/yangfp/Arc/represent/bench/java_flat_extra")
KEY_FILE_DIR = Path("/tmp/specgen400_key")
TIMEOUT_SECONDS = 1800  # per case; 20-iter SpecGen can take up to ~25 min for hard cases
MAX_ITERATIONS = 20    # SpecGen paper default (matches 3-model runs whose max calls observed at 20)


def build_case_inputs() -> list[tuple[str, Path, str]]:
    """case_id → (case_id, java_path, classname)."""
    out = []
    seen = set()
    # 1. Mapped 352 via arc_mapping
    with ARC_MAPPING.open(encoding="utf-8") as f:
        for r in csv.DictReader(f):
            cid = r["sespec_new_id"]
            arc = r["arc_stem"]
            jp = JAVA_FLAT / f"{arc}.java"
            if not jp.exists():
                print(f"  WARN: arc_mapping references missing {jp}", file=sys.stderr)
                continue
            # Extract class name from file content
            content = jp.read_text(encoding="utf-8")
            import re as _re
            m = _re.search(r"\b(?:public\s+)?class\s+(\w+)", content)
            cls = m.group(1) if m else jp.stem
            out.append((cid, jp, cls))
            seen.add(cid)
    # 2. Extra 48 via extra_java_mapping
    if EXTRA_MAPPING.exists():
        with EXTRA_MAPPING.open(encoding="utf-8") as f:
            for r in csv.DictReader(f):
                cid = r["sespec_new_id"]
                if cid in seen:
                    continue
                jp = Path(r["java_path"])
                if not jp.exists():
                    print(f"  WARN: extra_mapping missing {jp}", file=sys.stderr)
                    continue
                cls = r["class_name"]
                out.append((cid, jp, cls))
                seen.add(cid)
    missing = sorted(set(str(i) for i in range(400)) - seen, key=int)
    if missing:
        print(f"  WARN: {len(missing)} cases have no Java source: {missing[:10]}…", file=sys.stderr)
    return sorted(out, key=lambda x: int(x[0]))


def run_one(case_id: str, java_path: Path, classname: str) -> dict:
    case_dir = OUT_ROOT / case_id
    case_dir.mkdir(parents=True, exist_ok=True)
    api_key = os.environ["OPENAI_API_KEY"]
    KEY_FILE_DIR.mkdir(parents=True, exist_ok=True)
    key_file = KEY_FILE_DIR / f"key_{case_id}.txt"
    key_file.write_text(api_key, encoding="utf-8")
    usage_log = case_dir / "usage.jsonl"
    env = os.environ.copy()
    env["REPRESENT_SPECGEN_MODEL"] = "gpt-5"
    env["REPRESENT_USAGE_LOG"] = str(usage_log)
    env["PYTHONPATH"] = "/home/yangfp/Arc"
    cmd = [
        "conda", "run", "--no-capture-output", "-n", "SpecAutoGen",
        "python", "specgen.py",
        "--input", str(java_path),
        "--key_file", str(key_file),
        "--max_iterations", str(MAX_ITERATIONS),
    ]
    t0 = time.time()
    log_files_before = set(SPECGEN_LOGS.glob(f"log-{classname}-*.txt"))
    try:
        proc = subprocess.run(
            cmd, cwd=str(SPECGEN_DIR), env=env,
            capture_output=True, text=True, timeout=TIMEOUT_SECONDS,
        )
        rc = proc.returncode
        stdout, stderr = proc.stdout, proc.stderr
        timed_out = False
    except subprocess.TimeoutExpired as e:
        rc = -1
        stdout = e.stdout.decode() if isinstance(e.stdout, bytes) else (e.stdout or "")
        stderr = (e.stderr.decode() if isinstance(e.stderr, bytes) else (e.stderr or "")) + f"\n[TIMEOUT after {TIMEOUT_SECONDS}s]"
        timed_out = True
    elapsed = time.time() - t0

    # Write command.log
    (case_dir / "command.log").write_text(
        f"$ {' '.join(cmd)}\n\n[stdout]\n{stdout}\n\n[stderr]\n{stderr}\n",
        encoding="utf-8",
    )
    # Copy candidate Java input
    shutil.copy2(java_path, case_dir / "candidate.java")
    # Find newly created log file
    log_files_after = set(SPECGEN_LOGS.glob(f"log-{classname}-*.txt"))
    new_logs = sorted(log_files_after - log_files_before, key=lambda p: p.stat().st_mtime)
    log_path = new_logs[-1] if new_logs else None
    log_text = log_path.read_text(encoding="utf-8") if log_path else ""
    if log_path:
        shutil.copy2(log_path, case_dir / log_path.name)

    # Authoritative SpecGen verdict from command.log (see specgen_valid_pass above).
    valid_pass = specgen_valid_pass(case_dir / "command.log")

    summary = {
        "project": "specgen",
        "model": "gpt-5",
        "case_id": case_id,
        "java_input": str(java_path),
        "classname": classname,
        "returncode": rc,
        "timed_out": timed_out,
        "total_seconds": round(elapsed, 2),
        "log_path": str(log_path) if log_path else None,
        "valid_pass": valid_pass,
    }
    # Append token info from usage.jsonl if available
    if usage_log.exists():
        try:
            tokens_in = 0; tokens_out = 0; calls = 0
            for line in usage_log.read_text(encoding="utf-8").splitlines():
                if not line.strip():
                    continue
                j = json.loads(line)
                tokens_in += int(j.get("prompt_tokens", 0) or 0)
                tokens_out += int(j.get("completion_tokens", 0) or 0)
                calls += 1
            summary["prompt_tokens"] = tokens_in
            summary["completion_tokens"] = tokens_out
            summary["total_tokens"] = tokens_in + tokens_out
            summary["call_count"] = calls
        except (json.JSONDecodeError, ValueError):
            pass
    (case_dir / "summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    return summary


def _judge_valid(log_text: str) -> bool:
    """Mirror represent/runners/common.parse_specgen_validity heuristic.

    SpecGen writes alternating blocks: code / openjml-output. The run is judged
    valid when the LAST openjml output is empty (no error info)."""
    if not log_text:
        return False
    blocks = [b for b in log_text.split("==============================") if b.strip()]
    # blocks alternate: code, err, code, err, … last block is the err of the last iter
    if not blocks:
        return False
    last = blocks[-1].strip()
    # Valid means no errors. Errors typically include 'error', 'invalid', etc.
    if not last:
        return True
    # Check for absence of common error patterns
    lower = last.lower()
    if "error" in lower or "invalid" in lower or "warning" in lower:
        return False
    return True  # last block is non-empty but error-free


def main() -> int:
    if "OPENAI_API_KEY" not in os.environ:
        print("OPENAI_API_KEY not set", file=sys.stderr); return 1
    cases = build_case_inputs()
    print(f"Total cases to run: {len(cases)}")
    OUT_ROOT.mkdir(parents=True, exist_ok=True)
    workers = int(os.environ.get("WORKERS", "20"))
    print(f"Workers: {workers}")
    results = []
    t0 = time.time()
    with ThreadPoolExecutor(max_workers=workers) as ex:
        futures = {ex.submit(run_one, c, p, cls): c for c, p, cls in cases}
        for i, fut in enumerate(as_completed(futures), 1):
            try:
                s = fut.result()
                tag = "VALID" if s["valid_pass"] else ("TO" if s["timed_out"] else "fail")
                print(f"[{i:3d}/{len(cases)}] case {s['case_id']:>3s}  [{tag:>5s}]  "
                      f"{s['total_seconds']:6.1f}s")
                results.append(s)
            except Exception as e:
                print(f"[{i:3d}/{len(cases)}] CRASH: {e}")
    elapsed = time.time() - t0
    valid_n = sum(1 for r in results if r.get("valid_pass"))
    print(f"\nDone in {elapsed/60:.1f} min — {valid_n}/{len(results)} valid")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
