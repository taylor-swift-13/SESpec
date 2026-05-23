#!/usr/bin/env python3
"""Backfill per-case artifacts (logs + generated code) into RESULTS/paper_data.

For each (method, model, case) where summary.json exists, copies the relevant
artifact files (log, generated .c, candidate.c, etc.) from their original source
location next to the summary.json.

Source heuristics per method:
  - SESpec / SESpec_no_refine: summary.json contains log_path/output_path/
    loop_qcp_path/loop_acsl_path pointing to a matrix_run subdir. Copy those.
  - AutoSpec (gpt-5): summary.json has output_dir pointing to the autospec_out
    directory; copy its contents.
  - AutoSpec (3-model): legacy summary has no paths → skip with a note.
  - SpecGen (gpt-5): summary.json has log_path pointing to external logs/.
    Copy that log + the Java input file.
  - SpecGen (3-model): log_path = None → skip with a note.
  - LLM-C (bare_model_c) gpt-5: summary.json has candidate_path; also copy
    usage.jsonl if present.
  - LLM-C (3-model sespec_pure_llm / sespec_no_se_no_exm_no_repair): legacy
    summary has no paths → fall back to /Arc/represent/results/smoke/bare_model/c/
    <model>/<arc_stem>/ via arc_mapping if available.
"""
from __future__ import annotations

import csv
import json
import os
import shutil
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]
PD_300 = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400"
PD_GPT5 = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5"
ARC_BARE_ROOT = Path("/home/yangfp/Arc/represent/results/smoke/bare_model/c")
ARC_AUTOSPEC_ROOT = Path("/home/yangfp/Arc/represent/results/smoke/autospec/one_shot")
ARC_SPECGEN_ROOT = Path("/home/yangfp/Arc/represent/results/smoke/specgen")
ARC_MAPPING_CSV = Path("/home/yangfp/SESpec/RESULTS/paper_data/sespec_400_gpt5/arc_mapping.csv")
SPECGEN_LOGS = REPO_ROOT / "represent" / "external" / "specgen-artifact" / "logs"
JAVA_FLAT_ROOT = Path("/home/yangfp/Arc/represent/bench/java_flat")
C_FLAT_ROOT = Path("/home/yangfp/Arc/represent/bench/c_flat")

_arc_stem_by_sespec_id: dict[str, str] = {}
def _load_arc_mapping():
    if _arc_stem_by_sespec_id:
        return
    if ARC_MAPPING_CSV.exists():
        with ARC_MAPPING_CSV.open(encoding="utf-8") as f:
            for r in csv.DictReader(f):
                _arc_stem_by_sespec_id[r["sespec_new_id"]] = r["arc_stem"]

# (method_canonical, sespec_400_dir, sespec_400_gpt5_dir)
METHODS = [
    ("AutoSpec",         "autospec",                       "autospec"),
    ("SpecGen",          "specgen",                        "specgen"),
    ("LLM-C",            "sespec_pure_llm",                "bare_model_c"),
    ("SESpec_no_refine", "sespec_no_refine",               "sespec_no_repair"),
    ("SESpec",           "sespec",                         "sespec"),
]
MODELS = ["gpt-4o", "gpt-5-mini", "gpt-5.4-mini", "gpt-5"]

# Counters
stats = {"copied": 0, "skipped_no_source": 0, "already_present": 0, "method_skip": 0}

# Traceability manifest: list of dicts with source provenance per backfilled file
manifest_rows: list[dict] = []


def case_dir(method_canon: str, model: str) -> Path:
    _, d300, dg5 = next(m for m in METHODS if m[0] == method_canon)
    if model == "gpt-5":
        return PD_GPT5 / dg5 / "gpt-5"
    return PD_300 / d300 / model


_CURR = {"method": "", "model": "", "case_id": ""}  # active provenance context


def _trace(src: Path, target: Path, status: str, role: str = "artifact") -> None:
    manifest_rows.append({
        "method": _CURR["method"], "model": _CURR["model"], "case_id": _CURR["case_id"],
        "role": role, "source_path": str(src) if src else "",
        "target_path": str(target), "status": status,
    })


def safe_copy(src: Path, dest_dir: Path, *, skip_if_present: bool = True,
              role: str = "artifact") -> bool:
    if not src or not src.exists() or not src.is_file():
        _trace(src, dest_dir / (src.name if src else "?"), "src_missing", role)
        return False
    target = dest_dir / src.name
    if skip_if_present and target.exists():
        stats["already_present"] += 1
        _trace(src, target, "already_present", role)
        return True
    dest_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, target)
    stats["copied"] += 1
    _trace(src, target, "copied", role)
    return True


