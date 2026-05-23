#!/usr/bin/env python3
"""Reorganize RESULTS/paper_data into a flat layout: <Method>/<model>/<case>/.

Target structure:
  paper_data/
    inputs/                                  # 400 .c sources
    java_inputs/                             # ~400 .java (java_flat + java_flat_extra)
    AutoSpec/         {model}/{case}/...
    SpecGen/          {model}/{case}/...     # NOTE: gpt-5 populated by chained watcher AFTER SpecGen rerun
    LLM-C/            {model}/{case}/...
    SESpec/           {model}/{case}/...     # merges sespec/ + sespec_rerun_65/
    SESpec_no_refine/ {model}/{case}/...
    aggregate.csv
    backfill_manifest.csv
    slim_manifest.csv
    README.md

Old sespec_400/* and sespec_400_gpt5/* dirs are renamed to _archive_old_layout_*
once everything has been moved.
"""
from __future__ import annotations

import json
import shutil
import sys
from pathlib import Path

PD = Path("/home/yangfp/SESpec/RESULTS/paper_data")
OLD_300 = PD / "sespec_400"
OLD_G5 = PD / "sespec_400_gpt5"

# (target_method_dir, old_300_dir, old_g5_dir, sespec_rerun_65?)
METHODS = [
    ("AutoSpec",         "autospec",         "autospec",         False),
    ("SpecGen",          "specgen",          "specgen",          False),
    ("LLM-C",            "sespec_pure_llm",  "bare_model_c",     False),
    ("SESpec_no_refine", "sespec_no_refine", "sespec_no_repair", False),
    ("SESpec",           "sespec",           "sespec",           True),  # plus sespec_rerun_65
]
MODELS_3 = ["gpt-4o", "gpt-5-mini", "gpt-5.4-mini"]


def safe_mv(src: Path, dest: Path):
    if not src.is_dir():
        return False
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists():
        # Merge: move children
        for c in src.iterdir():
            target = dest / c.name
            if target.exists():
                continue  # keep existing target
            shutil.move(str(c), str(target))
        try: src.rmdir()
        except OSError: pass
    else:
        shutil.move(str(src), str(dest))
    return True


def reorganize() -> None:
    # 1) Top-level shared inputs (consolidate to one location)
    inputs = PD / "inputs"
    inputs.mkdir(exist_ok=True)
    g5_inputs = OLD_G5 / "inputs"
    if g5_inputs.is_dir():
        for f in g5_inputs.iterdir():
            target = inputs / f.name
            if not target.exists():
                shutil.move(str(f), str(target))
        try: g5_inputs.rmdir()
        except OSError: pass

    # 2) Java inputs (java_flat + java_flat_extra contents)
    java_inputs = PD / "java_inputs"
    java_inputs.mkdir(exist_ok=True)
    # link (not copy) java_flat to save space
    flat = Path("/home/yangfp/Arc/represent/bench/java_flat")
    extra = Path("/home/yangfp/Arc/represent/bench/java_flat_extra")
    if flat.is_dir():
        (java_inputs / "_java_flat_link").symlink_to(flat) if not (java_inputs / "_java_flat_link").exists() else None
    if extra.is_dir():
        (java_inputs / "_java_flat_extra_link").symlink_to(extra) if not (java_inputs / "_java_flat_extra_link").exists() else None

    # 3) Per-method × model moves
    for target_name, d300, dg5, use_rerun_65 in METHODS:
        target_root = PD / target_name
        target_root.mkdir(exist_ok=True)
        # 3-model
        for model in MODELS_3:
            src = OLD_300 / d300 / model
            if src.is_dir():
                safe_mv(src, target_root / model)
        # Supplementary sespec_rerun_65 → merge into SESpec/<model>/<case>
        if use_rerun_65:
            for model in MODELS_3:
                src = OLD_300 / "sespec_rerun_65" / model
                if src.is_dir():
                    dest = target_root / model
                    dest.mkdir(parents=True, exist_ok=True)
                    for cdir in src.iterdir():
                        tdir = dest / cdir.name
                        if not tdir.exists():
                            shutil.move(str(cdir), str(tdir))
                    try: src.rmdir()
                    except OSError: pass
        # gpt-5
        if target_name == "SpecGen":
            # Don't move gpt-5 dir yet — chained watcher needs current paths.
            # The watcher will mv specgen_full400/gpt-5 → SpecGen/gpt-5 after rerun finishes.
            continue
        src = OLD_G5 / dg5 / "gpt-5"
        if src.is_dir():
            safe_mv(src, target_root / "gpt-5")
        # Carry per_case.csv if it exists at the 3-model dir
        for p in [(OLD_300 / d300 / "per_case.csv"), (OLD_G5 / dg5 / "per_case.csv")]:
            if p.is_file():
                target = target_root / p.name
                if not target.exists():
                    shutil.move(str(p), str(target))

    # 4) Move SpecGen-related staging dirs (still being written or just finished)
    #    Leave specgen_full400 in OLD_G5 — chained watcher operates on that path
    for keep in ["specgen_full400", "specgen", "arc_mapping.csv", "extra_java_mapping.csv",
                 "manifest.csv", "_archive_specgen_full400_iter1_010708", "_archive_pre_20260518_232047",
                 "_archive_wrong_stem_20260517_fillin65", "README.md"]:
        # leave them; do not move
        pass

    # 5) Move/keep top-level files
    for f in ["aggregate_4models.csv", "aggregate.csv"]:
        src = OLD_300 / f
        if src.is_file():
            target = PD / f
            if not target.exists():
                shutil.move(str(src), str(target))


if __name__ == "__main__":
    reorganize()
    print("Reorganization complete. New layout:")
    for p in sorted(PD.iterdir()):
        if p.is_dir():
            n = sum(1 for _ in p.rglob("*") if _.is_file())
            print(f"  {p.name}/  ({n} files)")
        else:
            print(f"  {p.name}")
