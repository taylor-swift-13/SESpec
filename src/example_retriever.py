"""Category-based example retrieval (replaces vector DB / chroma).

Programs get classified into one of five buckets by static inspection of the
source, then every `.c` file under `examples/<category>/` is returned
as the "Examples" block for the LLM prompt.

Categories (priority order):
  1. recursive_ds       — operates on a self-referential struct (linked list,
                          tree, etc.).
  2. recursive_program  — function body calls itself.
  3. array              — pointer parameter or `a[i]` index access.
  4. trivial            — scalar-only, no `*` / `/` / `%`. Covers
                          straight-line numeric code AND linear-numeric
                          loops (e.g. `x = x + y; y = y + 1`). NO examples
                          are injected and NO predicate / logic placeholder
                          is emitted in the file — these programs never
                          need user-defined helpers, and the generic
                          numeric patterns add noise without lift.
  5. numeric            — scalar with multiplicative / modular arithmetic
                          (gcd, sqrt, power, parity, ...). Examples apply.
"""
from __future__ import annotations

import re
from pathlib import Path
from typing import List, Tuple

EXAMPLES_ROOT = Path(__file__).resolve().parent / "examples"
CATEGORIES: Tuple[str, ...] = ("numeric", "array", "recursive_ds", "recursive_program", "trivial")

_C_KEYWORDS = {
    "if", "else", "while", "for", "do", "switch", "case", "default",
    "return", "sizeof", "typedef", "struct", "union", "enum", "goto",
    "break", "continue", "static", "extern", "const", "void",
}


def _strip_comments(src: str) -> str:
    src = re.sub(r"/\*[\s\S]*?\*/", "", src)
    src = re.sub(r"//.*", "", src)
    # Also strip string / char literal contents — characters inside `"..."`
    # or `'...'` (typically `#include "../foo.h"` or printf format strings)
    # can contain `/`, `*`, `%` and would mislead the classifier heuristics
    # below (especially `_has_complex_arithmetic`).
    src = re.sub(r'"(?:[^"\\]|\\.)*"', '""', src)
    src = re.sub(r"'(?:[^'\\]|\\.)*'", "''", src)
    return src


def _has_self_referential_struct(s: str) -> bool:
    """Detect `struct X { ... struct X *...; ... }` in the source."""
    for m in re.finditer(r"struct\s+(\w+)\s*\{([^}]*)\}", s):
        name, body = m.group(1), m.group(2)
        if re.search(rf"\bstruct\s+{re.escape(name)}\s*\*", body):
            return True
    return False


def _has_self_call(s: str) -> bool:
    """Detect a function whose body invokes itself (direct recursion)."""
    func_re = re.compile(
        r"(?:[A-Za-z_]\w*[ \t\*]+)+(?P<name>[A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{"
    )
    for m in func_re.finditer(s):
        name = m.group("name")
        if name in _C_KEYWORDS:
            continue
        body_start = m.end()
        depth = 1
        i = body_start
        n = len(s)
        while i < n and depth > 0:
            c = s[i]
            if c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
            i += 1
        body = s[body_start:i - 1]
        if re.search(rf"\b{re.escape(name)}\s*\(", body):
            return True
    return False


def _has_array_signature(s: str) -> bool:
    """Pointer parameter or array indexing both count as array shape."""
    if re.search(r"\b[A-Za-z_]\w*\s*\[\s*[A-Za-z_0-9 +\-*/]+\s*\]", s):
        return True
    if re.search(r"\b(int|char|float|double|long|short|unsigned|signed)\s*\*", s):
        return True
    return False


def _has_complex_arithmetic(s: str) -> bool:
    """Detect multiplicative / modular ops that take a function out of the
    linear-numeric regime: `*`, `/`, `%`. Caller must have already stripped
    comments and ruled out pointer / array signatures, so any `*` here is
    multiplication (not pointer deref) and any `/` is division (not the
    comment opener)."""
    return bool(re.search(r"[*/%]", s))


def classify(source: str) -> str:
    s = _strip_comments(source or "")
    if _has_self_referential_struct(s):
        return "recursive_ds"
    if _has_self_call(s):
        return "recursive_program"
    if _has_array_signature(s):
        return "array"
    if not _has_complex_arithmetic(s):
        return "trivial"
    return "numeric"


def load_category(category: str) -> List[str]:
    folder = EXAMPLES_ROOT / category
    if not folder.is_dir():
        return []
    return [p.read_text(encoding="utf-8") for p in sorted(folder.glob("*.c"))]


def load_category_hints(source: str) -> str:
    """Concatenate the universal hint block with the category-specific one
    selected by ``classify(source)``. Returns an empty string if both files
    are missing. Shared by spec_gen, convertor (specgen/refine), and error
    repair so every prompt sees the same category-specific guidance —
    previously only error.txt got this injection.
    """
    hints_dir = EXAMPLES_ROOT.parent / "prompt" / "error_hints"
    universal = ""
    try:
        universal = (hints_dir / "universal.txt").read_text(encoding="utf-8")
    except OSError:
        pass

    category = classify(source) if source else ""
    category_block = ""
    if category in CATEGORIES:
        try:
            category_block = (hints_dir / f"{category}.txt").read_text(encoding="utf-8")
        except OSError:
            pass

    parts = [p for p in (universal, category_block) if p]
    return "\n\n".join(parts)


def get_examples_for(source: str) -> Tuple[str, str]:
    """Return (category, formatted prompt block).

    `trivial` is intentionally skipped — the whole point of that bucket is
    to NOT pollute the prompt with the (gcd / sqrt / power / parity / ...)
    numeric invariants that have nothing to do with straight-line code or
    linear update loops. Returns an empty block so callers' `{examples}`
    slot substitutes to nothing.
    """
    category = classify(source)
    if category == "trivial":
        return category, ""
    files = load_category(category)
    contents = "\n\n".join(files) if files else "(no examples available)"
    block = f"""
Examples (category: {category}):
You must use these follow examples as a reference to complete the task, with the following requirements:
    - You may use the invariant generation logic from these examples as a guide for your own invariant.
    - You may directly use the predicates or functions defined in these examples.
    - You may refer to the patterns or ideas from these examples to create new predicates or functions.
    ```
    {contents}
    ```
"""
    return category, block