def safe_copy_tree_contents(src_dir: Path, dest_dir: Path, role: str = "artifact") -> int:
    """Copy contents (files only) of src_dir into dest_dir. Returns count."""
    if not src_dir.is_dir():
        _trace(src_dir, dest_dir, "src_missing", role)
        return 0
    n = 0
    dest_dir.mkdir(parents=True, exist_ok=True)
    for f in src_dir.iterdir():
        if not f.is_file():
            continue
        if f.name in {"command.log"}:
            continue
        target = dest_dir / f.name
        if target.exists():
            stats["already_present"] += 1
            _trace(f, target, "already_present", role)
            continue
        shutil.copy2(f, target)
        stats["copied"] += 1
        _trace(f, target, "copied", role)
        n += 1
    return n


def backfill_sespec_like(method_canon: str, model: str) -> int:
    """SESpec and SESpec_no_refine: summary.json points at matrix_run subdir."""
    root = case_dir(method_canon, model)
    if not root.is_dir():
        return 0
    n = 0
    for cdir in root.iterdir():
        if not cdir.is_dir():
            continue
        sp = cdir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        for k in ("log_path", "output_path", "loop_qcp_path", "loop_acsl_path"):
            p = d.get(k)
            if p:
                if safe_copy(Path(p), cdir):
                    n += 1
            elif p is None:
                pass  # missing artifact (e.g. crashed run); fine
    return n


def backfill_autospec(method_canon: str, model: str) -> int:
    """AutoSpec gpt-5: copy contents of autospec_out/ dir. 3-model: legacy, skip."""
    root = case_dir(method_canon, model)
    if not root.is_dir():
        return 0
    n = 0
    if model != "gpt-5":
        # legacy summary has no path info → mark skipped
        stats["method_skip"] += sum(1 for _ in root.iterdir() if _.is_dir())
        return 0
    for cdir in root.iterdir():
        if not cdir.is_dir():
            continue
        sp = cdir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        od = d.get("output_dir")
        if od:
            n += safe_copy_tree_contents(Path(od), cdir)
    return n


def backfill_specgen(method_canon: str, model: str) -> int:
    """SpecGen gpt-5: log_path is set. 3-model: legacy, skip."""
    root = case_dir(method_canon, model)
    if not root.is_dir():
        return 0
    n = 0
    if model != "gpt-5":
        stats["method_skip"] += sum(1 for _ in root.iterdir() if _.is_dir())
        return 0
    for cdir in root.iterdir():
        if not cdir.is_dir():
            continue
        sp = cdir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        lp = d.get("log_path")
        if lp and safe_copy(Path(lp), cdir):
            n += 1
        # Also copy the Java input for context
        bm = d.get("benchmark")
        if bm and safe_copy(Path(bm), cdir):
            n += 1
    return n


