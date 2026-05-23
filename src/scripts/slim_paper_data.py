#!/usr/bin/env python3
"""Slim per-case dirs under RESULTS/paper_data to essentials only.

Per (method, model, case) we keep:
  - summary.json (always)
  - the FINAL generated artifact (one .c or .java)
  - ONE log file
  - (SESpec methods are already minimal: keep all 4 files foo*.{c,log,loop.c,qcp.c})

Everything else (intermediate iterations, raw_response.json, api_key.txt,
usage.jsonl, command.step_NNN.log for non-final steps, etc.) is deleted.

Writes a slim_manifest.csv listing removed files for traceability.
"""
from __future__ import annotations

import csv
import json
import os
import re
import shutil
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]
PD = REPO_ROOT / "RESULTS" / "paper_data"
SLIM_MANIFEST = PD / "slim_manifest.csv"

removed_rows: list[dict] = []


def _record(method, model, case_id, action, target_path, reason=""):
    removed_rows.append({
        "method": method, "model": model, "case_id": case_id,
        "action": action, "target_path": str(target_path), "reason": reason,
    })


def _delete(p: Path, method, model, case_id, reason="redundant"):
    if p.is_dir():
        shutil.rmtree(p, ignore_errors=True)
    elif p.is_file():
        try:
            p.unlink()
        except OSError:
            pass
    _record(method, model, case_id, "removed", p, reason)


def slim_autospec(case_dir: Path, method, model, case_id):
    """Keep: summary.json, the FINAL merged .c, the final Pass/Fail/Invalid txt, ONE log.

    Handles two layouts:
      - 3-model: files are inside `case_dir/autospec_out/` subdir.
      - gpt-5:   files are flat in `case_dir/` (my backfill flattened autospec_out).
    """
    keep = {"summary.json"}
    # Search BOTH flat and subdir
    search_dirs = [case_dir]
    aout = case_dir / "autospec_out"
    if aout.is_dir():
        search_dirs.append(aout)
    for sd in search_dirs:
        prefix = "" if sd == case_dir else f"{sd.name}/"
        merged_c = list(sd.glob("*_merged.c"))
        if merged_c:
            keep.add(f"{prefix}{merged_c[0].name}")
        # Result txt — pick the LAST by mtime
        result_files = sorted(
            list(sd.glob("*_Pass_*.txt")) +
            list(sd.glob("*_Fail_*.txt")) +
            list(sd.glob("*_Invalid*.txt")) +
            list(sd.glob("*_merged_Pass_*.txt")),
            key=lambda p: p.stat().st_mtime,
        )
        if result_files:
            keep.add(f"{prefix}{result_files[-1].name}")
    # One log: prefer top-level command.log, else last command.step_NNN.log
    if (case_dir / "command.log").exists():
        keep.add("command.log")
    else:
        step_logs = sorted(case_dir.glob("command.step_*.log"),
                           key=lambda p: int(re.search(r'\d+', p.name).group()))
        if step_logs:
            keep.add(step_logs[-1].name)
    # Delete everything else
    for f in case_dir.rglob("*"):
        if f.is_file():
            rel = f.relative_to(case_dir).as_posix()
            if rel not in keep:
                _delete(f, method, model, case_id)
    # Remove empty subdirs
    for d in sorted(case_dir.rglob("*"), reverse=True):
        if d.is_dir() and not any(d.iterdir()):
            try: d.rmdir()
            except OSError: pass


def slim_specgen(case_dir: Path, method, model, case_id):
    """Keep: summary.json, ONE log-*-*.txt (iteration log), one input .java (if present)."""
    keep = {"summary.json"}
    # Latest iteration log
    iter_logs = sorted(case_dir.glob("log-*-*.txt"), key=lambda p: p.stat().st_mtime)
    if iter_logs:
        keep.add(iter_logs[-1].name)
    # If specgen_input subdir has a Java, keep just that .java (flatten)
    inp = case_dir / "specgen_input"
    if inp.is_dir():
        java_files = list(inp.glob("*.java"))
        if java_files:
            target = case_dir / java_files[0].name
            if not target.exists():
                shutil.copy2(java_files[0], target)
            keep.add(java_files[0].name)
    # Also if there's a flattened *.java at top level, keep it
    for jf in case_dir.glob("*.java"):
        keep.add(jf.name)
    # If a "candidate.java" (input copy) was saved by my SpecGen-400 runner, keep it
    if (case_dir / "candidate.java").exists():
        keep.add("candidate.java")
    # Delete everything else
    for f in case_dir.rglob("*"):
        if f.is_file():
            rel = f.relative_to(case_dir).as_posix()
            base = f.name
            if base in keep or rel in keep:
                continue
            _delete(f, method, model, case_id)
    for d in sorted(case_dir.rglob("*"), reverse=True):
        if d.is_dir() and not any(d.iterdir()):
            try: d.rmdir()
            except OSError: pass


