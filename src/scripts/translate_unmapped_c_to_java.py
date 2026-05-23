#!/usr/bin/env python3
"""Translate unmapped SESpec C cases to Java for SpecGen evaluation.

For the 48 sespec cases not in arc_mapping.csv (mostly multifunc / helper-introduced
SESpec variants), use gpt-5 to produce a Java equivalent so SpecGen can be run.

Output:
  /home/yangfp/Arc/represent/bench/java_flat_extra/sespec_<NNNN>.java
  RESULTS/paper_data/sespec_400_gpt5/extra_java_mapping.csv
"""
from __future__ import annotations

import csv
import os
import re
import sys
import time
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor, as_completed

from openai import OpenAI

REPO_ROOT = Path(__file__).resolve().parents[2]
ARC_MAPPING = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5" / "arc_mapping.csv"
C_INPUT_DIR = REPO_ROOT / "src" / "input" / "sespec"
JAVA_OUT_DIR = Path("/home/yangfp/Arc/represent/bench/java_flat_extra")
EXTRA_MAPPING = REPO_ROOT / "RESULTS" / "paper_data" / "sespec_400_gpt5" / "extra_java_mapping.csv"

SYSTEM_PROMPT = """You translate small C functions to Java for OpenJML-based spec generation.
RULES:
1. Output a single `class <Name> { ... }` block with all functions as `static`.
2. The class name must be a short, valid Java identifier (one word, no underscores in middle is fine).
3. The file MUST be named `<ClassName>.java` (we will write it for you; just emit the class).
4. Use `static int` / `static void` etc. for the original C function signatures.
5. Translate pointers: `int *a, int a_len` → `int[] a` (a_len becomes a.length when used).
6. Drop `#include`s, `extern` declarations, and `static`/`extern` storage qualifiers.
7. Preserve all behavior — same loops, conditionals, recursion. NO new logic, NO comments.
8. If the C uses `unknown()` (nondeterminism), translate as a parameter or an external static method `static int unknown()` declared with empty body and `return 0;`.
9. ONLY emit Java code — no explanation, no markdown fences.
"""

USER_TEMPLATE = """Translate this C code to a single Java class. Use this exact class name: {class_name}

C CODE:
```c
{c_code}
```
"""


_client = None
def _get_client():
    global _client
    if _client is None:
        _client = OpenAI(api_key=os.environ["OPENAI_API_KEY"],
                          base_url=os.environ.get("OPENAI_BASE_URL", "https://yunwu.ai/v1"))
    return _client


def call_openai(c_code: str, class_name: str) -> str:
    resp = _get_client().chat.completions.create(
        model="gpt-5",
        messages=[
            {"role": "system", "content": SYSTEM_PROMPT},
            {"role": "user", "content": USER_TEMPLATE.format(c_code=c_code, class_name=class_name)},
        ],
    )
    return resp.choices[0].message.content


def extract_class(text: str, fallback_class_name: str) -> str:
    # Strip markdown fences if any
    text = re.sub(r"^```(?:java)?\s*", "", text.strip())
    text = re.sub(r"```\s*$", "", text.strip())
    # Ensure the class name in code matches what we asked for
    text = re.sub(r"\bclass\s+\w+", f"class {fallback_class_name}", text, count=1)
    return text.strip() + "\n"


def class_name_for_case(case_id: str) -> str:
    return f"Sespec{int(case_id):04d}"


def translate_one(case_id: str, c_path: Path) -> dict:
    cls = class_name_for_case(case_id)
    java_path = JAVA_OUT_DIR / f"{cls}.java"
    if java_path.exists() and java_path.stat().st_size > 0:
        return {"case_id": case_id, "java_path": str(java_path), "class_name": cls, "status": "cached"}
    c_code = c_path.read_text(encoding="utf-8")
    try:
        raw = call_openai(c_code, cls)
    except Exception as e:
        return {"case_id": case_id, "java_path": "", "class_name": cls, "status": f"error: {e}"}
    java_code = extract_class(raw, cls)
    JAVA_OUT_DIR.mkdir(parents=True, exist_ok=True)
    java_path.write_text(java_code, encoding="utf-8")
    return {"case_id": case_id, "java_path": str(java_path), "class_name": cls, "status": "translated"}


def unmapped_cases() -> list[str]:
    mapped = set()
    with ARC_MAPPING.open(encoding="utf-8") as f:
        for r in csv.DictReader(f):
            mapped.add(r["sespec_new_id"])
    return sorted([str(i) for i in range(400) if str(i) not in mapped], key=int)


def main() -> int:
    if "OPENAI_API_KEY" not in os.environ:
        print("OPENAI_API_KEY not set", file=sys.stderr)
        return 1
    cases = unmapped_cases()
    print(f"Translating {len(cases)} unmapped cases…")
    results = []
    t0 = time.time()
    with ThreadPoolExecutor(max_workers=12) as ex:
        futures = {ex.submit(translate_one, c, C_INPUT_DIR / f"{c}.c"): c for c in cases}
        for fut in as_completed(futures):
            r = fut.result()
            results.append(r)
            print(f"  [{r['status']:>11s}] case {r['case_id']:>3s} → {r['java_path']}")
    elapsed = time.time() - t0
    print(f"\nDone in {elapsed:.1f}s")

    EXTRA_MAPPING.parent.mkdir(parents=True, exist_ok=True)
    with EXTRA_MAPPING.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["sespec_new_id", "class_name", "java_path", "status"])
        w.writeheader()
        for r in sorted(results, key=lambda x: int(x["case_id"])):
            w.writerow({"sespec_new_id": r["case_id"], "class_name": r["class_name"],
                        "java_path": r["java_path"], "status": r["status"]})
    print(f"Wrote {EXTRA_MAPPING}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
