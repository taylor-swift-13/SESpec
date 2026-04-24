from __future__ import annotations

from pathlib import Path
import re

from represent.api.client import chat_completion, project_env
from represent.api.config import get_settings
from represent.runners.common import (
    ROOT,
    c_benchmark_supported,
    ensure_dirs,
    parse_frama_c_wp_output,
    run_command,
    write_json,
)


def _bare_prompt(language: str, source_code: str) -> str:
    if language == "c":
        return f"""Add ACSL specifications to the following C program.

Rules:
- Return only one complete C file.
- Keep the implementation unchanged.
- Add only ACSL specifications and annotations.
- Do not explain anything.

```c
{source_code}
```"""
    if language == "java":
        return f"""Add JML specifications to the following Java program.

Rules:
- Return only one complete Java file.
- Keep the implementation unchanged.
- Add only JML specifications and annotations.
- Do not explain anything.

```java
{source_code}
```"""
    raise ValueError(f"Unsupported language: {language}")


def _extract_code_block(text: str, language: str) -> str:
    fence = f"```{language}"
    if fence in text:
        tail = text.split(fence, 1)[1]
        if "```" in tail:
            return tail.split("```", 1)[0].strip() + "\n"
    if "```" in text:
        tail = text.split("```", 1)[1]
        if "```" in tail:
            return tail.split("```", 1)[0].strip() + "\n"
    return text.strip() + "\n"


def _java_public_type_name(source_code: str) -> str | None:
    match = re.search(r"\bpublic\s+(?:class|interface|enum)\s+([A-Za-z_][A-Za-z0-9_]*)", source_code)
    if match:
        return match.group(1)
    return None


def run_bare_model(model: str, *, source_path: str, language: str, benchmark_id: str) -> dict:
    ensure_dirs()
    settings = get_settings()
    result_dir = ROOT / "represent" / "results" / "smoke" / "bare_model" / language / model / benchmark_id
    usage_log = result_dir / "usage.jsonl"
    if language == "c":
        source_supported, source_message = c_benchmark_supported(Path(source_path))
        if not source_supported:
            summary = {
                "project": "bare_model",
                "preset": "one_shot",
                "model": model,
                "language": language,
                "benchmark_id": benchmark_id,
                "source_path": str(source_path),
                "skipped": True,
                "skip_reason": source_message,
                "valid_pass": False,
                "total_seconds": 0.0,
                "prompt_tokens": 0,
                "completion_tokens": 0,
                "total_tokens": 0,
            }
            write_json(result_dir / "summary.json", summary)
            return summary
    source = Path(source_path).read_text(encoding="utf-8", errors="ignore")
    response = chat_completion(
        messages=[
            {"role": "system", "content": "You are a formal specification generator."},
            {"role": "user", "content": _bare_prompt(language, source)},
        ],
        model=model,
        temperature=0.0,
        top_p=1.0,
        usage_log=usage_log,
    )
    candidate_source = _extract_code_block(response["content"], language)
    if language == "java":
        java_name = _java_public_type_name(candidate_source) or Path(source_path).stem or "Candidate"
        candidate_path = result_dir / f"{java_name}.java"
    else:
        candidate_path = result_dir / "candidate.c"
    candidate_path.parent.mkdir(parents=True, exist_ok=True)
    candidate_path.write_text(candidate_source, encoding="utf-8")

    if language == "c":
        supported, support_message = c_benchmark_supported(candidate_path)
        if not supported:
            summary = {
                "project": "bare_model",
                "preset": "one_shot",
                "model": model,
                "language": language,
                "benchmark_id": benchmark_id,
                "source_path": str(source_path),
                "candidate_path": str(candidate_path),
                "skipped": True,
                "skip_reason": support_message,
                "valid_pass": False,
                "total_seconds": 0.0,
                "prompt_tokens": int(response["usage"].get("prompt_tokens", 0)),
                "completion_tokens": int(response["usage"].get("completion_tokens", 0)),
                "total_tokens": int(response["usage"].get("total_tokens", 0)),
            }
            write_json(result_dir / "summary.json", summary)
            return summary
        command = [
            "opam",
            "exec",
            "--switch=frama-c.27.1",
            "--",
            "frama-c",
            "-wp",
            "-wp-print",
            "-wp-timeout",
            "10",
            "-wp-prover",
            "z3",
            "-wp-model",
            "Typed",
            str(candidate_path),
        ]
        result = run_command(command, cwd=ROOT, env=project_env(), log_path=result_dir / "command.log")
        validity = parse_frama_c_wp_output(result.stdout, result.stderr)
    else:
        openjml = settings.tools["openjml_cmd"][0]
        command = [openjml, "--esc", str(candidate_path)]
        result = run_command(command, cwd=ROOT, env=project_env(), log_path=result_dir / "command.log")
        validity = {"valid_pass": result.returncode == 0}

    summary = {
        "project": "bare_model",
        "preset": "one_shot",
        "model": model,
        "language": language,
        "benchmark_id": benchmark_id,
        "source_path": str(source_path),
        "candidate_path": str(candidate_path),
        "returncode": result.returncode,
        "valid_pass": validity.get("valid_pass", False),
        "total_seconds": result.seconds,
        "prompt_tokens": int(response["usage"].get("prompt_tokens", 0)),
        "completion_tokens": int(response["usage"].get("completion_tokens", 0)),
        "total_tokens": int(response["usage"].get("total_tokens", 0)),
        **validity,
    }
    write_json(result_dir / "summary.json", summary)
    return summary
