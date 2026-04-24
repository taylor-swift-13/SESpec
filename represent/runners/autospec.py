from __future__ import annotations

import json
import os
from pathlib import Path
import signal
import subprocess
import time

from represent.api.client import project_env
from represent.api.config import get_settings
from represent.runners.common import (
    c_benchmark_supported,
    ensure_dirs,
    parse_autospec_final_result,
    parse_autospec_valid_goals,
    run_command,
    write_json,
)


DEFAULT_AUTOSPEC_STALL_SECONDS = 120
DEFAULT_AUTOSPEC_POLL_SECONDS = 5


def _latest_update_time(path: Path) -> float:
    latest = path.stat().st_mtime if path.exists() else 0.0
    if path.exists():
        for child in path.rglob("*"):
            try:
                latest = max(latest, child.stat().st_mtime)
            except FileNotFoundError:
                continue
    return latest


def _count_output_files(path: Path) -> int:
    if not path.exists():
        return 0
    return sum(1 for child in path.rglob("*") if child.is_file())


def _has_terminal_autospec_result(path: Path) -> bool:
    if not path.exists():
        return False
    if (path / "final_result").exists():
        return True
    for child in path.glob("*_merged_Pass_*.txt"):
        if child.is_file():
            return True
    for child in path.glob("*_merged_Fail_*.txt"):
        if child.is_file():
            return True
    return False


def _run_autospec_monitored(
    command: list[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path,
    watch_dir: Path,
    stall_seconds: int,
    poll_seconds: int,
) -> tuple[object, dict[str, object]]:
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
    last_update = _latest_update_time(watch_dir)
    killed_for_stall = False

    while True:
        if proc.poll() is not None:
            break
        latest_update = _latest_update_time(watch_dir)
        if latest_update > last_update:
            last_update = latest_update
        terminal_result_seen = _has_terminal_autospec_result(watch_dir)
        if not terminal_result_seen and time.time() - last_update > stall_seconds:
            killed_for_stall = True
            try:
                os.killpg(proc.pid, signal.SIGTERM)
                time.sleep(1)
                if proc.poll() is None:
                    os.killpg(proc.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
            break
        time.sleep(poll_seconds)

    stdout, stderr = proc.communicate()
    seconds = time.perf_counter() - start
    log_path.parent.mkdir(parents=True, exist_ok=True)
    stall_note = ""
    if killed_for_stall:
        stall_note = f"\n\n[monitor]\nKilled due to no output updates for {stall_seconds} seconds."
    log_path.write_text(
        f"$ {' '.join(command)}\n\n[stdout]\n{stdout}\n\n[stderr]\n{stderr}{stall_note}",
        encoding="utf-8",
    )

    class Result:
        def __init__(self) -> None:
            self.command = command
            self.returncode = proc.returncode if proc.returncode is not None else -9
            self.seconds = seconds
            self.stdout = stdout
            self.stderr = stderr

    monitor = {
        "killed_for_stall": killed_for_stall,
        "stall_seconds": stall_seconds,
        "poll_seconds": poll_seconds,
        "output_file_count": _count_output_files(watch_dir),
        "last_output_update_epoch": last_update,
        "terminal_result_seen": _has_terminal_autospec_result(watch_dir),
    }
    return Result(), monitor


def run_autospec(model: str, *, benchmark_relpath: str = "benchmark/fib_46_benchmark/01.c", one_shot: bool = False) -> dict:
    ensure_dirs()
    settings = get_settings()
    repo_root = Path(settings.paths["autospec_root"])
    mode = "one_shot" if one_shot else "default"
    benchmark_name = Path(benchmark_relpath).stem
    result_dir = (
        Path(settings.paths["sespec_root"])
        / "represent"
        / "results"
        / "smoke"
        / "autospec"
        / mode
        / model
        / benchmark_name
    )
    output_dir = result_dir / "autospec_out"
    output_dir.mkdir(parents=True, exist_ok=True)
    gpt_file = repo_root / benchmark_relpath
    supported, support_message = c_benchmark_supported(gpt_file)
    if not supported:
        summary = {
            "project": "autospec",
            "preset": mode,
            "model": model,
            "benchmark": benchmark_relpath,
            "output_dir": str(output_dir),
            "skipped": True,
            "skip_reason": support_message,
            "valid_pass": False,
            "checked_goal_count": 0,
            "valid_goal_count": 0,
            "total_tokens": 0,
        }
        write_json(result_dir / "summary.json", summary)
        return summary
    env = project_env(
        {
            "PATH": f"/home/yangfp/.opam/frama-c.27.1/bin:{repo_root / 'clang+llvm' / 'bin'}:{repo_root / 'llvm' / 'bin'}:{project_env().get('PATH', '')}",
            "PYTHONPATH": str(repo_root),
            "ROOT_DIR": str(repo_root),
            "LLVM_COMPILER": "clang",
            "ASAN_OPTIONS": "detect_leaks=0",
            "VERI_LIB_PATH": str(repo_root / "llvm"),
            "LD_LIBRARY_PATH": str(repo_root / "clang+llvm" / "lib"),
        }
    )
    entry = "step.py" if one_shot else "fuzz.py"
    command = [
        "conda",
        "run",
        "--no-capture-output",
        "-n",
        settings.env_name,
        "python",
        entry,
        "-f",
        str(gpt_file),
        "-t",
        "0",
        "-o",
        str(output_dir),
        "-m",
        model,
    ]
    stall_seconds = int(os.environ.get("REPRESENT_AUTOSPEC_STALL_SECONDS", DEFAULT_AUTOSPEC_STALL_SECONDS))
    poll_seconds = int(os.environ.get("REPRESENT_AUTOSPEC_POLL_SECONDS", DEFAULT_AUTOSPEC_POLL_SECONDS))
    result, monitor = _run_autospec_monitored(
        command,
        cwd=repo_root,
        env=env,
        log_path=result_dir / "command.log",
        watch_dir=output_dir,
        stall_seconds=stall_seconds,
        poll_seconds=poll_seconds,
    )
    final_result = parse_autospec_final_result(output_dir / "final_result")
    valid_result = parse_autospec_valid_goals(output_dir)
    json_line = {}
    for line in reversed(result.stdout.splitlines()):
        line = line.strip()
        if line.startswith("{") and line.endswith("}"):
            json_line = json.loads(line)
            break
    summary = {
        "project": "autospec",
        "preset": mode,
        "model": model,
        "benchmark": benchmark_relpath,
        "returncode": result.returncode,
        "command": result.command,
        "output_dir": str(output_dir),
        "success": valid_result.get("valid_pass", False),
        "valid_pass": valid_result.get("valid_pass", False),
        "checked_goal_count": valid_result.get("checked_goal_count", 0),
        "valid_goal_count": valid_result.get("valid_goal_count", 0),
        "latest_txt_file": valid_result.get("latest_txt_file", ""),
        "llms_query_times": json_line.get("llms_query_times", final_result.get("llms_query_times", "")),
        "total_solve_time": json_line.get("total_solve_time", final_result.get("total_solve_time", "")),
        "llms_query_seconds": float(final_result.get("llms_query_seconds", 0.0) or 0.0),
        "total_solve_seconds": float(final_result.get("total_solve_seconds", 0.0) or 0.0),
        "total_seconds": float(final_result.get("total_solve_seconds", 0.0) or result.seconds),
        "total_tokens": int(json_line.get("tokens_usage", final_result.get("tokens_usage", 0) or 0)),
        **monitor,
    }
    write_json(result_dir / "summary.json", summary)
    return summary
