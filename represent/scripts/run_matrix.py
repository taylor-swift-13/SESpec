from __future__ import annotations

import argparse
import concurrent.futures
import csv
from datetime import datetime
import json
import os
import re
import shutil
import traceback
from collections import defaultdict
from pathlib import Path

from represent.api.config import get_settings
from represent.judge import judge_spec_completeness
from represent.runners import run_autospec, run_bare_model, run_sespec, run_specgen


ROOT = Path(__file__).resolve().parents[2]
BENCH_ROOT = ROOT / "represent" / "bench"
MAPPING_PATH = BENCH_ROOT / "mapping.tsv"
LOOP_MODE_PATH = BENCH_ROOT / "sespec_loop_mode.json"
RESULTS_ROOT = ROOT / "represent" / "results" / "matrix_runs"
AUTO_SPEC_ROOT = ROOT / "represent" / "external" / "autospec"
SESPEC_INPUT_ROOT = ROOT / "src" / "input"
JUDGE_MODEL = "gpt-5.4"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the fixed linear/unlinear matrix experiment.")
    parser.add_argument("--group", choices=["linear", "unlinear", "all"], default="all")
    parser.add_argument("--limit", type=int, default=0, help="Run only the first N benchmarks in each group.")
    parser.add_argument(
        "--run-name",
        default=None,
        help="Timestamped output folder name. Defaults to YYYYMMDD_HHMMSS.",
    )
    parser.add_argument(
        "--models",
        nargs="*",
        default=None,
        help="Override model list. Defaults to represent/config/models.yaml.",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=max(1, min(4, os.cpu_count() or 1)),
        help="Parallel benchmark workers. Models and tools for the same benchmark still run sequentially.",
    )
    return parser.parse_args()


def load_rows(group: str) -> list[dict[str, str]]:
    with MAPPING_PATH.open(encoding="utf-8") as handle:
        rows = list(csv.DictReader(handle, delimiter="\t"))
    return [row for row in rows if row["id"].startswith(f"SVCOMP_{group}_")]


def load_loop_ids() -> set[str]:
    payload = json.loads(LOOP_MODE_PATH.read_text(encoding="utf-8"))
    return set(payload.get("only_loop_ids", []))


def copy_if_exists(src: Path, dst: Path) -> None:
    if src.exists() and src.is_file():
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


def copytree_if_exists(src: Path, dst: Path) -> None:
    if src.exists() and src.is_dir():
        if dst.exists():
            shutil.rmtree(dst)
        shutil.copytree(src, dst)


def ensure_benchmark_inputs(bench_id: str, c_path: Path) -> str:
    sespec_dir = SESPEC_INPUT_ROOT / bench_id
    sespec_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy2(c_path, sespec_dir / c_path.name)

    autospec_rel = f"benchmark/represent_matrix/{bench_id}.c"
    autospec_target = AUTO_SPEC_ROOT / autospec_rel
    autospec_target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(c_path, autospec_target)
    return autospec_rel


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


def _extract_specgen_candidate(log_path: Path, output_path: Path) -> Path:
    content = log_path.read_text(encoding="utf-8", errors="ignore")
    blocks = re.findall(r"```(?:java)?\n(.*?)```", content, re.DOTALL)
    if blocks:
        candidate = blocks[-1].strip() + "\n"
    else:
        head = re.split(r"^\s*=+\s*$", content, maxsplit=1, flags=re.MULTILINE)[0].strip()
        if not re.search(r"\bclass\b", head):
            raise ValueError(f"No Java code block found in {log_path}")
        candidate = head + "\n"
    output_path.write_text(candidate, encoding="utf-8")
    return output_path


def _find_bare_candidate(out: Path, language: str) -> Path | None:
    matches = [
        p for p in out.glob(f"*.{language}")
        if p.name not in {"command.log", "summary.json", "usage.jsonl"}
    ]
    return sorted(matches)[-1] if matches else None


