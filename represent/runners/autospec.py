from __future__ import annotations

import json
from pathlib import Path

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


def run_autospec(model: str, *, benchmark_relpath: str = "benchmark/fib_46_benchmark/01.c", one_shot: bool = False) -> dict:
    ensure_dirs()
    settings = get_settings()
    repo_root = Path(settings.paths["autospec_root"])
    mode = "one_shot" if one_shot else "default"
    result_dir = Path(settings.paths["sespec_root"]) / "represent" / "results" / "smoke" / "autospec" / mode / model
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
    env = project_env({"PYTHONPATH": f"{repo_root}:{Path(settings.paths['sespec_root'])}"})
    entry = "step.py" if one_shot else "fuzz.py"
    shell_cmd = (
        "source ./scripts/requires/init_env.sh >/dev/null 2>&1 && "
        "export PATH='/home/yangfp/.opam/frama-c.27.1/bin:$PATH' && "
        f"export PYTHONPATH='{repo_root}:{Path(settings.paths['sespec_root'])}:$PYTHONPATH' && "
        f"python3 {entry} -f '{gpt_file}' -t 0 -o '{output_dir}' -m '{model}'"
    )
    command = ["conda", "run", "--no-capture-output", "-n", settings.env_name, "bash", "-lc", shell_cmd]
    result = run_command(command, cwd=repo_root, env=env, log_path=result_dir / "command.log")
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
        "total_tokens": int(json_line.get("tokens_usage", final_result.get("tokens_usage", 0) or 0)),
    }
    write_json(result_dir / "summary.json", summary)
    return summary
