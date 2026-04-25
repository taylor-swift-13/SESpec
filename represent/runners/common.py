from __future__ import annotations

import ast
import csv
import json
import os
import re
import signal
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from represent.api.config import get_settings


ROOT = Path(__file__).resolve().parents[2]
REPRESENT_ROOT = ROOT / "represent"
RESULTS_ROOT = REPRESENT_ROOT / "results"
TMP_ROOT = RESULTS_ROOT / "tmp"


@dataclass
class CommandResult:
    command: list[str]
    returncode: int
    seconds: float
    stdout: str
    stderr: str


def ensure_dirs() -> None:
    for path in [RESULTS_ROOT, TMP_ROOT, REPRESENT_ROOT / "bench"]:
        path.mkdir(parents=True, exist_ok=True)


def conda_prefix() -> list[str]:
    env_name = get_settings().env_name
    return ["conda", "run", "--no-capture-output", "-n", env_name]


def run_command(
    command: list[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path,
    timeout_seconds: int | None = None,
) -> CommandResult:
    start = time.perf_counter()
    proc = subprocess.Popen(
        command,
        cwd=str(cwd),
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        start_new_session=True,
    )
    timed_out = False
    try:
        stdout, stderr = proc.communicate(timeout=timeout_seconds)
    except subprocess.TimeoutExpired:
        timed_out = True
        try:
            os.killpg(proc.pid, signal.SIGTERM)
            time.sleep(1)
            if proc.poll() is None:
                os.killpg(proc.pid, signal.SIGKILL)
        except ProcessLookupError:
            pass
        stdout, stderr = proc.communicate()
    seconds = time.perf_counter() - start
    log_path.parent.mkdir(parents=True, exist_ok=True)
    timeout_note = f"\n\n[monitor]\nKilled after {timeout_seconds} seconds." if timed_out else ""
    log_path.write_text(
        f"$ {' '.join(command)}\n\n[stdout]\n{stdout}\n\n[stderr]\n{stderr}{timeout_note}",
        encoding="utf-8",
    )
    return CommandResult(command, proc.returncode if proc.returncode is not None else -9, seconds, stdout, stderr)


def write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2, ensure_ascii=False), encoding="utf-8")


