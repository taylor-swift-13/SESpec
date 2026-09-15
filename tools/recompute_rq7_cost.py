#!/usr/bin/env python3
"""Recompute RQ7 costs for all 400 gpt-5.4-mini benchmark programs."""

import json
import os
from pathlib import Path
import re
import csv

ROOT = Path(__file__).resolve().parents[1]
DATA = ROOT / "RESULTS" / "paper_data"
OUTPUT = DATA / "rq7_cost" / "reanalysis"
METHODS = ("SESpec", "SESpec_no_refine", "LLM-C", "AutoSpec", "SpecGen")
METHOD_FOLDERS = {
    "SESpec": "sespec",
    "SESpec_no_refine": "sespec_no_refine",
    "LLM-C": "llm_c",
    "AutoSpec": "autospec",
    "SpecGen": "specgen",
}
MODELS = ("gpt-5.4-mini",)
METRICS = ("seconds", "tokens", "calls")
AUTOSPEC_ARCHIVE = Path(os.environ.get(
    "RQ7_AUTOSPEC_ARCHIVE",
    "/home/yangfp/TRASH/SESpecTrash/represent/results/smoke/autospec/one_shot/gpt-5.4-mini",
))
SESpec_ARCHIVE = ROOT / "src/results/matrix_runs/20260521_165109_sespec400_strengthened_3models/sespec_default/sespec/gpt-5.4-mini"
TOKEN_LINE = re.compile(r"(?:^|\n)\s*(?:INFO:root:)?total_tokens:\s*(\d+)")


def autospec_archive(case_id):
    specgen = DATA / "rq5_validity/runs/specgen/gpt-5.4-mini" / str(case_id) / "summary.json"
    stem = json.loads(specgen.read_text()).get("archive_case_id")
    return AUTOSPEC_ARCHIVE / stem if stem else None


def logged_tokens(case_id, expected_calls):
    archive = autospec_archive(case_id)
    if archive is None:
        return None
    logs = sorted(archive.glob("command.step_*.log"))
    if len(logs) != expected_calls or not logs:
        return None
    values = [TOKEN_LINE.findall(path.read_text(errors="ignore")) for path in logs]
    if not all(len(value) == 1 for value in values):
        return None
    return sum(int(value[0]) for value in values)


def reconstructed_tokens(case_id, expected_calls):
    """Estimate missing original-step usage from a matched-model rerun.

    Original elapsed time, call count, and validity always remain attached to
    the original attempt. When possible, retain exact per-step archive usage.
    """
    replacement = OUTPUT / "reruns/autospec/gpt-5.4-mini" / str(case_id) / "summary.json"
    if not replacement.exists():
        return None
    rerun = json.loads(replacement.read_text())
    steps = rerun.get("steps", [])
    observed = [step.get("tokens") for step in steps]
    if not observed or any(not isinstance(value, int) or value <= 0 for value in observed):
        return None
    archive = autospec_archive(case_id)
    logs = sorted(archive.glob("command.step_*.log")) if archive else []
    exact = [None] * expected_calls
    if len(logs) == expected_calls:
        for index, log in enumerate(logs):
            matches = TOKEN_LINE.findall(log.read_text(errors="ignore"))
            if len(matches) == 1:
                exact[index] = int(matches[0])
    estimated = 0
    total = 0
    for index in range(expected_calls):
        if exact[index] is not None:
            total += exact[index]
        else:
            total += observed[index] if index < len(observed) else round(sum(observed) / len(observed))
            estimated += 1
    return total, estimated


def load_record(method, model, case_id):
    folder = DATA / "rq5_validity" / "runs" / METHOD_FOLDERS[method] / model / str(case_id)
    source = folder / "summary.json"
    origin = "paper_archive"
    if not source.exists() and method == "SESpec":
        summaries = list((SESpec_ARCHIVE / str(case_id)).glob("*/summary.json"))
        if len(summaries) == 1:
            source, origin = summaries[0], "later_model_archive"
    if not source.exists() and method == "AutoSpec":
        archive = autospec_archive(case_id)
        source = archive / "summary.json" if archive else source
        origin = "autospec_step_archive"
    if not source.exists():
        return None
    raw = json.loads(source.read_text())
    canonical = folder / "summary_canonical.json"
    if origin == "paper_archive" and canonical.exists():
        canonical_record = json.loads(canonical.read_text())
        valid = bool(canonical_record.get("valid_pass") and canonical_record.get("body_aligned", True))
    elif "valid_pass" in raw:
        valid = bool(raw["valid_pass"])
    else:
        valid = raw.get("result") == "pass"
    values = {
        "seconds": raw.get("total_seconds", raw.get("seconds")),
        "tokens": raw.get("total_tokens", raw.get("tokens")),
        "calls": raw.get("call_count", raw.get("api_calls", raw.get("step_count"))),
    }
    if method == "SESpec_no_refine" and values["calls"] is None and values["tokens"] is None:
        log_name = raw.get("function_name", "") + ".log"
        log = folder / log_name
        log_text = log.read_text(errors="ignore") if log.is_file() else ""
        if raw.get("failure_reason") == "returncode_1" and log_text and "LLM querying" not in log_text and "Total tokens:" not in log_text:
            values["calls"] = values["tokens"] = 0
            origin += "+before_api_failure"
    if not all(isinstance(values[key], (int, float)) and values[key] >= 0
               for key in ("seconds", "calls")):
        return None
    # Legacy AutoSpec summaries use zero as a placeholder. Recover actual usage
    # from the archived per-step logs when every API call has a token record.
    if method == "AutoSpec" and values["tokens"] == 0 and values["calls"] > 0:
        values["tokens"] = logged_tokens(case_id, int(values["calls"]))
        if values["tokens"] is not None:
            origin += "+step_logs"
    if method == "AutoSpec" and values["tokens"] is None and values["calls"] > 0:
        recovered = reconstructed_tokens(case_id, int(values["calls"]))
        if recovered is not None:
            values["tokens"], estimated_steps = recovered
            origin += f"+rerun_estimate_{estimated_steps}_steps"
    if not isinstance(values["tokens"], (int, float)):
        values["tokens"] = None
    return {"valid": valid, "origin": origin, **values}


