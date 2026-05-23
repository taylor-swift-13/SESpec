#!/usr/bin/env python3
"""Re-judge SpecGen outputs with strict OpenJML parameters.

SpecGen invokes OpenJML with `-nowarn --arithmetic-failure=quiet --esc-max-warnings 1`,
which suppresses overflow / div-by-zero / postcondition warnings. This rejudge
re-runs OpenJML in ESC mode WITHOUT those suppressions on the FINAL Java spec
that SpecGen produced for each case. Any warning or error → INVALID.

Output:
  - Overwrites each case_dir/summary.json's `valid_pass` field with the strict
    verdict, preserves the SpecGen-internal verdict under `valid_pass_specgen`,
    and adds `strict_openjml_output` (truncated) + `strict_openjml_returncode`.
  - Prints a per-case + aggregate summary.

Usage:
  python rejudge_specgen_strict.py /path/to/specgen_full400/gpt-5
"""
from __future__ import annotations

import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

OPENJML = Path("/home/yangfp/CAV-JAVA/.tools/openjml/current/openjml")
STRICT_FLAGS = [
    "--esc",
    "--prover=cvc4",
    "--nonnull-by-default",
    "--arithmetic-failure=soft",  # was 'quiet' in specgen (suppress); soft is openjml default that emits warnings
    "--timeout", "200",
    # Removed from specgen's lenient command:
    #   --esc-max-warnings 1, -nowarn, --quiet
]


def extract_final_java(log_path: Path) -> tuple[str, str] | None:
    """Return (classname, final_java_code) from the SpecGen iteration log, or None.

    SpecGen log structure (after Bug fix): blocks separated by '====...====':
      [code_iter1][err_iter1][code_iter2][err_iter2]...[code_iterN][err_iterN]
    The LAST code block is the final spec'd Java. We pick it and extract the
    class name with the same regex SpecGen uses.
    """
    if not log_path.exists():
        return None
    text = log_path.read_text(encoding="utf-8", errors="ignore")
    blocks = [b.strip() for b in text.split("==============================") if b.strip()]
    if not blocks:
        return None
    # Code blocks contain 'class Xxx { ... }'; err blocks are openjml output
    # The last code block is at index -2 (last is err) OR -1 if log ends mid-iter
    code_blocks = [b for b in blocks if re.search(r'\bclass\s+\w+', b) and '{' in b]
    if not code_blocks:
        return None
    code = code_blocks[-1]
    m = re.search(r'\b(?:public\s+)?class\s+(\w+)', code)
    if not m:
        return None
    return m.group(1), code


def strict_judge_one(case_dir: Path) -> dict:
    out = {"case_id": case_dir.name, "strict_valid_pass": False,
           "strict_openjml_output": "", "strict_openjml_returncode": -1,
           "note": ""}
    sp = case_dir / "summary.json"
    if not sp.exists():
        out["note"] = "no summary.json"
        return out
    # Find SpecGen log
    logs = sorted(case_dir.glob("log-*-*.txt"))
    if not logs:
        out["note"] = "no specgen log"
        return out
    log_path = logs[-1]
    parsed = extract_final_java(log_path)
    if parsed is None:
        out["note"] = "could not extract final java from log"
        return out
    classname, code = parsed
    # Write to a unique temp file (filename must match class name)
    with tempfile.TemporaryDirectory() as tmpd:
        tmp = Path(tmpd) / f"{classname}.java"
        tmp.write_text(code, encoding="utf-8")
        cmd = [str(OPENJML), *STRICT_FLAGS, str(tmp)]
        try:
            proc = subprocess.run(cmd, capture_output=True, text=True, timeout=240)
            out["strict_openjml_returncode"] = proc.returncode
            output = (proc.stdout or "") + (proc.stderr or "")
        except subprocess.TimeoutExpired:
            out["strict_openjml_returncode"] = -2
            output = "[TIMEOUT after 240s]"
        out["strict_openjml_output"] = output[:2000]
        # Strict valid: empty output (no warning, no error)
        out["strict_valid_pass"] = (proc.returncode == 0 and output.strip() == "") \
            if "proc" in dir() else False
    return out


def merge_into_summary(case_dir: Path, result: dict) -> None:
    sp = case_dir / "summary.json"
    if not sp.exists():
        return
    d = json.loads(sp.read_text(encoding="utf-8"))
    # Preserve previous verdict
    if "valid_pass_specgen" not in d:
        d["valid_pass_specgen"] = bool(d.get("valid_pass"))
    d["valid_pass"] = bool(result["strict_valid_pass"])  # strict overrides
    d["strict_openjml_output"] = result["strict_openjml_output"]
    d["strict_openjml_returncode"] = result["strict_openjml_returncode"]
    if result.get("note"):
        d["strict_note"] = result["note"]
    sp.write_text(json.dumps(d, indent=2), encoding="utf-8")


def main() -> int:
    if len(sys.argv) < 2:
        print("Usage: rejudge_specgen_strict.py <case_root>", file=sys.stderr)
        return 1
    root = Path(sys.argv[1])
    if not root.is_dir():
        print(f"Not a dir: {root}", file=sys.stderr); return 1
    case_dirs = sorted([d for d in root.iterdir() if d.is_dir() and d.name.isdigit()],
                       key=lambda p: int(p.name))
    print(f"Re-judging {len(case_dirs)} case dirs under {root}")
    print(f"Strict openjml flags: {' '.join(STRICT_FLAGS)}")
    workers = int(os.environ.get("WORKERS", "16"))
    results = []
    with ThreadPoolExecutor(max_workers=workers) as ex:
        futures = {ex.submit(strict_judge_one, d): d for d in case_dirs}
        for i, fut in enumerate(as_completed(futures), 1):
            cd = futures[fut]
            try:
                r = fut.result()
            except Exception as e:
                r = {"case_id": cd.name, "strict_valid_pass": False,
                     "note": f"crash: {e}", "strict_openjml_output": "",
                     "strict_openjml_returncode": -3}
            merge_into_summary(cd, r)
            results.append(r)
            mark = "VALID" if r["strict_valid_pass"] else "fail "
            note = f"  {r.get('note')}" if r.get("note") else ""
            print(f"[{i:3d}/{len(case_dirs)}] case {r['case_id']:>3s} [{mark}]{note}")
    strict_n = sum(1 for r in results if r["strict_valid_pass"])
    print(f"\nStrict valid: {strict_n}/{len(results)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
