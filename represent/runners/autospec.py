from __future__ import annotations

import json
import os
from pathlib import Path
import shutil
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


DEFAULT_AUTOSPEC_STALL_SECONDS = 1800
DEFAULT_AUTOSPEC_POLL_SECONDS = 5
DEFAULT_AUTOSPEC_TERMINAL_GRACE_SECONDS = 60
DEFAULT_AUTOSPEC_MAX_SECONDS = 7200


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


def _reset_output_dir(path: Path) -> None:
    if path.exists():
        shutil.rmtree(path)
    path.mkdir(parents=True, exist_ok=True)


def _reset_benchmark_state(gpt_file: Path) -> None:
    stale_paths = [
        gpt_file.with_name(f"{gpt_file.stem}_infilled{gpt_file.suffix}"),
        gpt_file.with_name(f"{gpt_file.stem}_marked{gpt_file.suffix}"),
        Path(f"{gpt_file}.pickle"),
    ]
    for stale_path in stale_paths:
        if stale_path.exists():
            if stale_path.is_dir():
                shutil.rmtree(stale_path)
            else:
                stale_path.unlink()


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


def _terminate_process_group(proc: subprocess.Popen[str]) -> None:
    try:
        os.killpg(proc.pid, signal.SIGTERM)
        time.sleep(1)
        if proc.poll() is None:
            os.killpg(proc.pid, signal.SIGKILL)
    except ProcessLookupError:
        pass


def _run_autospec_monitored(
    command: list[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path,
    watch_dir: Path,
    stall_seconds: int,
    poll_seconds: int,
    terminal_grace_seconds: int,
    max_seconds: int,
) -> tuple[object, dict[str, object]]:
    start = time.perf_counter()
    log_path.parent.mkdir(parents=True, exist_ok=True)
    stdout_path = log_path.with_suffix(log_path.suffix + ".stdout.tmp")
    stderr_path = log_path.with_suffix(log_path.suffix + ".stderr.tmp")
    terminal_seen_at: float | None = None
    terminal_result_seen = False
    killed_reason = ""

    with stdout_path.open("w+", encoding="utf-8") as stdout_handle, stderr_path.open(
        "w+", encoding="utf-8"
    ) as stderr_handle:
        proc = subprocess.Popen(
            command,
            cwd=str(cwd),
            env=env,
            text=True,
            stdout=stdout_handle,
            stderr=stderr_handle,
            start_new_session=True,
        )
        last_update = _latest_update_time(watch_dir)

        while True:
            if proc.poll() is not None:
                break
            now = time.time()
            latest_update = _latest_update_time(watch_dir)
            if latest_update > last_update:
                last_update = latest_update
            terminal_result_seen = _has_terminal_autospec_result(watch_dir)
            if terminal_result_seen and terminal_seen_at is None:
                terminal_seen_at = now
            if not terminal_result_seen and now - last_update > stall_seconds:
                killed_reason = f"no output updates for {stall_seconds} seconds"
                _terminate_process_group(proc)
                break
            if terminal_seen_at is not None and now - terminal_seen_at > terminal_grace_seconds:
                killed_reason = f"process did not exit within {terminal_grace_seconds} seconds after terminal result"
                _terminate_process_group(proc)
                break
            if max_seconds > 0 and time.perf_counter() - start > max_seconds:
                killed_reason = f"runtime exceeded {max_seconds} seconds"
                _terminate_process_group(proc)
                break
            time.sleep(poll_seconds)

        proc.wait()
        stdout_handle.flush()
        stderr_handle.flush()
        stdout_handle.seek(0)
        stderr_handle.seek(0)
        stdout = stdout_handle.read()
        stderr = stderr_handle.read()

    stdout_path.unlink(missing_ok=True)
    stderr_path.unlink(missing_ok=True)
    seconds = time.perf_counter() - start
    monitor_note = ""
    if killed_reason:
        monitor_note = f"\n\n[monitor]\nKilled because {killed_reason}."
    log_path.write_text(
        f"$ {' '.join(command)}\n\n[stdout]\n{stdout}\n\n[stderr]\n{stderr}{monitor_note}",
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
        "killed_for_stall": killed_reason.startswith("no output updates"),
        "killed_after_terminal_result": killed_reason.startswith("process did not exit"),
        "killed_for_max_runtime": killed_reason.startswith("runtime exceeded"),
        "killed_reason": killed_reason,
        "stall_seconds": stall_seconds,
        "max_seconds": max_seconds,
        "poll_seconds": poll_seconds,
        "terminal_grace_seconds": terminal_grace_seconds,
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
        Path(settings.paths["project_root"])
        / "represent"
        / "results"
        / "smoke"
        / "autospec"
        / mode
        / model
        / benchmark_name
    )
    output_dir = result_dir / "autospec_out"
    _reset_output_dir(output_dir)
    gpt_file = repo_root / benchmark_relpath
    _reset_benchmark_state(gpt_file)
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
    terminal_grace_seconds = int(
        os.environ.get("REPRESENT_AUTOSPEC_TERMINAL_GRACE_SECONDS", DEFAULT_AUTOSPEC_TERMINAL_GRACE_SECONDS)
    )
    max_seconds = int(os.environ.get("REPRESENT_AUTOSPEC_MAX_SECONDS", DEFAULT_AUTOSPEC_MAX_SECONDS))
    result, monitor = _run_autospec_monitored(
        command,
        cwd=repo_root,
        env=env,
        log_path=result_dir / "command.log",
        watch_dir=output_dir,
        stall_seconds=stall_seconds,
        poll_seconds=poll_seconds,
        terminal_grace_seconds=terminal_grace_seconds,
        max_seconds=max_seconds,
    )
    final_result = parse_autospec_final_result(output_dir / "final_result")
    valid_result = parse_autospec_valid_goals(output_dir)
    json_line = {}
    for line in reversed(result.stdout.splitlines()):
        line = line.strip()
        if not (line.startswith("{") and line.endswith("}")):
            continue
        try:
            parsed = json.loads(line)
        except json.JSONDecodeError:
            continue
        if isinstance(parsed, dict):
            json_line = parsed
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
