from __future__ import annotations

import json
from pathlib import Path

from represent.api.client import project_env
from represent.api.config import get_settings
from represent.runners.common import (
    TMP_ROOT,
    c_benchmark_supported,
    ensure_dirs,
    parse_sespec_metrics,
    run_command,
    write_json,
)


def _apply_sespec_preset(base_config: dict, preset: str) -> None:
    main = base_config["main"]
    if preset == "default":
        main["use_symbolic_execution"] = True
    elif preset == "no_repair":
        main["refine_count"] = 0
        main["use_symbolic_execution"] = True
    elif preset == "no_se_no_repair":
        main["refine_count"] = 0
        main["use_symbolic_execution"] = False
    elif preset == "bare_prompt":
        main["pass_count"] = 1
        main["refine_count"] = 0
        main["use_db"] = False
        main["template"] = False
        main["think"] = False
        main["use_symbolic_execution"] = False
    else:
        raise ValueError(f"Unknown SESpec preset: {preset}")


def run_sespec(
    model: str,
    *,
    root_dir: str = "motivation_example",
    function_name: str = "foo",
    preset: str = "default",
    loop_mode: bool = False,
) -> dict:
    ensure_dirs()
    settings = get_settings()
    repo_root = Path(settings.paths["sespec_root"])
    src_root = repo_root / "src"
    source_file = src_root / "input" / root_dir / f"{function_name}.c"
    result_dir = repo_root / "represent" / "results" / "smoke" / "sespec" / preset / model
    supported, support_message = c_benchmark_supported(source_file)
    if not supported:
        summary = {
            "project": "sespec",
            "preset": preset,
            "model": model,
            "root_dir": root_dir,
            "function_name": function_name,
            "source_path": str(source_file),
            "skipped": True,
            "skip_reason": support_message,
            "valid_pass": False,
            "syntax_ok": False,
            "total_seconds": 0.0,
            "prompt_tokens": 0,
            "completion_tokens": 0,
            "total_tokens": 0,
            "call_count": 0,
        }
        write_json(result_dir / "summary.json", summary)
        return summary
    temp_config = TMP_ROOT / f"sespec_{preset}_{root_dir}_{function_name}_{model}.json"
    base_config = json.loads((src_root / "configs" / "func_config.json").read_text(encoding="utf-8"))
    base_config["main"]["root_dir"] = root_dir
    base_config["main"]["function_name"] = function_name
    _apply_sespec_preset(base_config, preset)
    if loop_mode:
        base_config["main"]["only_loop"] = True
    base_config["llm"]["api_model"] = model
    base_config["llm"]["base_url"] = settings.base_url
    base_config["llm"]["api_key"] = settings.api_key
    base_config["llm"]["api_temperature"] = settings.temperature
    base_config["llm"]["api_top_p"] = settings.top_p
    temp_config.write_text(json.dumps(base_config, indent=2), encoding="utf-8")

    command = [
        "conda",
        "run",
        "--no-capture-output",
        "-n",
        settings.env_name,
        "python",
        "main.py",
        "--config",
        str(temp_config),
    ]
    env = project_env(
        {
            "PATH": f"/home/yangfp/.opam/frama-c.27.1/bin:{project_env().get('PATH', '')}",
        }
    )
    log_path = result_dir / "command.log"
    result = run_command(command, cwd=src_root, env=env, log_path=log_path)
    sespec_log = src_root / "log" / root_dir / model / f"{function_name}.log"
    metrics = parse_sespec_metrics(sespec_log, result.stdout, result.seconds)
    summary = {
        "project": "sespec",
        "preset": preset,
        "loop_mode": loop_mode,
        "model": model,
        "root_dir": root_dir,
        "function_name": function_name,
        "returncode": result.returncode,
        "command": result.command,
        "log_path": str(sespec_log),
        **metrics,
    }
    write_json(result_dir / "summary.json", summary)
    return summary