def backfill_bare(method_canon: str, model: str) -> int:
    """LLM-C bare model: gpt-5 has candidate_path; 3-model falls back to arc dir."""
    root = case_dir(method_canon, model)
    if not root.is_dir():
        return 0
    n = 0
    arc_map = {}  # sespec_id → arc_stem
    arc_csv = PD_GPT5 / "arc_mapping.csv"
    if arc_csv.exists():
        with arc_csv.open(encoding="utf-8") as f:
            for r in csv.DictReader(f):
                arc_map[r["sespec_new_id"]] = r["arc_stem"]
    for cdir in root.iterdir():
        if not cdir.is_dir():
            continue
        sp = cdir / "summary.json"
        if not sp.exists():
            continue
        try:
            d = json.loads(sp.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        # gpt-5 modern: candidate_path + usage.jsonl + source
        cp = d.get("candidate_path")
        if cp and safe_copy(Path(cp), cdir):
            n += 1
            # try usage.jsonl in same dir
            ujson = Path(cp).parent / "usage.jsonl"
            if ujson.exists() and safe_copy(ujson, cdir):
                n += 1
        else:
            # 3-model: try /Arc/.../bare_model/c/<model>/<sespec_NNNN>/candidate.c
            sespec_id = cdir.name
            case_padded = f"sespec_{int(sespec_id):04d}"
            arc_stem = arc_map.get(sespec_id)
            for stem in (case_padded, arc_stem):
                if not stem:
                    continue
                arc_case = ARC_BARE_ROOT / model / stem
                if arc_case.is_dir():
                    n += safe_copy_tree_contents(arc_case, cdir)
                    break
            else:
                stats["skipped_no_source"] += 1
    return n


HANDLERS = {
    "SESpec": backfill_sespec_like,
    "SESpec_no_refine": backfill_sespec_like,
    "AutoSpec": backfill_autospec,
    "SpecGen": backfill_specgen,
    "LLM-C": backfill_bare,
}


def _wrap_handler(method_canon, model, handler):
    """Set provenance context and call handler. Iterate per case for richer manifest."""
    root = case_dir(method_canon, model)
    for cdir in sorted(root.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else 1 << 30):
        if not cdir.is_dir():
            continue
        _CURR["method"] = method_canon
        _CURR["model"] = model
        _CURR["case_id"] = cdir.name
        # Per-case rather than per-method dispatch: re-implement core
        _backfill_one_case(method_canon, model, cdir)


def _backfill_one_case(method: str, model: str, cdir: Path) -> None:
    sp = cdir / "summary.json"
    if not sp.exists():
        return
    try:
        d = json.loads(sp.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return

    if method in ("SESpec", "SESpec_no_refine"):
        for k, role in [("log_path", "log"), ("output_path", "spec_c"),
                        ("loop_qcp_path", "qcp"), ("loop_acsl_path", "loop_acsl")]:
            p = d.get(k)
            if p:
                safe_copy(Path(p), cdir, role=role)
    elif method == "AutoSpec":
        if model == "gpt-5":
            od = d.get("output_dir")
            if od:
                safe_copy_tree_contents(Path(od), cdir, role="autospec_out")
        else:
            # 3-model: source under /Arc/.../smoke/autospec/one_shot/<model>/<archive_case_id>/
            arc_id = d.get("archive_case_id")
            if arc_id:
                src = ARC_AUTOSPEC_ROOT / model / arc_id
                if src.is_dir():
                    safe_copy_tree_contents(src, cdir, role="autospec_artifacts")
                    # also copy autospec_out subdir contents (flatten)
                    sub_out = src / "autospec_out"
                    if sub_out.is_dir():
                        safe_copy_tree_contents(sub_out, cdir / "autospec_out", role="autospec_out")
                else:
                    stats["skipped_no_source"] += 1
                    _trace(src, cdir, "src_missing", "autospec_3model")
            else:
                stats["method_skip"] += 1
                _trace(None, cdir, "no_archive_id", "autospec_3model")
    elif method == "SpecGen":
        if model == "gpt-5":
            lp = d.get("log_path")
            if lp:
                safe_copy(Path(lp), cdir, role="specgen_log")
            bm = d.get("benchmark")
            if bm:
                safe_copy(Path(bm), cdir, role="java_input")
        else:
            # 3-model: source under /Arc/.../smoke/specgen/<model>/<arc_stem>/
            _load_arc_mapping()
            stem = _arc_stem_by_sespec_id.get(cdir.name)
            if stem:
                src = ARC_SPECGEN_ROOT / model / stem
                if src.is_dir():
                    safe_copy_tree_contents(src, cdir, role="specgen_artifacts")
                else:
                    stats["skipped_no_source"] += 1
                    _trace(src, cdir, "src_missing", "specgen_3model")
            else:
                stats["method_skip"] += 1
                _trace(None, cdir, "no_arc_stem", "specgen_3model")
    elif method == "LLM-C":
        cp = d.get("candidate_path")
        if cp and Path(cp).exists():
            safe_copy(Path(cp), cdir, role="candidate_c")
            ujson = Path(cp).parent / "usage.jsonl"
            if ujson.exists():
                safe_copy(ujson, cdir, role="usage_jsonl")
        else:
            # 3-model fallback: /Arc/.../bare_model/c/<model>/<archive_case_id>/
            # where archive_case_id is in the legacy summary (e.g., "SVCOMP_0001", "FormalBench_0237").
            arc_id = d.get("archive_case_id")
            if arc_id:
                arc_case = ARC_BARE_ROOT / model / arc_id
                if arc_case.is_dir():
                    safe_copy_tree_contents(arc_case, cdir, role="bare_model_artifacts")
                else:
                    stats["skipped_no_source"] += 1
                    _trace(arc_case, cdir, "src_missing", "llm_c_legacy")
            else:
                stats["skipped_no_source"] += 1
                _trace(None, cdir, "no_archive_id", "llm_c_legacy")


def main() -> int:
    for method_canon, _, _ in METHODS:
        for model in MODELS:
            root = case_dir(method_canon, model)
            if not root.is_dir():
                print(f"[skip] {method_canon}/{model}: no case dir")
                continue
            count_before = stats["copied"]
            _wrap_handler(method_canon, model, None)
            delta = stats["copied"] - count_before
            print(f"[done] {method_canon:18s}/{model:14s}: +{delta} copied   (root={root})")
    # Write manifest
    manifest_csv = REPO_ROOT / "RESULTS" / "paper_data" / "backfill_manifest.csv"
    manifest_csv.parent.mkdir(parents=True, exist_ok=True)
    with manifest_csv.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["method", "model", "case_id", "role",
                                          "source_path", "target_path", "status"])
        w.writeheader()
        w.writerows(manifest_rows)
    print(f"\nManifest written: {manifest_csv}  ({len(manifest_rows)} rows)")
    print(f"Totals: copied={stats['copied']}, already_present={stats['already_present']}, "
          f"skipped_no_source={stats['skipped_no_source']}, method_skip={stats['method_skip']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