def slim_bare_model(case_dir: Path, method, model, case_id):
    """Keep: summary.json, candidate.c."""
    keep = {"summary.json", "candidate.c"}
    for f in case_dir.rglob("*"):
        if f.is_file():
            rel = f.relative_to(case_dir).as_posix()
            if rel in keep or f.name in keep:
                continue
            _delete(f, method, model, case_id)
    for d in sorted(case_dir.rglob("*"), reverse=True):
        if d.is_dir() and not any(d.iterdir()):
            try: d.rmdir()
            except OSError: pass


def slim_sespec(case_dir: Path, method, model, case_id):
    """SESpec already minimal: foo*.{c,log,loop.c,qcp.c} + summary.json. Drop command.log only."""
    cl = case_dir / "command.log"
    if cl.exists():
        _delete(cl, method, model, case_id)


HANDLERS = {
    "autospec":           slim_autospec,
    "specgen":            slim_specgen,
    "bare_model_c":       slim_bare_model,
    "sespec_pure_llm":    slim_bare_model,  # same shape — keep summary + maybe candidate.c
    "sespec":             slim_sespec,
    "sespec_no_refine":   slim_sespec,
    "sespec_no_repair":   slim_sespec,
}

# (method_canon, sespec_400 dir, sespec_400_gpt5 dir)
METHOD_DIRS = [
    ("AutoSpec",         "autospec",         "autospec"),
    ("SpecGen",          "specgen",          "specgen"),
    ("LLM-C",            "sespec_pure_llm",  "bare_model_c"),
    ("SESpec_no_refine", "sespec_no_refine", "sespec_no_repair"),
    ("SESpec",           "sespec",           "sespec"),
]
MODELS = ["gpt-4o", "gpt-5-mini", "gpt-5.4-mini", "gpt-5"]
SUPPLEMENTARY = {
    "sespec_400/sespec":      ["sespec_400/sespec_rerun_65"],
}


def case_roots(method, model) -> list[tuple[Path, str]]:
    """All case dir roots for (method, model), with the dirname for handler lookup."""
    _, d300, dg5 = next(m for m in METHOD_DIRS if m[0] == method)
    out = []
    if model == "gpt-5":
        out.append((PD / "sespec_400_gpt5" / dg5 / "gpt-5", dg5))
    else:
        out.append((PD / "sespec_400" / d300 / model, d300))
        # Supplementary (SESpec rerun_65)
        if method == "SESpec":
            out.append((PD / "sespec_400" / "sespec_rerun_65" / model, "sespec"))
    return out


def main() -> int:
    for method, _, _ in METHOD_DIRS:
        for model in MODELS:
            for root, handler_key in case_roots(method, model):
                if not root.is_dir():
                    continue
                handler = HANDLERS.get(handler_key)
                if not handler:
                    continue
                n_pre = sum(1 for _ in root.rglob("*") if _.is_file())
                for cdir in sorted(root.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else 1 << 30):
                    if not cdir.is_dir():
                        continue
                    handler(cdir, method, model, cdir.name)
                n_post = sum(1 for _ in root.rglob("*") if _.is_file())
                print(f"  {method:18s}/{model:14s}  ({handler_key:18s})  "
                      f"files: {n_pre:5d} → {n_post:5d}   (-{n_pre - n_post})")
    SLIM_MANIFEST.parent.mkdir(parents=True, exist_ok=True)
    with SLIM_MANIFEST.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["method", "model", "case_id", "action",
                                          "target_path", "reason"])
        w.writeheader()
        w.writerows(removed_rows)
    print(f"\nSlim manifest: {SLIM_MANIFEST}  ({len(removed_rows)} removed entries)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
