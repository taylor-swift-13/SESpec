#!/usr/bin/env python3
"""Pairwise specification strength judge for gpt-5 (new paper_data layout).

For each baseline ∈ {AutoSpec, SpecGen} and each case where both
SESpec gpt-5 AND baseline gpt-5 produced a verified spec, call the judge model
(gpt-5.4-mini) to compare explicit preconditions and postconditions using
strict contract refinement, with an invariants-only fallback for pairs that
lack substantive function preconditions and postconditions on both sides.

Outputs:
  RESULTS/paper_data/judge_gpt5/vs_autospec.csv   (per-case verdicts)
  RESULTS/paper_data/judge_gpt5/vs_specgen.csv
  RESULTS/paper_data/judge_gpt5/summary.csv       (counts per baseline)

Usage:
  OPENAI_API_KEY=... python tools/judge_stronger.py [--limit N]
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import sys
import time
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

from openai import OpenAI

REPO = Path("/home/yangfp/SESpec")
PD = REPO / "RESULTS" / "paper_data"
SESPEC_ROOT = PD / "SESpec" / "gpt-5"
AUTOSPEC_ROOT = PD / "AutoSpec" / "gpt-5"
SPECGEN_ROOT = PD / "SpecGen" / "gpt-5"
OUT_DIR = PD / "judge_gpt5"

BASE_URL = "https://yunwu.ai/v1"
JUDGE_MODEL = "gpt-5.4-mini"

from judge_prompts import CONTRACT_SYSTEM as JUDGE_SYSTEM, CONTRACT_TEMPLATE as JUDGE_USER_TEMPLATE, PROMPTS
from judge_routing import route_pair


def case_summary_valid(case_dir: Path) -> bool:
    sp = case_dir / "summary.json"
    if not sp.exists():
        return False
    try:
        return bool(json.loads(sp.read_text()).get("valid_pass"))
    except json.JSONDecodeError:
        return False


def sespec_spec(case_id: str) -> str | None:
    cd = SESPEC_ROOT / case_id
    if not cd.is_dir() or not case_summary_valid(cd):
        return None
    foo_files = sorted(cd.glob("foo*.c"))
    # exclude .loop.c / .qcp.c — keep the final ACSL-annotated C
    foo_files = [f for f in foo_files if not f.name.endswith(".loop.c") and not f.name.endswith(".qcp.c")]
    if not foo_files:
        return None
    return foo_files[0].read_text(errors="replace")


def autospec_spec(case_id: str) -> str | None:
    cd = AUTOSPEC_ROOT / case_id
    if not cd.is_dir() or not case_summary_valid(cd):
        return None
    # Try flat: sespec_XXXX_merged.c
    merged = list(cd.glob("*_merged.c"))
    if merged:
        return merged[0].read_text(errors="replace")
    # Try subdir
    aout = cd / "autospec_out"
    if aout.is_dir():
        merged = list(aout.glob("*_merged.c"))
        if merged:
            return merged[0].read_text(errors="replace")
    return None


def specgen_spec(case_id: str) -> str | None:
    """Extract final Java spec from SpecGen iteration log (last code block)."""
    cd = SPECGEN_ROOT / case_id
    if not cd.is_dir() or not case_summary_valid(cd):
        return None
    logs = sorted(cd.glob("log-*-*.txt"))
    if not logs:
        return None
    text = logs[-1].read_text(errors="replace")
    blocks = [b.strip() for b in text.split("==============================") if b.strip()]
    code_blocks = [b for b in blocks if re.search(r"\bclass\s+\w+", b) and "{" in b]
    if not code_blocks:
        return None
    return code_blocks[-1]


def read_clamped(text: str, max_chars: int = 8000) -> str:
    if len(text) > max_chars:
        return text[:max_chars] + "\n/* ... truncated ... */\n"
    return text


def make_client() -> OpenAI:
    return OpenAI(api_key=os.environ["OPENAI_API_KEY"], base_url=BASE_URL)


def parse_reply(raw: str) -> dict:
    raw = raw.strip()
    raw = re.sub(r"^```(?:json)?\s*", "", raw)
    raw = re.sub(r"\s*```$", "", raw)
    try:
        return json.loads(raw)
    except Exception:
        return {"verdict": "parse_error", "reason": raw[:200]}


def judge_one(client: OpenAI, spec_a: str, spec_b: str, tool_a: str, lang_a: str,
              target_a: str | None = None, target_b: str | None = None) -> dict:
    route = route_pair(spec_a, spec_b, lang_a, target_a, target_b)
    basis = route['comparison_basis']
    system, template = PROMPTS[basis]
    prompt = template.format(lang_a=lang_a, spec_a=spec_a, spec_b=spec_b)
    if target_a and target_b:
        prompt += f'\nTarget functions: A = {target_a}; B = {target_b}. Judge only these target functions.\n'
    resp = client.chat.completions.create(
        model=JUDGE_MODEL,
        messages=[
            {"role": "system", "content": system},
            {"role": "user", "content": prompt},
        ],
        max_tokens=2048,
    )
    result = parse_reply(resp.choices[0].message.content)
    result['comparison_basis'] = basis
    return result


def collect_both_pass(baseline: str) -> list[str]:
    """case_ids where both SESpec gpt-5 and baseline gpt-5 produced a valid spec."""
    if baseline == "AutoSpec":
        get_spec = autospec_spec
    elif baseline == "SpecGen":
        get_spec = specgen_spec
    else:
        raise ValueError(baseline)
    case_ids = []
    for cdir in sorted(SESPEC_ROOT.iterdir(), key=lambda p: int(p.name) if p.name.isdigit() else 1 << 30):
        if not cdir.is_dir() or not cdir.name.isdigit():
            continue
        cid = cdir.name
        if sespec_spec(cid) is None:
            continue
        if get_spec(cid) is None:
            continue
        case_ids.append(cid)
    return case_ids


def run_baseline(client: OpenAI, baseline: str, limit: int | None) -> dict:
    case_ids = collect_both_pass(baseline)
    if limit:
        case_ids = case_ids[:limit]
    print(f"  {baseline}: {len(case_ids)} both-pass cases")
    out_csv = OUT_DIR / f"vs_{baseline.lower()}.csv"
    out_csv.parent.mkdir(parents=True, exist_ok=True)
    spec_fn = autospec_spec if baseline == "AutoSpec" else specgen_spec
    lang_a = "c" if baseline == "AutoSpec" else "java"
    rows = []
    counts = {"B_stronger": 0, "A_stronger": 0, "equal": 0, "incomparable": 0, "parse_error": 0}

    def task(cid):
        spec_a = spec_fn(cid)
        spec_b = sespec_spec(cid)
        try:
            v = judge_one(client, spec_a, spec_b, baseline, lang_a)
        except Exception as e:
            return cid, {"verdict": "parse_error", "reason": f"api_error: {e}"}
        return cid, v

    with ThreadPoolExecutor(max_workers=8) as ex:
        futures = {ex.submit(task, c): c for c in case_ids}
        for i, fut in enumerate(as_completed(futures), 1):
            cid, v = fut.result()
            verdict = v.get("verdict", "parse_error")
            counts[verdict] = counts.get(verdict, 0) + 1
            rows.append({"case_id": cid, "verdict": verdict, "reason": v.get("reason", "")[:300]})
            if i % 20 == 0 or i == len(case_ids):
                print(f"    [{i}/{len(case_ids)}]")
    with out_csv.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["case_id", "verdict", "reason"])
        w.writeheader()
        w.writerows(sorted(rows, key=lambda r: int(r["case_id"])))
    print(f"  wrote {out_csv}")
    return {"baseline": baseline, "both_pass_total": len(case_ids), **counts}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--baselines", nargs="+", default=["AutoSpec", "SpecGen"])
    ap.add_argument("--limit", type=int, default=None)
    args = ap.parse_args()

    client = make_client()
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    summary_rows = []
    for baseline in args.baselines:
        r = run_baseline(client, baseline, args.limit)
        summary_rows.append(r)
    summary_csv = OUT_DIR / "summary.csv"
    with summary_csv.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["baseline", "both_pass_total",
                                          "B_stronger", "A_stronger", "equal",
                                          "incomparable", "parse_error"])
        w.writeheader()
        w.writerows(summary_rows)
    print(f"\n=== judge_gpt5 summary ===\n  {summary_csv}")
    for r in summary_rows:
        n = r["both_pass_total"]
        bs = r.get("B_stronger", 0); as_ = r.get("A_stronger", 0)
        eq = r.get("equal", 0); ic = r.get("incomparable", 0); pe = r.get("parse_error", 0)
        bp = round(bs / n * 100, 1) if n else 0
        ap_ = round(as_ / n * 100, 1) if n else 0
        print(f"  {r['baseline']:10s}  both-valid {n:4d}  "
              f"SESpec_stronger {bs:3d} ({bp:5.1f}%)  baseline_stronger {as_:3d} ({ap_:5.1f}%)  "
              f"equal {eq:3d}  incomparable {ic:3d}  parse_error {pe:3d}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