def _resolve_judge_inputs(
    *,
    label: str,
    out: Path,
    summary: dict,
    source_java: Path,
    source_c: Path,
) -> tuple[str, Path, Path] | None:
    if label == "bare_model_java":
        candidate = _find_bare_candidate(out, "java")
        return ("java", source_java, candidate) if candidate else None
    if label == "bare_model_c":
        candidate = _find_bare_candidate(out, "c")
        return ("c", source_c, candidate) if candidate else None
    if label == "specgen":
        log_path = summary.get("log_path")
        if not log_path:
            return None
        candidate = _extract_specgen_candidate(Path(log_path), out / "candidate.java")
        return ("java", source_java, candidate)
    if label == "autospec":
        candidate = out / "autospec_out" / f"{summary['benchmark'].split('/')[-1].removesuffix('.c')}_merged.c"
        return ("c", source_c, candidate) if candidate.exists() else None
    if label.startswith("sespec_"):
        function_name = summary.get("function_name")
        if not function_name:
            return None
        candidate = out / f"{function_name}.c"
        return ("c", source_c, candidate) if candidate.exists() else None
    return None


def _run_judge(
    *,
    out: Path,
    label: str,
    summary: dict,
    source_java: Path,
    source_c: Path,
) -> int | None:
    if not summary.get("valid_pass", False):
        return None
    judge_inputs = _resolve_judge_inputs(
        label=label,
        out=out,
        summary=summary,
        source_java=source_java,
        source_c=source_c,
    )
    if not judge_inputs:
        return None
    language, source_path, candidate_path = judge_inputs
    result = judge_spec_completeness(
        model=JUDGE_MODEL,
        language=language,
        original_program_path=source_path,
        candidate_program_path=candidate_path,
        usage_log=out / "judge_usage.jsonl",
    )
    judge_payload = {"score": int(result["score"])}
    (out / "judge.json").write_text(json.dumps(judge_payload, indent=2), encoding="utf-8")
    return judge_payload["score"]


def run_job(
    *,
    run_root: Path,
    group: str,
    bench_id: str,
    model: str,
    label: str,
    source_java: Path,
    source_c: Path,
    runner,
) -> None:
    out = run_root / group / label / model / bench_id
    out.mkdir(parents=True, exist_ok=True)
    try:
        summary = runner()
        judge_score = None
        try:
            judge_score = _run_judge(
                out=out,
                label=label,
                summary=summary,
                source_java=source_java,
                source_c=source_c,
            )
        except Exception:
            (out / "judge_error.txt").write_text(traceback.format_exc(), encoding="utf-8")
        summary["judge_score"] = judge_score
        (out / "summary.json").write_text(
            json.dumps(summary, indent=2, ensure_ascii=False),
            encoding="utf-8",
        )

        if label == "specgen":
            if summary.get("log_path"):
                copy_if_exists(Path(summary["log_path"]), out / Path(summary["log_path"]).name)
            smoke = ROOT / "represent" / "results" / "smoke" / "specgen" / model / Path(str(summary.get("benchmark", ""))).stem
            copy_if_exists(smoke / "command.log", out / "command.log")
            copy_if_exists(smoke / "usage.jsonl", out / "usage.jsonl")

        elif label == "autospec":
            smoke = ROOT / "represent" / "results" / "smoke" / "autospec" / "one_shot" / model / bench_id
            copy_if_exists(smoke / "command.log", out / "command.log")
            copytree_if_exists(smoke / "autospec_out", out / "autospec_out")

        elif label.startswith("sespec_"):
            preset = label.replace("sespec_", "")
            function_name = summary.get("function_name", "")
            if function_name:
                smoke = ROOT / "represent" / "results" / "smoke" / "sespec" / preset / model / bench_id / function_name
                copy_if_exists(smoke / "command.log", out / "command.log")
                copy_if_exists(ROOT / "src" / "log" / bench_id / model / f"{function_name}.log", out / f"{function_name}.log")
                copy_if_exists(ROOT / "src" / "output" / bench_id / f"{function_name}.c", out / f"{function_name}.c")

        elif label.startswith("bare_model_"):
            language = "java" if label.endswith("java") else "c"
            smoke = ROOT / "represent" / "results" / "smoke" / "bare_model" / language / model / bench_id
            copy_if_exists(smoke / "command.log", out / "command.log")
            for pattern in ("*.java", "*.c"):
                for file_path in smoke.glob(pattern):
                    copy_if_exists(file_path, out / file_path.name)

        print(f"[OK] {group} {bench_id} {model} {label}")
    except Exception:
        (out / "error.txt").write_text(traceback.format_exc(), encoding="utf-8")
        print(f"[ERR] {group} {bench_id} {model} {label}")