def main():
    records = {}
    for model in MODELS:
        for case_id in range(400):
            group = {method: load_record(method, model, case_id)
                     for method in METHODS}
            if not all(group.values()):
                raise RuntimeError(f"missing cost record for {model}:{case_id}: "
                                   f"{[method for method, value in group.items() if value is None]}")
            records[f"{model}:{case_id}"] = group
    assert len(records) == 400, f"cost cohort changed: {len(records)}"

    summary = {
        "models": list(MODELS),
        "paired_attempts_per_method": len(records),
        "paired_case_models": {
            model: sum(key.startswith(model + ":") for key in records)
            for model in MODELS
        },
        "methods": {},
    }
    for method in METHODS:
        runs = [group[method] for group in records.values()]
        valid = [run for run in runs if run["valid"]]
        failed = [run for run in runs if not run["valid"]]
        totals = {metric: sum(run[metric] for run in runs)
                  if all(run[metric] is not None for run in runs) else None
                  for metric in METRICS}
        def mean(group, metric):
            return (sum(run[metric] for run in group) / len(group)
                    if all(run[metric] is not None for run in group) else None)
        summary["methods"][method] = {
            "valid_n": len(valid), "failed_n": len(failed),
            "token_recorded_n": sum(run["tokens"] is not None for run in runs),
            "token_rerun_estimated_n": sum("+rerun_estimate_" in run["origin"] for run in runs),
            "token_missing_case_ids": [case_id for case_id in range(400)
                                       if records[f"{MODELS[0]}:{case_id}"][method]["tokens"] is None],
            "record_origins": {origin: sum(run["origin"] == origin for run in runs)
                               for origin in sorted({run["origin"] for run in runs})},
            "valid_mean": {metric: mean(valid, metric) for metric in METRICS},
            "failed_mean": {metric: mean(failed, metric) for metric in METRICS},
            "valid_contribution_per_attempt": {
                metric: sum(run[metric] for run in valid) / len(runs)
                if all(run[metric] is not None for run in valid) else None
                for metric in METRICS
            },
            "failed_contribution_per_attempt": {
                metric: sum(run[metric] for run in failed) / len(runs)
                if all(run[metric] is not None for run in failed) else None
                for metric in METRICS
            },
            "all_attempt_mean": {metric: totals[metric] / len(runs)
                                 if totals[metric] is not None else None
                                 for metric in METRICS},
            "total_cost_per_valid": {metric: totals[metric] / len(valid)
                                     if totals[metric] is not None else None
                                     for metric in METRICS},
        }
        for metric in METRICS:
            x = summary["methods"][method]
            if x["all_attempt_mean"][metric] is None:
                continue
            assert abs(x["all_attempt_mean"][metric] -
                       x["valid_contribution_per_attempt"][metric] -
                       x["failed_contribution_per_attempt"][metric]) < 1e-7
    OUTPUT.mkdir(parents=True, exist_ok=True)
    current = OUTPUT / "summary.json"
    if current.exists() and json.loads(current.read_text()).get("paired_attempts_per_method") == 646:
        current.rename(OUTPUT / "legacy_three_model_cohort.json")
    current.write_text(json.dumps(summary, indent=2) + "\n")
    with (OUTPUT / "per_case.csv").open("w", newline="") as output:
        writer = csv.DictWriter(output, fieldnames=("model", "case_id", "method", "valid", "seconds", "tokens", "calls", "origin"), lineterminator="\n")
        writer.writeheader()
        for key, group in records.items():
            model, case_id = key.split(":")
            for method, record in group.items():
                writer.writerow({"model": model, "case_id": case_id,
                                 "method": method, **record})
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
