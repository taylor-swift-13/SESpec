from __future__ import annotations

import glob
from pathlib import Path
import subprocess

from represent.api.client import project_env
from represent.api.config import get_settings
from represent.runners.common import ensure_dirs, parse_specgen_usage, parse_specgen_validity, run_command, write_json


def run_specgen(model: str, *, benchmark_relpath: str = "benchmark/SVCOMP/Addition/Addition.java") -> dict:
    ensure_dirs()
    settings = get_settings()
    repo_root = Path(settings.paths["specgen_root"])
    result_dir = Path(settings.paths["sespec_root"]) / "represent" / "results" / "smoke" / "specgen" / model
    usage_log = result_dir / "usage.jsonl"
    key_file = result_dir / "api_key.txt"
    key_file.parent.mkdir(parents=True, exist_ok=True)
    key_file.write_text(settings.api_key, encoding="utf-8")
    openjml_link = repo_root / "openjml"
    if openjml_link.exists() or openjml_link.is_symlink():
        if openjml_link.is_symlink() and openjml_link.resolve() == Path("/home/yangfp/CAV-JAVA/.tools/openjml/current"):
            pass
        else:
            if openjml_link.is_symlink() or openjml_link.is_file():
                openjml_link.unlink()
    if not openjml_link.exists():
        subprocess.run(
            ["ln", "-sfn", "/home/yangfp/CAV-JAVA/.tools/openjml/current", str(openjml_link)],
            check=True,
        )
    before_logs = set(glob.glob(str(repo_root / "logs" / "log-*.txt")))
    command = [
        "conda",
        "run",
        "--no-capture-output",
        "-n",
        settings.env_name,
        "python",
        "specgen.py",
        "--input",
        benchmark_relpath,
        "--key_file",
        str(key_file),
        "--max_iterations",
        "1",
    ]
    env = project_env(
        {
            "REPRESENT_SPECGEN_MODEL": model,
            "REPRESENT_USAGE_LOG": str(usage_log),
            "PYTHONPATH": str(Path(settings.paths["sespec_root"])),
        }
    )
    result = run_command(command, cwd=repo_root, env=env, log_path=result_dir / "command.log")
    after_logs = sorted(set(glob.glob(str(repo_root / "logs" / "log-*.txt"))) - before_logs)
    metrics = parse_specgen_usage(usage_log)
    validity = parse_specgen_validity(result_dir / "command.log")
    summary = {
        "project": "specgen",
        "model": model,
        "benchmark": benchmark_relpath,
        "returncode": result.returncode,
        "command": result.command,
        "log_path": after_logs[-1] if after_logs else "",
        "success": validity.get("valid_pass", False),
        "valid_pass": validity.get("valid_pass", False),
        "total_seconds": result.seconds,
        **metrics,
    }
    write_json(result_dir / "summary.json", summary)
    return summary
