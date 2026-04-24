from __future__ import annotations

import ast
import csv
import json
import re
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
) -> CommandResult:
    start = time.perf_counter()
    proc = subprocess.run(
        command,
        cwd=str(cwd),
        env=env,
        text=True,
        capture_output=True,
    )
    seconds = time.perf_counter() - start
    log_path.parent.mkdir(parents=True, exist_ok=True)
    log_path.write_text(
        f"$ {' '.join(command)}\n\n[stdout]\n{proc.stdout}\n\n[stderr]\n{proc.stderr}",
        encoding="utf-8",
    )
    return CommandResult(command, proc.returncode, seconds, proc.stdout, proc.stderr)


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


def parse_sespec_metrics(log_path: Path, stdout: str, run_seconds: float) -> dict[str, Any]:
    content = log_path.read_text(encoding="utf-8") if log_path.exists() else ""

    def grab(pattern: str) -> int:
        match = re.search(pattern, content)
        return int(match.group(1).replace(",", "")) if match else 0

    def grab_bool_list(section_name: str) -> list[bool]:
        pattern = rf"{re.escape(section_name)}:\s*\n(\[[^\]]*\])"
        match = re.search(pattern, content)
        if not match:
            return []
        raw = match.group(1).strip()[1:-1].strip()
        if not raw:
            return []
        return [item.strip() == "True" for item in raw.split(",")]

    time_match = re.search(r"Total execution time:\s*([0-9.]+)\s*seconds", content)
    seconds = float(time_match.group(1)) if time_match else run_seconds
    syntax_ok = "Syntax Error:\nsyntax Correct" in content or "syntax Correct" in content
    loop_results = grab_bool_list("Loop Invariant")
    post_results = grab_bool_list("Post Condition")
    instance_results = grab_bool_list("Instance")
    valid_groups = []
    if loop_results:
        valid_groups.append(all(loop_results))
    if post_results:
        valid_groups.append(all(post_results))
    if instance_results:
        valid_groups.append(all(instance_results))
    valid_pass = syntax_ok and all(valid_groups) if valid_groups else syntax_ok
    return {
        "success": valid_pass,
        "valid_pass": valid_pass,
        "syntax_ok": syntax_ok,
        "total_seconds": seconds,
        "prompt_tokens": grab(r"Total prompt tokens \(input\):\s*([0-9,]+)"),
        "completion_tokens": grab(r"Total completion tokens \(output\):\s*([0-9,]+)"),
        "total_tokens": grab(r"Total tokens:\s*([0-9,]+)"),
        "call_count": grab(r"Total API calls:\s*([0-9,]+)"),
    }


def parse_autospec_final_result(final_result_path: Path) -> dict[str, Any]:
    if not final_result_path.exists():
        return {"success": False}
    lines = final_result_path.read_text(encoding="utf-8").splitlines()
    payload = ast.literal_eval(lines[-1]) if lines else {}
    status = payload.get("Status")
    return {
        "success": status == 0,
        "status": status,
        "tokens_usage": int(payload.get("tokens_usage", 0)),
        "llms_query_times": str(payload.get("llms_query_times", "")),
        "total_solve_time": str(payload.get("total_solve_time", "")),
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

    filtered = [(name, block) for name, block in goals if "Goal Assertion" not in name]
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

    filtered = [(name, block) for name, block in goals if "Goal Assertion" not in name]
    valid_count = sum(1 for _, block in filtered if re.search(r"returns\s+Valid\b", block))
    return {
        "valid_pass": bool(filtered) and valid_count == len(filtered),
        "checked_goal_count": len(filtered),
        "valid_goal_count": valid_count,
    }


def write_mapping(rows: list[tuple[str, str, str, str]], mapping_path: Path) -> None:
    mapping_path.parent.mkdir(parents=True, exist_ok=True)
    with mapping_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle, delimiter="\t")
        writer.writerow(["id", "source_repo", "source_path", "translated_c_path"])
        writer.writerows(rows)