def run_benchmark(run_root: Path, group: str, row: dict[str, str], models: list[str], loop_ids: set[str]) -> None:
    bench_id = row["id"]
    java_path = ROOT / row["source_path"]
    c_path = ROOT / row["translated_c_path"]
    autospec_rel = ensure_benchmark_inputs(bench_id, c_path)
    stem = c_path.stem
    use_loop_mode = bench_id in loop_ids

    for model in models:
        jobs = [
            (
                "bare_model_java",
                lambda model=model, java_path=str(java_path), bench_id=bench_id: run_bare_model(
                    model, source_path=java_path, language="java", benchmark_id=bench_id
                ),
            ),
            (
                "bare_model_c",
                lambda model=model, c_path=str(c_path), bench_id=bench_id: run_bare_model(
                    model, source_path=c_path, language="c", benchmark_id=bench_id
                ),
            ),
            (
                "specgen",
                lambda model=model, java_path=str(java_path): run_specgen(
                    model, benchmark_relpath=java_path
                ),
            ),
            (
                "autospec",
                lambda model=model, autospec_rel=autospec_rel: run_autospec(
                    model, benchmark_relpath=autospec_rel, one_shot=True
                ),
            ),
            (
                "sespec_default",
                lambda model=model, bench_id=bench_id, stem=stem, use_loop_mode=use_loop_mode: run_sespec(
                    model,
                    root_dir=bench_id,
                    function_name=stem,
                    preset="default",
                    loop_mode=use_loop_mode,
                ),
            ),
            (
                "sespec_no_repair",
                lambda model=model, bench_id=bench_id, stem=stem, use_loop_mode=use_loop_mode: run_sespec(
                    model,
                    root_dir=bench_id,
                    function_name=stem,
                    preset="no_repair",
                    loop_mode=use_loop_mode,
                ),
            ),
            (
                "sespec_no_se_no_repair",
                lambda model=model, bench_id=bench_id, stem=stem, use_loop_mode=use_loop_mode: run_sespec(
                    model,
                    root_dir=bench_id,
                    function_name=stem,
                    preset="no_se_no_repair",
                    loop_mode=use_loop_mode,
                ),
            ),
            (
                "sespec_bare_prompt",
                lambda model=model, bench_id=bench_id, stem=stem, use_loop_mode=use_loop_mode: run_sespec(
                    model,
                    root_dir=bench_id,
                    function_name=stem,
                    preset="bare_prompt",
                    loop_mode=use_loop_mode,
                ),
            ),
        ]
        for label, runner in jobs:
            run_job(
                run_root=run_root,
                group=group,
                bench_id=bench_id,
                model=model,
                label=label,
                source_java=java_path,
                source_c=c_path,
                runner=runner,
            )


def run_group(
    run_root: Path,
    group: str,
    rows: list[dict[str, str]],
    models: list[str],
    loop_ids: set[str],
    workers: int,
) -> Path:
    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        futures = [
            executor.submit(run_benchmark, run_root, group, row, models, loop_ids)
            for row in rows
        ]
        for future in concurrent.futures.as_completed(futures):
            future.result()
    return summarize_group(run_root / group, group)


def main() -> None:
    args = parse_args()
    settings = get_settings()
    models = args.models or settings.model_list
    groups = ["linear", "unlinear"] if args.group == "all" else [args.group]
    loop_ids = load_loop_ids()
    run_name = args.run_name or datetime.now().strftime("%Y%m%d_%H%M%S")
    run_root = RESULTS_ROOT / run_name
    run_root.mkdir(parents=True, exist_ok=True)

    for group in groups:
        rows = load_rows(group)
        if args.limit:
            rows = rows[: args.limit]
        summary_path = run_group(run_root, group, rows, models, loop_ids, args.workers)
        print(f"done: {group}, benchmarks={len(rows)}, models={len(models)}")
        print(summary_path)
    print(f"run_root={run_root}")


if __name__ == "__main__":
    main()
