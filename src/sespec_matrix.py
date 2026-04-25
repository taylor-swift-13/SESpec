from __future__ import annotations

import argparse
import concurrent.futures
import csv
from datetime import datetime
import json
import os
import shutil
import signal
import subprocess
import time
import traceback
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from uuid import uuid4


SRC_ROOT = Path(__file__).resolve().parent
ROOT = SRC_ROOT.parent
INPUT_ROOT = SRC_ROOT / "input"
RESULTS_ROOT = SRC_ROOT / "results" / "matrix_runs"
TMP_ROOT = SRC_ROOT / "results" / "tmp"
DEFAULT_BENCHES = ["SV_COMP", "FormalBench", "SpecGenBench"]
DEFAULT_LABELS = [
    "sespec_default",
    "sespec_no_repair",
    "sespec_no_se_no_repair",
    "sespec_bare_prompt",
]
DEFAULT_MODEL_CONFIG = SRC_ROOT / "configs" / "matrix_models.yaml"


@dataclass
class CommandResult:
    command: list[str]
    returncode: int
    seconds: float
    stdout: str
    stderr: str


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the SESpec matrix experiment over src/input benches.")
    parser.add_argument(
        "--bench",
        "--group",
        dest="bench",
        nargs="*",
        default=["all"],
        help="Bench names under src/input. Use 'all' for SV_COMP, FormalBench, SpecGenBench.",
    )
    parser.add_argument("--limit", type=int, default=0, help="Run only the first N cases per bench.")
    parser.add_argument("--run-name", default=None, help="Output folder name. Defaults to YYYYMMDD_HHMMSS.")
    parser.add_argument("--models", nargs="*", default=None, help="Override model list.")
    parser.add_argument("--workers", type=int, default=max(1, min(4, os.cpu_count() or 1)))
    parser.add_argument("--labels", nargs="*", default=DEFAULT_LABELS, choices=DEFAULT_LABELS)
    parser.add_argument("--env-name", default=os.environ.get("SESPEC_CONDA_ENV", "SpecAutoGen"))
    parser.add_argument("--base-url", default=os.environ.get("OPENAI_BASE_URL") or os.environ.get("API_URL_BASE") or "https://yunwu.ai/v1")
    parser.add_argument("--temperature", type=float, default=float(os.environ.get("SESPEC_TEMPERATURE", "0.4")))
    parser.add_argument("--top-p", type=float, default=float(os.environ.get("SESPEC_TOP_P", "0.7")))
    parser.add_argument("--skip-support-check", action="store_true")
    return parser.parse_args()


def load_models() -> list[str]:
    env_models = os.environ.get("SESPEC_MATRIX_MODELS")
    if env_models:
        return [item.strip() for item in env_models.split(",") if item.strip()]
    if DEFAULT_MODEL_CONFIG.exists():
        models: list[str] = []
        in_models = False
        for line in DEFAULT_MODEL_CONFIG.read_text(encoding="utf-8").splitlines():
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue
            if stripped == "models:":
                in_models = True
                continue
            if in_models:
                if stripped.startswith("- "):
                    models.append(stripped[2:].strip())
                elif not line.startswith((" ", "\t")):
                    break
        if models:
            return models
    return ["gpt-4o"]


def resolve_benches(requested: list[str]) -> list[str]:
    if not requested or requested == ["all"] or "all" in requested:
        return DEFAULT_BENCHES
    return requested


def load_cases(bench: str) -> list[Path]:
    bench_dir = INPUT_ROOT / bench
    if not bench_dir.is_dir():
        raise FileNotFoundError(f"Missing input bench: {bench_dir}")
    cases = sorted(
        [path for path in bench_dir.glob("*.c") if path.stem.isdigit()],
        key=lambda path: int(path.stem),
    )
    if not cases:
        raise FileNotFoundError(f"No numbered .c cases under {bench_dir}")
    return cases


def function_name_for_case(case_path: Path) -> str:
    return f"foo{case_path.stem}"


