from __future__ import annotations

import json
from pathlib import Path
import re

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
    main["pass_count"] = 1
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
        main["template"] = False
        main["think"] = False
        main["use_symbolic_execution"] = False
    else:
        raise ValueError(f"Unknown SESpec preset: {preset}")


def _find_source_file(input_root: Path, requested_name: str) -> Path:
    direct = input_root / f"{requested_name}.c"
    if direct.exists():
        return direct
    c_files = sorted(input_root.glob("*.c"))
    if len(c_files) == 1:
        return c_files[0]
    raise FileNotFoundError(f"Cannot resolve source file for {requested_name} in {input_root}")


def _infer_c_function_name(source_file: Path, requested_name: str) -> str:
    text = source_file.read_text(encoding="utf-8", errors="ignore")
    pattern = re.compile(r"^\s*(?:int|void|char|float|double|long|short|unsigned|signed)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{", re.MULTILINE)
    names = [name for name in pattern.findall(text) if name != "unknown"]
    if requested_name in names:
        return requested_name
    lowered = requested_name[:1].lower() + requested_name[1:]
    if lowered in names:
        return lowered
    if names:
        return names[0]
    return requested_name


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
    input_root = src_root / "input" / root_dir
    source_file = _find_source_file(input_root, function_name)
    effective_function_name = _infer_c_function_name(source_file, function_name)
    result_dir = (
        repo_root
        / "represent"
        / "results"
        / "smoke"
        / "sespec"
        / preset
        / model
        / root_dir
        / effective_function_name
    )
    supported, support_message = c_benchmark_supported(source_file)
    if not supported:
        summary = {
            "project": "sespec",
            "preset": preset,
            "model": model,
            "root_dir": root_dir,
            "function_name": effective_function_name,
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
    base_config["main"]["function_name"] = effective_function_name
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
    sespec_log = src_root / "log" / root_dir / model / f"{effective_function_name}.log"
    metrics = parse_sespec_metrics(sespec_log, result.stdout, result.seconds)
    summary = {
        "project": "sespec",
        "preset": preset,
        "loop_mode": loop_mode,
        "model": model,
        "root_dir": root_dir,
        "function_name": effective_function_name,
        "returncode": result.returncode,
        "command": result.command,
        "log_path": str(sespec_log),
        **metrics,
    }
    write_json(result_dir / "summary.json", summary)
    return summary