def framac_supports_file(c_path: Path, *, timeout_seconds: int = 8) -> tuple[bool, str]:
    try:
        result = subprocess.run(
            ["opam", "exec", "--switch=frama-c.27.1", "--", "frama-c", "-print", str(c_path)],
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired:
        return False, f"Frama-C timeout after {timeout_seconds}s"
    message = (result.stderr or result.stdout).strip()
    return result.returncode == 0, message


def c_benchmark_supported(c_path: Path, *, timeout_seconds: int = 8) -> tuple[bool, str]:
    if not c_path.exists():
        return False, f"Missing benchmark file: {c_path}"
    text = c_path.read_text(encoding="utf-8", errors="ignore")
    unsupported_markers = [
        "unsupported_translation",
        "unsupported method omitted",
        "/* unsupported ",
    ]
    for marker in unsupported_markers:
        if marker in text:
            return False, f"Unsupported translation marker: {marker}"
    return framac_supports_file(c_path, timeout_seconds=timeout_seconds)


def parse_autospec_final_result(final_result_path: Path) -> dict[str, Any]:
    if not final_result_path.exists():
        return {
            "success": False,
            "status": None,
            "tokens_usage": 0,
            "llms_query_times": "",
            "total_solve_time": "",
            "llms_query_seconds": 0.0,
            "total_solve_seconds": 0.0,
        }
    content = final_result_path.read_text(encoding="utf-8", errors="ignore")
    lines = content.splitlines()

    def parse_timedelta(field: str) -> tuple[str, float]:
        match = re.search(rf"'{field}':\s*datetime\.timedelta\(([^)]*)\)", content)
        if not match:
            return "", 0.0
        args = match.group(1).strip()
        if not args:
            return "0:00:00", 0.0
        days = 0
        seconds = 0
        microseconds = 0
        for part in [item.strip() for item in args.split(",") if item.strip()]:
            if "=" not in part:
                try:
                    days = int(part)
                except ValueError:
                    pass
                continue
            key, value = [item.strip() for item in part.split("=", 1)]
            try:
                ivalue = int(value)
            except ValueError:
                continue
            if key == "days":
                days = ivalue
            elif key == "seconds":
                seconds = ivalue
            elif key == "microseconds":
                microseconds = ivalue
        total_seconds = days * 86400 + seconds + microseconds / 1_000_000
        return f"{days} day, {seconds}s, {microseconds}us" if days else f"{seconds}.{microseconds:06d}s", total_seconds

    status_match = re.search(r"'Status':\s*(\d+)", content)
    tokens_match = re.search(r"'tokens_usage':\s*(\d+)", content)
    llm_text, llm_seconds = parse_timedelta("llms_query_times")
    solve_text, solve_seconds = parse_timedelta("total_solve_time")
    status = int(status_match.group(1)) if status_match else None
    return {
        "success": bool(lines and lines[0].strip() == "Pass"),
        "status": status,
        "tokens_usage": int(tokens_match.group(1)) if tokens_match else 0,
        "llms_query_times": llm_text,
        "total_solve_time": solve_text,
        "llms_query_seconds": llm_seconds,
        "total_solve_seconds": solve_seconds,
    }


def parse_autospec_valid_goals(output_dir: Path) -> dict[str, Any]:
    txt_files = sorted(output_dir.glob("*.txt"))
    if not txt_files:
        return {
            "valid_pass": False,
            "checked_goal_count": 0,
            "valid_goal_count": 0,
            "latest_txt_file": "",
        }

    latest = txt_files[-1]
    content = latest.read_text(encoding="utf-8", errors="ignore")
    if "[kernel] Frama-C aborted:" in content or "[kernel:annot-error]" in content:
        return {
            "valid_pass": False,
            "checked_goal_count": 0,
            "valid_goal_count": 0,
            "latest_txt_file": str(latest),
        }

    goals = []
    current_goal = None
    current_lines: list[str] = []
    for line in content.splitlines():
        if line.startswith("Goal "):
            if current_goal is not None:
                goals.append((current_goal, "\n".join(current_lines)))
            current_goal = line.strip()
            current_lines = [line]
        elif current_goal is not None:
            current_lines.append(line)
    if current_goal is not None:
        goals.append((current_goal, "\n".join(current_lines)))

    filtered = [
        (name, block)
        for name, block in goals
        if "Goal Assertion" not in name and "Loop variant" not in name
    ]
    valid_count = 0
    for _, block in filtered:
        if re.search(r"returns\s+Valid\b", block):
            valid_count += 1
    valid_pass = bool(filtered) and valid_count == len(filtered)
    return {
        "valid_pass": valid_pass,
        "checked_goal_count": len(filtered),
        "valid_goal_count": valid_count,
        "latest_txt_file": str(latest),
    }


def parse_specgen_usage(usage_path: Path) -> dict[str, int]:
    prompt = 0
    completion = 0
    total = 0
    if usage_path.exists():
        for line in usage_path.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            item = json.loads(line)
            prompt += int(item.get("prompt_tokens", 0))
            completion += int(item.get("completion_tokens", 0))
            total += int(item.get("total_tokens", 0))
    return {
        "prompt_tokens": prompt,
        "completion_tokens": completion,
        "total_tokens": total,
    }


def parse_specgen_validity(command_log: Path) -> dict[str, Any]:
    content = command_log.read_text(encoding="utf-8", errors="ignore") if command_log.exists() else ""
    syntax_error_markers = [
        "error:",
        "Exception in thread",
        "jml: error",
        "ParseException",
        "cannot find symbol",
    ]
    lowered = content.lower()
    syntax_ok = not any(marker.lower() in lowered for marker in syntax_error_markers)
    return {
        "valid_pass": syntax_ok,
        "syntax_ok": syntax_ok,
    }


def parse_frama_c_wp_output(stdout: str, stderr: str = "") -> dict[str, Any]:
    content = f"{stdout}\n{stderr}"
    if "[kernel] Frama-C aborted:" in content or "[kernel:annot-error]" in content:
        return {
            "valid_pass": False,
            "checked_goal_count": 0,
            "valid_goal_count": 0,
        }
    goals = []
    current_goal = None
    current_lines: list[str] = []
    for line in stdout.splitlines():
        if line.startswith("Goal "):
            if current_goal is not None:
                goals.append((current_goal, "\n".join(current_lines)))
            current_goal = line.strip()
            current_lines = [line]
        elif current_goal is not None:
            current_lines.append(line)
    if current_goal is not None:
        goals.append((current_goal, "\n".join(current_lines)))

    filtered = [
        (name, block)
        for name, block in goals
        if "Goal Assertion" not in name and "Loop variant" not in name
    ]
    valid_count = sum(1 for _, block in filtered if re.search(r"returns\s+Valid\b", block))
    return {
        "valid_pass": bool(filtered) and valid_count == len(filtered),
        "checked_goal_count": len(filtered),
        "valid_goal_count": valid_count,
    }


def write_mapping(rows: list[tuple[str, str, str, str, str]], mapping_path: Path) -> None:
    mapping_path.parent.mkdir(parents=True, exist_ok=True)
    with mapping_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, delimiter="\t")
        writer.writerow(["id", "source_repo", "source_path", "translated_c_path", "function_name"])
        writer.writerows(rows)