def project_env(base_url: str, extra: dict[str, str] | None = None) -> dict[str, str]:
    env = os.environ.copy()
    env["API_URL_BASE"] = base_url
    env["OPENAI_BASE_URL"] = base_url
    if extra:
        env.update(extra)
    return env


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


def c_benchmark_supported(c_path: Path, *, timeout_seconds: int = 8) -> tuple[bool, str]:
    if not c_path.exists():
        return False, f"Missing benchmark file: {c_path}"
    text = c_path.read_text(encoding="utf-8", errors="ignore")
    for marker in ["unsupported_translation", "unsupported method omitted", "/* unsupported "]:
        if marker in text:
            return False, f"Unsupported translation marker: {marker}"
    try:
        result = subprocess.run(
            ["opam", "exec", "--switch=frama-c.27.1", "--", "frama-c", "-print", str(c_path)],
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired:
        return False, f"Frama-C timeout after {timeout_seconds}s"
    return result.returncode == 0, (result.stderr or result.stdout).strip()


def apply_sespec_preset(base_config: dict, preset: str) -> None:
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


def metrics_from_run_payload(run_payload: dict, result_seconds: float, loop_mode: bool) -> dict:
    first_pass = run_payload.get("first_pass") or {}
    syntax_status = first_pass.get("syntax_status") or ("pass" if first_pass.get("syntax") else "fail")
    validity_status = first_pass.get("validity_status") or ("pass" if first_pass.get("valid") else "fail")
    satisfy_status = first_pass.get("satisfy_status") or ("pass" if first_pass.get("satisfy") else "fail")
    token_stats = run_payload.get("token_stats") or {}
    return {
        "success": syntax_status == "pass" and validity_status == "pass" and (loop_mode or satisfy_status == "pass"),
        "valid_pass": validity_status == "pass",
        "syntax_ok": syntax_status == "pass",
        "first_pass_syntax": first_pass.get("syntax") == 1,
        "first_pass_valid": first_pass.get("valid") == 1,
        "failure_reason": first_pass.get("failure_reason", "unknown"),
        "syntax_status": syntax_status,
        "validity_status": validity_status,
        "satisfy_status": satisfy_status,
        "total_seconds": float(run_payload.get("total_seconds", result_seconds)),
        "prompt_tokens": int(token_stats.get("total_prompt_tokens", 0)),
        "completion_tokens": int(token_stats.get("total_completion_tokens", 0)),
        "total_tokens": int(token_stats.get("total_tokens", 0)),
        "call_count": int(token_stats.get("call_count", 0)),
    }


def run_sespec_case(
    *,
    bench: str,
    case_path: Path,
    model: str,
    preset: str,
    env_name: str,
    base_url: str,
    temperature: float,
    top_p: float,
    skip_support_check: bool,
    out: Path,
) -> dict:
    function_name = function_name_for_case(case_path)
    if not skip_support_check:
        supported, support_message = c_benchmark_supported(case_path)
        if not supported:
            return {
                "project": "sespec",
                "preset": preset,
                "model": model,
                "root_dir": bench,
                "case_id": case_path.stem,
                "function_name": function_name,
                "source_path": str(case_path),
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

    run_id = f"{datetime.now().strftime('%Y%m%d_%H%M%S')}_{os.getpid()}_{uuid4().hex[:8]}"
    TMP_ROOT.mkdir(parents=True, exist_ok=True)
    temp_input_base = TMP_ROOT / "inputs" / run_id / bench / case_path.stem
    temp_input_bench = temp_input_base / bench
    temp_input_bench.mkdir(parents=True, exist_ok=True)
    shutil.copy2(case_path, temp_input_bench / case_path.name)

    try:
        temp_config = TMP_ROOT / f"sespec_{preset}_{bench}_{case_path.stem}_{model}_{run_id}.json"
        base_config = json.loads((SRC_ROOT / "configs" / "func_config.json").read_text(encoding="utf-8"))
        base_config["main"]["root_dir"] = bench
        base_config["main"]["input_dir"] = str(temp_input_base)
        base_config["main"]["function_name"] = function_name
        base_config["main"]["run_id"] = run_id
        apply_sespec_preset(base_config, preset)
        base_config["llm"]["api_model"] = model
        base_config["llm"]["base_url"] = base_url
        base_config["llm"].pop("api_key", None)
        base_config["llm"]["api_temperature"] = temperature
        base_config["llm"]["api_top_p"] = top_p
        temp_config.write_text(json.dumps(base_config, indent=2), encoding="utf-8")

        workspace_root = SRC_ROOT / "log" / bench / model / function_name / run_id
        command = [
            "conda",
            "run",
            "--no-capture-output",
            "-n",
            env_name,
            "python",
            "main.py",
            "--config",
            str(temp_config),
        ]
        env = project_env(base_url, {"PATH": f"/home/yangfp/.opam/frama-c.27.1/bin:{os.environ.get('PATH', '')}"})
        result = run_command(command, cwd=SRC_ROOT, env=env, log_path=out / "command.log")

        workspace_log = workspace_root / "run.log"
        workspace_output = workspace_root / "output" / f"{function_name}.c"
        workspace_loop_qcp = workspace_root / "2_output" / f"{function_name}.c"
        workspace_loop_acsl = workspace_root / "3_output" / f"{function_name}.c"
        workspace_summary = workspace_root / "run_summary.json"
        for source, target_name in [
            (workspace_log, f"{function_name}.log"),
            (workspace_output, f"{function_name}.c"),
            (workspace_loop_qcp, f"{function_name}.qcp.c"),
            (workspace_loop_acsl, f"{function_name}.loop.c"),
        ]:
            if source.exists():
                shutil.copy2(source, out / target_name)

        run_payload = json.loads(workspace_summary.read_text(encoding="utf-8")) if workspace_summary.exists() else {}
        metrics = metrics_from_run_payload(run_payload, result.seconds, loop_mode=False) if run_payload else {
            "success": False,
            "valid_pass": False,
            "syntax_ok": False,
            "failure_reason": "missing_run_summary",
            "total_seconds": result.seconds,
            "prompt_tokens": 0,
            "completion_tokens": 0,
            "total_tokens": 0,
            "call_count": 0,
        }
        summary = {
            "project": "sespec",
            "preset": preset,
            "loop_mode": False,
            "model": model,
            "root_dir": bench,
            "case_id": case_path.stem,
            "function_name": function_name,
            "source_path": str(case_path),
            "returncode": result.returncode,
            "command": result.command,
            "run_id": run_id,
            "workspace_root": str(workspace_root),
            "log_path": str(out / f"{function_name}.log" if (out / f"{function_name}.log").exists() else workspace_log),
            "output_path": str(out / f"{function_name}.c" if (out / f"{function_name}.c").exists() else workspace_output),
            "loop_qcp_path": str(out / f"{function_name}.qcp.c" if (out / f"{function_name}.qcp.c").exists() else workspace_loop_qcp),
            "loop_acsl_path": str(out / f"{function_name}.loop.c" if (out / f"{function_name}.loop.c").exists() else workspace_loop_acsl),
            **metrics,
        }
        return summary
    finally:
        shutil.rmtree(temp_input_base.parent, ignore_errors=True)


def run_job(
    *,
    run_root: Path,
    bench: str,
    case_path: Path,
    model: str,
    label: str,
    env_name: str,
    base_url: str,
    temperature: float,
    top_p: float,
    skip_support_check: bool,
) -> None:
    out = run_root / bench / label / model / case_path.stem
    if (out / "summary.json").exists():
        print(f"[SKIP] {bench} {case_path.stem} {model} {label}")
        return
    out.mkdir(parents=True, exist_ok=True)
    try:
        summary = run_sespec_case(
            bench=bench,
            case_path=case_path,
            model=model,
            preset=label.replace("sespec_", ""),
            env_name=env_name,
            base_url=base_url,
            temperature=temperature,
            top_p=top_p,
            skip_support_check=skip_support_check,
            out=out,
        )
        summary["judge_score"] = None
        (out / "summary.json").write_text(json.dumps(summary, indent=2, ensure_ascii=False), encoding="utf-8")
        print(f"[OK] {bench} {case_path.stem} {model} {label}")
    except Exception:
        (out / "error.txt").write_text(traceback.format_exc(), encoding="utf-8")
        print(f"[ERR] {bench} {case_path.stem} {model} {label}")


def summarize_group(base: Path, group: str) -> Path:
    stats: dict[tuple[str, str], dict[str, float | int]] = defaultdict(
        lambda: {"total": 0, "valid": 0, "skip": 0, "judge_count": 0, "complete": 0, "seconds": 0.0, "tokens": 0}
    )
    for path in base.glob("*/*/*/summary.json"):
        label, model = path.parts[-4], path.parts[-3]
        item = json.loads(path.read_text(encoding="utf-8"))
        key = (label, model)
        stats[key]["total"] += 1
        stats[key]["valid"] += 1 if item.get("valid_pass", False) else 0
        stats[key]["skip"] += 1 if item.get("skipped", False) else 0
        judge_score = item.get("judge_score")
        if judge_score is not None:
            stats[key]["judge_count"] += 1
            stats[key]["complete"] += int(judge_score)
        stats[key]["seconds"] += float(item.get("total_seconds", 0) or 0)
        stats[key]["tokens"] += int(item.get("total_tokens", 0) or 0)

    out_path = base / "summary.csv"
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.writer(handle)
        writer.writerow(
            [
                "group",
                "label",
                "model",
                "total",
                "valid",
                "skip",
                "valid_rate",
                "judge_count",
                "complete",
                "complete_rate",
                "total_seconds",
                "total_tokens",
            ]
        )
        for (label, model), stat in sorted(stats.items()):
            total = int(stat["total"]) or 1
            judge_count = int(stat["judge_count"]) or 1
            writer.writerow(
                [
                    group,
                    label,
                    model,
                    int(stat["total"]),
                    int(stat["valid"]),
                    int(stat["skip"]),
                    f"{int(stat['valid']) / total:.4f}",
                    int(stat["judge_count"]),
                    int(stat["complete"]),
                    f"{int(stat['complete']) / judge_count:.4f}" if int(stat["judge_count"]) else "0.0000",
                    f"{float(stat['seconds']):.2f}",
                    int(stat["tokens"]),
                ]
            )
    return out_path


def run_bench(
    *,
    run_root: Path,
    bench: str,
    cases: list[Path],
    models: list[str],
    labels: set[str],
    workers: int,
    env_name: str,
    base_url: str,
    temperature: float,
    top_p: float,
    skip_support_check: bool,
) -> Path:
    jobs = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        for case_path in cases:
            for model in models:
                for label in DEFAULT_LABELS:
                    if label not in labels:
                        continue
                    jobs.append(
                        executor.submit(
                            run_job,
                            run_root=run_root,
                            bench=bench,
                            case_path=case_path,
                            model=model,
                            label=label,
                            env_name=env_name,
                            base_url=base_url,
                            temperature=temperature,
                            top_p=top_p,
                            skip_support_check=skip_support_check,
                        )
                    )
        for future in concurrent.futures.as_completed(jobs):
            future.result()
    return summarize_group(run_root / bench, bench)


def main() -> None:
    args = parse_args()
    models = args.models or load_models()
    benches = resolve_benches(args.bench)
    labels = set(args.labels)
    run_name = args.run_name or datetime.now().strftime("%Y%m%d_%H%M%S")
    run_root = RESULTS_ROOT / run_name
    run_root.mkdir(parents=True, exist_ok=True)

    for bench in benches:
        cases = load_cases(bench)
        if args.limit:
            cases = cases[: args.limit]
        summary_path = run_bench(
            run_root=run_root,
            bench=bench,
            cases=cases,
            models=models,
            labels=labels,
            workers=args.workers,
            env_name=args.env_name,
            base_url=args.base_url,
            temperature=args.temperature,
            top_p=args.top_p,
            skip_support_check=args.skip_support_check,
        )
        print(f"done: {bench}, benchmarks={len(cases)}, models={len(models)}")
        print(summary_path)
    print(f"run_root={run_root}")


if __name__ == "__main__":
    main()
