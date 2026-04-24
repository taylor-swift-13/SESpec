from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

from represent.judge import judge_spec_completeness
from represent.runners.common import ROOT, write_json


def extract_specgen_candidate(log_path: Path, output_path: Path) -> Path:
    content = log_path.read_text(encoding="utf-8", errors="ignore")
    blocks = re.findall(r"```(?:java)?\n(.*?)```", content, re.DOTALL)
    if not blocks:
        raise ValueError(f"No Java code block found in {log_path}")
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(blocks[-1].strip() + "\n", encoding="utf-8")
    return output_path


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", required=True, help="Original source program path")
    parser.add_argument("--candidate", help="Annotated candidate program path")
    parser.add_argument("--language", choices=["c", "java"], required=True)
    parser.add_argument("--model", default="gpt-5.4")
    parser.add_argument("--project", default="generic")
    parser.add_argument("--specgen-log", help="SpecGen log path; extracts last Java block as candidate")
    parser.add_argument("--output", help="Output JSON path")
    args = parser.parse_args()

    source_path = Path(args.source)
    if args.specgen_log:
        candidate_path = extract_specgen_candidate(
            Path(args.specgen_log),
            ROOT / "represent" / "results" / "judge" / "tmp" / f"{source_path.stem}.specgen.java",
        )
    elif args.candidate:
        candidate_path = Path(args.candidate)
    else:
        raise ValueError("Either --candidate or --specgen-log must be provided")

    usage_log = ROOT / "represent" / "results" / "judge" / "usage.jsonl"
    result = judge_spec_completeness(
        model=args.model,
        language=args.language,
        original_program_path=source_path,
        candidate_program_path=candidate_path,
        usage_log=usage_log,
    )
    result["project"] = args.project
    out_path = Path(args.output) if args.output else ROOT / "represent" / "results" / "judge" / f"{args.project}_{source_path.stem}.json"
    write_json(out_path, result)
    print(json.dumps({
        "project": result["project"],
        "score": result["score"],
        "output": str(out_path),
    }, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()
