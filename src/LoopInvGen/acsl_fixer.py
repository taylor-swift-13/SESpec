"""Deterministic ACSL syntax fixer.

Run as a pre-pass before the LLM-based `repair_annotations()` to handle a
handful of repeating syntax-error patterns observed in real sespec runs:

  1. `PLACE_HOLDER_*` template markers leaked through the LLM fill step.
  2. `\\result` used inside a `predicate <name>(...)` body
     (only valid in `ensures`).
  3. `assigns X, \\nothing, Y;` mixing `\\nothing` with real locations.
  4. `unexpected token 'const'` on an annotation line.
  5. `unexpected token ')'` paren mismatch on an annotation line.

Invariants:
  - Never edits text outside ACSL annotation spans (`/*@ ... */` or `//@ ...`).
  - Never inserts new clauses; only drops or rewrites existing ones.
  - Idempotent: re-running fix() on its own output is a no-op.
  - On any unrecognised pattern, returns input unchanged so the LLM fallback
    can take over.

Run the self-test with:  python -m LoopInvGen.acsl_fixer
"""

from __future__ import annotations

import logging
import re
from dataclasses import dataclass, field
from typing import Iterable, List, Tuple


@dataclass
class FixReport:
    annotations: str = ""
    fixes_applied: List[str] = field(default_factory=list)
    fully_handled: bool = False


_PH_INVARIANT_LINE = re.compile(
    r'^[ \t]*loop\s+invariant\s+PLACE_HOLDER_[A-Z_0-9]+\s*;.*$',
    re.MULTILINE,
)
_PH_BARE_TOKEN = re.compile(r'\bPLACE_HOLDER_[A-Z_0-9]+\b')
_PH_CLAUSE_KEYWORDS = ('loop invariant', 'loop assigns', 'requires',
                       'ensures', 'assert', 'assigns')

# Top-level ACSL definitions that end in `;` (no `{...}` body) — these are
# legal clause-anchor keywords for the *_at_line clause-drop helper, in
# addition to _PH_CLAUSE_KEYWORDS. `axiomatic { ... }` has a brace body
# and is handled separately (we currently do not drop axiomatic blocks).
_TOP_LEVEL_DEF_KEYWORDS = ('logic', 'predicate', 'lemma', 'inductive')

_PRED_WITH_RESULT = re.compile(
    r'\bpredicate\s+([A-Za-z_]\w*)\s*\([^)]*\)\s*=\s*[^;]*\\result[^;]*;',
    re.DOTALL,
)

_ASSIGNS_CLAUSE = re.compile(
    r'(\bloop\s+assigns\b|\bassigns\b)([^;]*);'
)

_ERR_LINE = re.compile(
    r'\[kernel:annot-error\][^:\n]*:(\d+):\s*Warning:\s*\n\s*(.+)'
)


def _find_annotation_spans(src: str) -> List[Tuple[int, int]]:
    """Return [(start, end_exclusive), ...] for every ACSL annotation block."""
    spans: List[Tuple[int, int]] = []
    i, n = 0, len(src)
    while i < n:
        if src.startswith('/*@', i):
            end = src.find('*/', i + 3)
            if end < 0:
                break
            spans.append((i, end + 2))
            i = end + 2
        elif src.startswith('//@', i):
            end = src.find('\n', i + 3)
            if end < 0:
                end = n
            spans.append((i, end))
            i = end
        else:
            i += 1
    return spans


def _in_annotation(idx: int, spans: List[Tuple[int, int]]) -> bool:
    return any(s <= idx < e for s, e in spans)


def _line_to_offset(src: str, line_no: int) -> int:
    """1-based line_no → byte offset of that line's first char. -1 if OOB."""
    if line_no < 1:
        return -1
    off = 0
    for _ in range(line_no - 1):
        nl = src.find('\n', off)
        if nl < 0:
            return -1
        off = nl + 1
    return off


def _drop_physical_line(src: str, line_no: int) -> str:
    start = _line_to_offset(src, line_no)
    if start < 0:
        return src
    end = src.find('\n', start)
    end = end + 1 if end >= 0 else len(src)
    return src[:start] + src[end:]


def _clause_span_at_line(src: str, line_no: int,
                         spans: List[Tuple[int, int]]
                         ) -> Tuple[int, int, str]:
    """Find the enclosing ACSL clause that contains the cited line, and
    return (start_offset, end_offset_exclusive, keyword_used).

    Walks backwards from the cited line to the nearest clause-starting
    keyword (one of _PH_CLAUSE_KEYWORDS or _TOP_LEVEL_DEF_KEYWORDS) within
    the same annotation span, then forwards to the terminating top-level
    `;`. Brace/paren depth-aware so that `; ` inside a function-call arg
    list or an `\\at(x, Pre)` does not terminate the clause prematurely.

    Returns (-1, -1, '') if no clause can be located (caller skips).
    """
    line_start = _line_to_offset(src, line_no)
    if line_start < 0:
        return -1, -1, ''
    if not _in_annotation(line_start, spans):
        return -1, -1, ''

    # Find which annotation span we're in.
    span = next((s for s in spans if s[0] <= line_start < s[1]), None)
    if span is None:
        return -1, -1, ''
    span_start, span_end = span

    # End-of-cited-line offset (inclusive of any keyword starting ON that
    # very line). The clause keyword frequently lives on the cited line
    # itself — Frama-C points at where the parser choked, which is often
    # right after the keyword.
    line_end = src.find('\n', line_start)
    if line_end < 0:
        line_end = len(src)

    # Walk backwards from end-of-cited-line: find the latest occurrence of
    # any known keyword that begins at or before line_end AND lives in the
    # SAME annotation span.
    all_kws = list(_PH_CLAUSE_KEYWORDS) + list(_TOP_LEVEL_DEF_KEYWORDS)
    best_off = -1
    best_kw = ''
    for kw in all_kws:
        hit = src.rfind(kw, span_start, line_end)
        if hit > best_off:
            # Require word-boundary: previous char must be whitespace or
            # `/*@`/`//@` boundary; next char must be non-identifier.
            prev = src[hit - 1] if hit > 0 else '\n'
            nxt = src[hit + len(kw)] if hit + len(kw) < len(src) else '\n'
            if not (prev.isalnum() or prev == '_') and not (nxt.isalnum() or nxt == '_'):
                best_off = hit
                best_kw = kw

    if best_off < 0:
        return -1, -1, ''

    # Find clause end: nearest top-level `;` after the keyword, within the
    # same annotation span. `\at(...)` etc. doesn't contain `;`, so depth
    # tracking isn't usually needed, but be defensive against nested
    # `{ ... }` for inductive/axiomatic-like bodies.
    i = best_off + len(best_kw)
    depth = 0
    end_semi = -1
    while i < span_end:
        ch = src[i]
        if ch in '({[':
            depth += 1
        elif ch in ')}]':
            depth = max(0, depth - 1)
        elif ch == ';' and depth == 0:
            end_semi = i
            break
        i += 1
    if end_semi < 0:
        return -1, -1, ''
    # Consume trailing newline so we don't leave a blank line.
    end = end_semi + 1
    if end < len(src) and src[end] == '\n':
        end += 1
    return best_off, end, best_kw


def _comment_marker_balance(src: str) -> int:
    """`/*@` count minus `*/` count (signed)."""
    return src.count('/*@') - src.count('*/')


def _split_top_level(s: str, sep: str = ',') -> List[str]:
    out, buf, depth = [], [], 0
    for ch in s:
        if ch in '([{':
            depth += 1
        elif ch in ')]}':
            depth -= 1
        if ch == sep and depth == 0:
            out.append(''.join(buf))
            buf = []
        else:
            buf.append(ch)
    out.append(''.join(buf))
    return out


_TOKEN_RE = re.compile(r"unexpected token '([^']+)'")
_UNBOUND_VAR_RE = re.compile(r"unbound logic variable ([A-Za-z_]\w*)")
_UNBOUND_BACKSLASH_VAR_RE = re.compile(r"unbound logic variable (\\[A-Za-z_]\w*)")
_UNBOUND_FUNC_RE = re.compile(r"unbound logic function ([A-Za-z_]\w*)")
_UNBOUND_PH_RE = re.compile(r"unbound logic variable (PLACE_HOLDER_[A-Z_0-9]+)")
_NOTHING_MIX_RE = re.compile(r"Mixing\s+\\nothing\s+and\s+a\s+real\s+location")
# "comparison of incompatible types: int * and ℤ" (or similar). Frama-C also
# emits this when an LLM-generated annotation compares a pointer to a logic
# integer (e.g. `ptr > 0` instead of `ptr != \null`).
_INCOMPAT_TYPES_RE = re.compile(r"comparison of incompatible types")


def _parse_error_lines(syntax_error: str) -> List[Tuple[int, str]]:
    """Extract (line_no, raw_msg) for every annot-error entry."""
    if not syntax_error:
        return []
    out: List[Tuple[int, str]] = []
    for m in _ERR_LINE.finditer(syntax_error):
        try:
            ln = int(m.group(1))
        except ValueError:
            continue
        out.append((ln, m.group(2).strip()))
    return out


def _classify_token(msg: str) -> str:
    """Return a short category for the error message."""
    if _UNBOUND_PH_RE.search(msg):
        return 'placeholder'
    if _NOTHING_MIX_RE.search(msg):
        return 'nothing-mix'
    if _UNBOUND_VAR_RE.search(msg) or _UNBOUND_FUNC_RE.search(msg):
        return 'unbound'
    tok = _TOKEN_RE.search(msg)
    if not tok:
        return 'other'
    t = tok.group(1)
    if t == 'const':
        return 'const'
    if t == ')':
        return 'rparen'
    if t == r'\result':
        return 'result'
    if t.startswith('PLACE_HOLDER_'):
        return 'placeholder'
    return 'other'


class ACSLFixer:
    """Deterministic textual fixer; see module docstring."""

    def __init__(self, logger: logging.Logger | None = None):
        self.logger = logger

    def fix(self, annotations: str, syntax_error: str) -> FixReport:
        report = FixReport(annotations=annotations)
        err_lines = _parse_error_lines(syntax_error)

        src = annotations

        src, msgs = self._fix_placeholder_markers(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._fix_result_in_predicate(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._fix_nothing_mixed_assigns(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._fix_unbound_names(src, syntax_error)
        report.fixes_applied.extend(msgs)

        src, msgs = self._fix_empty_blocks(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._fix_duplicate_top_level_defs(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._strip_status_brackets(src)
        report.fixes_applied.extend(msgs)

        # Proactive textual rewrites (run BEFORE WP-error-driven drops) for
        # known LLM-emitted patterns that Frama-C/WP rejects but ACSL-the-
        # grammar nominally allows. Each rewrite is a no-op if the pattern
        # is absent, so this is always safe.
        src, msgs = self._strip_const_in_annotations(src)
        report.fixes_applied.extend(msgs)

        src, msgs = self._rewrite_zero_arg_logic(src)
        report.fixes_applied.extend(msgs)

        # `decreases X, Y;` (tuple form) is invalid ACSL; ACSL accepts only one
        # expression per decreases clause. Rewrite to `decreases X + Y;`.
        def _fix_decreases_tuple(s: str) -> Tuple[str, List[str]]:
            ms: List[str] = []
            def repl(m):
                ms.append(f"[acsl-fixer] decreases tuple: rewrote to sum form on line ~{s.count(chr(10), 0, m.start())+1}")
                terms = [t.strip() for t in m.group(1).split(',')]
                return f"decreases {' + '.join(terms)};"
            out = re.sub(r'\bdecreases\s+([^;\n]*,[^;\n]*);', repl, s)
            return out, ms

        src, msgs = _fix_decreases_tuple(src)
        report.fixes_applied.extend(msgs)

        # `const`-token-cited line drop is now mostly redundant (the proactive
        # strip above removes every `const` inside annotation spans). Keep as
        # a safety net for cases where the LLM smuggles `const` inside a
        # non-annotation block that Frama-C still picks up.
        src, msgs = self._drop_lines_by_token(src, err_lines, 'const')
        report.fixes_applied.extend(msgs)

        # `)` errors: prefer clause-aware drop. A `)` mismatch frequently
        # spans multiple lines (an unclosed `\at(...)` inside a long
        # `requires`), in which case removing only the cited physical line
        # leaves a dangling clause. The clause-aware drop walks back to the
        # enclosing keyword and drops the whole clause cleanly.
        src, msgs = self._drop_clause_by_token(src, err_lines, ')')
        report.fixes_applied.extend(msgs)

        # Multi-line clause drop for tokens whose offending site typically
        # lives inside `logic`/`predicate` bodies or multi-line clauses
        # (case-165/166/314 in sespec-400). `_drop_lines_by_token` removes
        # only the cited physical line, which is insufficient when a
        # malformed clause spans several lines.
        for tok in ('integer', '\\exists', '\\sum', '\\forall'):
            src, msgs = self._drop_clause_by_token(src, err_lines, tok)
            report.fixes_applied.extend(msgs)

        # Pointer-vs-integer comparison: Frama-C reports `comparison of
        # incompatible types: int * and ℤ` at the cited line. Drop the
        # enclosing clause.
        src, msgs = self._drop_clauses_by_message(src, err_lines, _INCOMPAT_TYPES_RE,
                                                   "incompat-types")
        report.fixes_applied.extend(msgs)

        # Backslash unbound logic vars (\max_int, \min_int, ...). Frama-C
        # phrases them the same as ordinary unbound vars, but our existing
        # _UNBOUND_VAR_RE only matches [A-Za-z_]\w*. Run a dedicated pass
        # over the relevant regex.
        src, msgs = self._drop_clauses_by_message(src, err_lines,
                                                   _UNBOUND_BACKSLASH_VAR_RE,
                                                   "unbound-builtin")
        report.fixes_applied.extend(msgs)

        report.annotations = src
        if not err_lines:
            report.fully_handled = bool(report.fixes_applied)
        else:
            # Every cited line either got dropped (no longer indexable) or
            # was modified by one of the structural passes. Detecting that
            # precisely is fiddly; instead, set fully_handled when at least
            # one fix fired AND no error category remains unhandled.
            handled_categories = {
                'placeholder', 'result', 'nothing-mix', 'const', 'rparen',
                'unbound',
            }
            residual = [m for _, m in err_lines
                        if _classify_token(m) not in handled_categories]
            report.fully_handled = bool(report.fixes_applied) and not residual
        return report

    # ------------------------------------------------------------------
    # Fix passes
    # ------------------------------------------------------------------

    def _fix_placeholder_markers(self, src: str) -> Tuple[str, List[str]]:
        msgs: List[str] = []
        spans = _find_annotation_spans(src)

        # Pass 1a: whole `loop invariant PLACE_HOLDER_*;` lines (with trailing
        # comment). Filter to those inside annotation spans.
        def _line_no(off: int) -> int:
            return src.count('\n', 0, off) + 1

        replacements: List[Tuple[int, int, str, str]] = []
        for m in _PH_INVARIANT_LINE.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            tok_match = _PH_BARE_TOKEN.search(m.group(0))
            tok = tok_match.group(0) if tok_match else 'PLACE_HOLDER_?'
            # Extend deletion to end-of-line (consume trailing comment).
            end = src.find('\n', m.end())
            if end < 0:
                end = len(src)
            replacements.append((m.start(), end, '',
                                 f'placeholder: dropped {tok} on line {_line_no(m.start())}'))

        # Pass 1b: bare tokens inside an annotation but NOT covered by 1a —
        # drop the enclosing clause from keyword to terminating `;`.
        # Skip tokens already inside a 1a replacement range.
        consumed = [(a, b) for a, b, _, _ in replacements]

        def _covered(off: int) -> bool:
            return any(a <= off < b for a, b in consumed)

        for m in _PH_BARE_TOKEN.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            if _covered(m.start()):
                continue
            # Find clause start: walk backwards looking for a keyword from
            # _PH_CLAUSE_KEYWORDS, stopping at `/*@`.
            kw_off = -1
            kw_str = ''
            for kw in _PH_CLAUSE_KEYWORDS:
                hit = src.rfind(kw, 0, m.start())
                if hit > kw_off:
                    # Ensure it's still inside the same annotation span.
                    if _in_annotation(hit, spans):
                        kw_off = hit
                        kw_str = kw
            if kw_off < 0:
                continue
            # End at next `;` (top-level inside annotation).
            semi = src.find(';', m.end())
            if semi < 0:
                continue
            replacements.append((kw_off, semi + 1, '',
                                 f'placeholder: dropped {m.group(0)} clause '
                                 f'({kw_str}) on line {_line_no(kw_off)}'))

        # Apply replacements right-to-left so offsets remain valid.
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, repl, msg in replacements:
            src = src[:a] + repl + src[b:]
            msgs.append(msg)
        return src, msgs

    def _fix_result_in_predicate(self, src: str) -> Tuple[str, List[str]]:
        msgs: List[str] = []
        spans = _find_annotation_spans(src)
        replacements: List[Tuple[int, int, str]] = []
        for m in _PRED_WITH_RESULT.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            name = m.group(1)
            replacements.append((m.start(), m.end(), name))
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, name in replacements:
            src = src[:a] + src[b:]
            msgs.append(f"result-in-predicate: dropped predicate '{name}'")
        return src, msgs

    def _fix_unbound_names(self, src: str, syntax_error: str) -> Tuple[str, List[str]]:
        """Drop the SPECIFIC clause Frama-C cited as unbound — never any
        sibling clauses that happen to mention the same identifier.

        Frama-C's `unbound logic variable X. Ignoring ... of function foo`
        is line-anchored: the cited line points at the broken clause,
        not at every other clause mentioning X. So we walk to the clause
        containing the cited line offset and drop only that clause.

        `X` itself might be a legitimate live variable used correctly
        elsewhere (typical case: `\\at(x, Pre)` where `x` is a local
        declared after the function-Pre label — `x` is unbound at Pre,
        but `loop invariant x >= -50;` and `loop assigns x;` are fine).
        """
        msgs: List[str] = []
        if not syntax_error:
            return src, msgs
        # Pair each cited (line, name) tuple.
        cited: List[Tuple[int, str]] = []
        for ln, raw in _parse_error_lines(syntax_error):
            for m in _UNBOUND_VAR_RE.finditer(raw):
                cited.append((ln, m.group(1)))
            for m in _UNBOUND_FUNC_RE.finditer(raw):
                cited.append((ln, m.group(1)))
        # Skip PLACE_HOLDER_* (pass 1) and ACSL built-ins (defensive).
        ACSL_BUILTINS = {
            'integer', 'real', 'boolean', 'true', 'false', 'null',
            'result', 'nothing', 'old', 'at', 'valid', 'separated',
        }
        cited = [
            (ln, n) for (ln, n) in cited
            if not n.startswith('PLACE_HOLDER_') and n not in ACSL_BUILTINS
        ]
        if not cited:
            return src, msgs

        spans = _find_annotation_spans(src)
        replacements: List[Tuple[int, int, str, str]] = []
        # For each citation, find the clause at the cited line that
        # mentions the cited name. Drop ONLY that clause.
        for ln, name in cited:
            line_start = _line_to_offset(src, ln)
            if line_start < 0:
                continue
            line_end = src.find('\n', line_start)
            if line_end < 0:
                line_end = len(src)
            # Find the closest occurrence of `name` on or after the line
            # start and on or before the next `;` (which closes the
            # clause). Some clauses span multiple physical lines; we use
            # the cited line as an anchor.
            tok_re = re.compile(rf'\b{re.escape(name)}\b')
            anchor = None
            for m in tok_re.finditer(src, line_start, len(src)):
                if not _in_annotation(m.start(), spans):
                    continue
                anchor = m.start()
                break
            if anchor is None:
                continue
            # Walk backwards to the clause-starting keyword inside the
            # same annotation span.
            kw_off = -1
            kw_str = ''
            for kw in _PH_CLAUSE_KEYWORDS:
                hit = src.rfind(kw, 0, anchor)
                if hit > kw_off and _in_annotation(hit, spans):
                    kw_off = hit
                    kw_str = kw
            if kw_off < 0:
                continue
            semi = src.find(';', anchor)
            if semi < 0:
                continue
            replacements.append((kw_off, semi + 1, '',
                                 f"unbound-name: dropped cited clause referencing "
                                 f"'{name}' ({kw_str}) on line {ln}"))

        if not replacements:
            return src, msgs

        # Dedupe + apply right-to-left.
        seen = set()
        unique = []
        for a, b, repl, msg in replacements:
            if (a, b) in seen:
                continue
            seen.add((a, b))
            unique.append((a, b, repl, msg))
        unique.sort(key=lambda r: r[0], reverse=True)
        for a, b, repl, msg in unique:
            src = src[:a] + repl + src[b:]
            msgs.append(msg)
        return src, msgs

    def _fix_empty_blocks(self, src: str) -> Tuple[str, List[str]]:
        """Strip empty ACSL annotation blocks like `/*@ */` (any whitespace).

        Frama-C parses an empty `/*@ */` as `unexpected token ''` and bails
        out for the WHOLE file — so a single stray empty block produced by
        spec-gen template stitching kills every downstream clause. The
        block has no semantics; dropping it is always safe.
        """
        msgs: List[str] = []
        empty_re = re.compile(r'/\*@[ \t\r\n]*\*/')
        replacements: List[Tuple[int, int]] = []
        for m in empty_re.finditer(src):
            replacements.append((m.start(), m.end()))
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b in replacements:
            line_no = src.count('\n', 0, a) + 1
            src = src[:a] + src[b:]
            msgs.append(f"empty-block: removed empty `/*@ */` on line {line_no}")
        return src, msgs

    def _fix_duplicate_top_level_defs(self, src: str) -> Tuple[str, List[str]]:
        """Dedupe top-level `/*@ logic ... */` / `/*@ predicate ... */` blocks
        that declare the same NAME more than once. Keeps the FIRST occurrence
        (in source order) and drops every subsequent one.

        Frama-C reports `<predicate|logic function> X is already declared
        with the same profile` and refuses to load the duplicate annotation.
        Dropping the later block lets the original definition survive.
        Only acts on top-level blocks (depth==0 brace tracking) so logic
        nested inside a function-level contract isn't accidentally pruned.
        """
        msgs: List[str] = []
        # Track brace depth to determine "top-level".
        depth = 0
        pos = 0
        seen: dict[str, int] = {}
        replacements: List[Tuple[int, int, str]] = []
        n = len(src)
        # Pattern for the NAME inside a /*@ logic <type> <name>(...) ... */
        # or /*@ predicate <name>(...) ... */ block.
        body_name_re = re.compile(
            r'^\s*(?:logic\s+\w[\w\s\*]*?|predicate)\s+([A-Za-z_]\w*)\s*[({]'
        )
        i = 0
        while i < n:
            ch = src[i]
            if src.startswith('/*@', i):
                end = src.find('*/', i + 3)
                if end < 0:
                    break
                if depth == 0:
                    body = src[i + 3:end]
                    bm = body_name_re.match(body)
                    if bm:
                        name = bm.group(1)
                        if name in seen:
                            replacements.append((i, end + 2, name))
                        else:
                            seen[name] = i
                i = end + 2
            elif ch == '{':
                depth += 1
                i += 1
            elif ch == '}':
                depth = max(0, depth - 1)
                i += 1
            else:
                i += 1
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, name in replacements:
            line_no = src.count('\n', 0, a) + 1
            # Also gobble a trailing newline if present, to avoid blank lines.
            j = b
            if j < len(src) and src[j] == '\n':
                j += 1
            src = src[:a] + src[j:]
            msgs.append(f"dedupe: dropped duplicate top-level def of '{name}' on line {line_no}")
        return src, msgs

    def _strip_status_brackets(self, src: str) -> Tuple[str, List[str]]:
        """Strip LLM-emitted status-hint brackets like `[POSTCONDITION FAILED]`,
        `[ASSERT VALID]`, `[INVARIANT UNKNOWN]` that appear inside ACSL
        clauses. These come from the model echoing Frama-C's prior-round
        status decorations and are not valid ACSL syntax.

        Pattern: `\\[<KEYWORD>(\\s+<KEYWORD>)*\\]` where all words are
        ALL-UPPERCASE (>=2 letters). Conservative: only acts inside
        annotation spans and only when the bracket contents are
        recognizable status keywords. Single-letter or mixed-case names
        (which could be legitimate identifiers) are untouched.
        """
        msgs: List[str] = []
        spans = _find_annotation_spans(src)
        if not spans:
            return src, msgs

        # All-uppercase words (>=2 chars) separated by spaces, in square
        # brackets. Matches things like [POSTCONDITION FAILED],
        # [INVARIANT UNKNOWN], [ASSERT VALID].
        status_re = re.compile(r'\[[A-Z]{2,}(?:\s+[A-Z]{2,})*\]')

        replacements: List[Tuple[int, int, str]] = []
        for m in status_re.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            line_no = src.count('\n', 0, m.start()) + 1
            replacements.append((m.start(), m.end(),
                                 f"status-bracket: stripped '{m.group(0)}' on line {line_no}"))
        if not replacements:
            return src, msgs

        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, msg in replacements:
            src = src[:a] + src[b:]
            msgs.append(msg)
        return src, msgs

    def _fix_nothing_mixed_assigns(self, src: str) -> Tuple[str, List[str]]:
        msgs: List[str] = []
        spans = _find_annotation_spans(src)
        replacements: List[Tuple[int, int, str, str]] = []

        for m in _ASSIGNS_CLAUSE.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            kw = m.group(1)
            body = m.group(2)
            targets = [t.strip() for t in _split_top_level(body, ',')]
            targets = [t for t in targets if t]
            has_nothing = any(t == r'\nothing' for t in targets)
            real_targets = [t for t in targets if t != r'\nothing']
            if not (has_nothing and real_targets):
                continue  # pure-\nothing clauses are fine; nothing to do
            new_clause = f"{kw} " + ', '.join(real_targets) + ';'
            line_no = src.count('\n', 0, m.start()) + 1
            replacements.append((m.start(), m.end(), new_clause,
                                 f"assigns: removed \\nothing from mixed list on line {line_no}"))

        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, repl, msg in replacements:
            src = src[:a] + repl + src[b:]
            msgs.append(msg)
        return src, msgs

    def _strip_const_in_annotations(self, src: str) -> Tuple[str, List[str]]:
        """Remove `const` qualifier tokens that appear inside ACSL annotation
        spans.

        ACSL types have no qualifier concept; any `const T*` parameter in a
        `logic` / `predicate` declaration triggers `unexpected token 'const'`
        and (because the const token sits in the MIDDLE of a multi-line
        parameter list) the older line-drop fix would amputate the
        declaration and leave the rest of the spec referring to unbound
        names. Stripping the token in place preserves the parameter list.

        Conservative: only touches text inside `/*@ ... */` or `//@ ...`
        spans; C-body uses of `const` are untouched. Word-boundary anchored.
        """
        msgs: List[str] = []
        spans = _find_annotation_spans(src)
        if not spans:
            return src, msgs
        pattern = re.compile(r'\bconst\b\s*')
        replacements: List[Tuple[int, int, str]] = []
        for m in pattern.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            ln = src.count('\n', 0, m.start()) + 1
            replacements.append((m.start(), m.end(),
                                 f"const-strip: removed `const` qualifier "
                                 f"on line {ln}"))
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, msg in replacements:
            src = src[:a] + src[b:]
            msgs.append(msg)
        return src, msgs

    def _rewrite_zero_arg_logic(self, src: str) -> Tuple[str, List[str]]:
        """Rewrite `logic T foo() = expr;` to `logic T foo = expr;`.

        ACSL nominally allows zero-parameter `logic` function definitions,
        but Frama-C/WP rejects them with `unexpected token ')'` at the
        defining line. Treating these as plain logic constants (no parens)
        is semantically equivalent and discharges WP cleanly. Runs over
        annotation spans only.
        """
        msgs: List[str] = []
        spans = _find_annotation_spans(src)
        if not spans:
            return src, msgs
        pattern = re.compile(
            r'(\blogic\s+\w+(?:\s*\*+)?\s+)(\w+)\s*\(\s*\)\s*=',
        )
        replacements: List[Tuple[int, int, str, str]] = []
        for m in pattern.finditer(src):
            if not _in_annotation(m.start(), spans):
                continue
            ln = src.count('\n', 0, m.start()) + 1
            new_text = f"{m.group(1)}{m.group(2)} ="
            replacements.append(
                (m.start(), m.end(), new_text,
                 f"zero-arg-logic: rewrote `{m.group(2)}()` -> `{m.group(2)}` "
                 f"on line {ln}"))
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        for a, b, repl, msg in replacements:
            src = src[:a] + repl + src[b:]
            msgs.append(msg)
        return src, msgs

    def _drop_clause_by_token(self, src: str,
                              err_lines: Iterable[Tuple[int, str]],
                              token: str) -> Tuple[str, List[str]]:
        """Like _drop_lines_by_token but drops the entire enclosing clause
        instead of just the cited physical line. Necessary for tokens that
        typically appear inside multi-line `logic`/`predicate` bodies or
        comprehension expressions (`\\sum`, `\\exists`, `\\forall`, type
        keyword `integer` in unsupported positions)."""
        msgs: List[str] = []
        target_lines: List[int] = []
        for ln, msg in err_lines:
            tok = _TOKEN_RE.search(msg)
            if tok and tok.group(1) == token:
                target_lines.append(ln)
        if not target_lines:
            return src, msgs
        # Apply right-to-left.
        replacements: List[Tuple[int, int, str]] = []
        spans = _find_annotation_spans(src)
        for ln in sorted(set(target_lines)):
            a, b, kw = _clause_span_at_line(src, ln, spans)
            if a < 0:
                continue
            preview = src[a:min(a + 60, b)].replace('\n', ' ')
            replacements.append(
                (a, b, f"{token}-clause: dropped {kw} clause on line {ln} "
                       f"({preview!r})"))
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        # Track applied ranges to avoid overlaps (which would double-drop).
        applied: List[Tuple[int, int]] = []
        for a, b, msg in replacements:
            if any(b > pa and a < pb for pa, pb in applied):
                continue
            if _comment_marker_balance(src[:a] + src[b:]) != _comment_marker_balance(src):
                msgs.append(f"{token}-clause: skipped line — would break /*@..*/")
                continue
            src = src[:a] + src[b:]
            applied.append((a, b))
            msgs.append(msg)
        return src, msgs

    def _drop_clauses_by_message(self, src: str,
                                  err_lines: Iterable[Tuple[int, str]],
                                  pattern: 're.Pattern[str]',
                                  tag: str) -> Tuple[str, List[str]]:
        """Drop the enclosing clause for every err_line whose message
        matches `pattern`. The match group(1), if any, is used for the
        log message."""
        msgs: List[str] = []
        target_lines: List[Tuple[int, str]] = []
        for ln, msg in err_lines:
            m = pattern.search(msg)
            if m:
                detail = m.group(1) if m.groups() else ''
                target_lines.append((ln, detail))
        if not target_lines:
            return src, msgs
        replacements: List[Tuple[int, int, str]] = []
        spans = _find_annotation_spans(src)
        for ln, detail in sorted(set(target_lines)):
            a, b, kw = _clause_span_at_line(src, ln, spans)
            if a < 0:
                continue
            extra = f" ({detail!r})" if detail else ''
            replacements.append(
                (a, b, f"{tag}: dropped {kw} clause on line {ln}{extra}"))
        if not replacements:
            return src, msgs
        replacements.sort(key=lambda r: r[0], reverse=True)
        applied: List[Tuple[int, int]] = []
        for a, b, msg in replacements:
            if any(b > pa and a < pb for pa, pb in applied):
                continue
            if _comment_marker_balance(src[:a] + src[b:]) != _comment_marker_balance(src):
                msgs.append(f"{tag}: skipped — would break /*@..*/")
                continue
            src = src[:a] + src[b:]
            applied.append((a, b))
            msgs.append(msg)
        return src, msgs

    def _drop_lines_by_token(self, src: str,
                             err_lines: Iterable[Tuple[int, str]],
                             token: str) -> Tuple[str, List[str]]:
        msgs: List[str] = []
        target_lines: List[int] = []
        for ln, msg in err_lines:
            tok = _TOKEN_RE.search(msg)
            if tok and tok.group(1) == token:
                target_lines.append(ln)
        if not target_lines:
            return src, msgs

        # Descending so earlier indices stay stable.
        for ln in sorted(set(target_lines), reverse=True):
            spans = _find_annotation_spans(src)
            off = _line_to_offset(src, ln)
            if off < 0:
                continue
            if not _in_annotation(off, spans):
                continue
            candidate = _drop_physical_line(src, ln)
            # Guardrail: don't break /*@...*/ balance.
            if _comment_marker_balance(candidate) != _comment_marker_balance(src):
                msgs.append(f"{token}-drop: skipped line {ln} (would break /*@..*/)")
                continue
            line_text = src[off:src.find('\n', off) if src.find('\n', off) >= 0 else len(src)].strip()
            src = candidate
            msgs.append(f"{token}-drop: removed line {ln}: {line_text[:80]}")
        return src, msgs


# ----------------------------------------------------------------------
# Self-test
# ----------------------------------------------------------------------

def _self_test() -> None:
    fx = ACSLFixer()

    # 1. Whole-line PLACE_HOLDER invariant gets removed.
    s1 = ("void f(){\n"
          "    /*@\n"
          "      loop invariant PLACE_HOLDER_VERFICATION_GOAL;   /* must imply ... */\n"
          "      loop invariant x >= 0;\n"
          "    */\n"
          "    while (x) x--;\n"
          "}\n")
    r1 = fx.fix(s1, '')
    assert 'PLACE_HOLDER_VERFICATION_GOAL' not in r1.annotations, r1.annotations
    assert any('placeholder' in m for m in r1.fixes_applied), r1.fixes_applied

    # 2. Bare PLACE_HOLDER inside a clause: enclosing clause is dropped.
    s2 = ("/*@\n"
          "  loop invariant x >= PLACE_HOLDER_X;\n"
          "  loop invariant y >= 0;\n"
          "*/\n")
    r2 = fx.fix(s2, '')
    assert 'PLACE_HOLDER_X' not in r2.annotations, r2.annotations
    assert 'y >= 0' in r2.annotations

    # 3. `\result` inside predicate body -> predicate stripped; predicate
    #    without \result stays.
    s3 = ("/*@ predicate p(int x) = \\result == x; */\n"
          "/*@ predicate q(int x) = x >= 0; */\n")
    r3 = fx.fix(s3, '')
    assert 'predicate p' not in r3.annotations, r3.annotations
    assert 'predicate q' in r3.annotations
    assert any('predicate' in m and "'p'" in m for m in r3.fixes_applied)

    # 4. \nothing mixed with real locations.
    s4 = ("/*@ loop assigns i, \\nothing, a[0..n]; */\n"
          "/*@ loop assigns \\nothing; */\n")
    r4 = fx.fix(s4, '')
    assert r'\nothing' not in r4.annotations.split('\n')[0], r4.annotations
    assert 'loop assigns i, a[0..n];' in r4.annotations
    # pure \nothing clause survives:
    assert r'loop assigns \nothing;' in r4.annotations

    # 5. Synthetic syntax_error citing `const` on a line inside an annotation.
    s5 = ("void f(){\n"
          "/*@\n"
          "  loop invariant const x == 0;\n"
          "*/\n"
          "    while(x) x--;\n"
          "}\n")
    fake_err5 = ("[kernel:annot-error] tmp/foo.c:3: Warning:\n"
                 "  unexpected token 'const'\n")
    r5 = fx.fix(s5, fake_err5)
    assert 'loop invariant const' not in r5.annotations, r5.annotations
    assert any(m.startswith('const-drop:') for m in r5.fixes_applied)

    # 6. Outside-annotation guard: `const` on a body line is NOT touched.
    s6 = ("void f(){\n"
          "  const int x = 0;\n"
          "  while(x) x--;\n"
          "}\n")
    fake_err6 = ("[kernel:annot-error] tmp/foo.c:2: Warning:\n"
                 "  unexpected token 'const'\n")
    r6 = fx.fix(s6, fake_err6)
    assert r6.annotations == s6, r6.annotations
    assert not any(m.startswith('const-drop:') for m in r6.fixes_applied)

    # 8. Unbound logic variable on a specific line: drop ONLY that clause.
    s8 = ("/*@\n"
          "  loop invariant x >= W;\n"
          "  loop invariant y >= 0;\n"
          "*/\n")
    fake_err8 = ("[kernel:annot-error] tmp/foo.c:2: Warning:\n"
                 "  unbound logic variable W. Ignoring logic specification of function foo\n")
    r8 = fx.fix(s8, fake_err8)
    assert 'x >= W' not in r8.annotations, r8.annotations
    assert 'y >= 0' in r8.annotations
    assert any('unbound-name' in m and "'W'" in m for m in r8.fixes_applied)

    # 9. Unbound logic function on a specific line.
    s9 = ("/*@\n"
          "  loop invariant foo_helper(x, y) > 0;\n"
          "  loop invariant z == 5;\n"
          "*/\n")
    fake_err9 = ("[kernel:annot-error] tmp/foo.c:2: Warning:\n"
                 "  unbound logic function foo_helper. Ignoring specification of function foo\n")
    r9 = fx.fix(s9, fake_err9)
    assert 'foo_helper' not in r9.annotations, r9.annotations
    assert 'z == 5' in r9.annotations

    # 10. Critical: don't drop SIBLING clauses that legitimately mention
    # the cited name. Common case: `\at(x, Pre)` triggers `unbound x` but
    # the other clauses using x (`x >= 0`, `loop assigns x`) are fine.
    s10 = ("/*@\n"
           "  loop invariant y == sum_fn(\\at(x, Pre), x);\n"
           "  loop invariant x >= -50;\n"
           "  loop invariant z == 0;\n"
           "  loop assigns x, y;\n"
           "*/\n")
    fake_err10 = ("[kernel:annot-error] tmp/foo.c:2: Warning:\n"
                  "  unbound logic variable x. Ignoring logic specification of function foo\n")
    r10 = fx.fix(s10, fake_err10)
    # The cited line-2 clause is dropped.
    assert 'sum_fn' not in r10.annotations, r10.annotations
    # Sibling clauses that also mention x are KEPT.
    assert 'x >= -50' in r10.annotations, r10.annotations
    assert 'loop assigns x, y;' in r10.annotations, r10.annotations
    assert 'z == 0' in r10.annotations

    # 10b. Outside-annotation guard: name in function body is NOT touched.
    s10b = ("int W = 5;\n"
            "void f(){\n"
            "/*@ loop invariant a >= 0; */\n"
            "    while(a) a--;\n"
            "}\n")
    fake_err10b = ("[kernel:annot-error] tmp/foo.c:1: Warning:\n"
                   "  unbound logic variable W. Ignoring ...\n")
    r10b = fx.fix(s10b, fake_err10b)
    assert r10b.annotations == s10b, r10b.annotations  # nothing changed

    # 11. Status brackets stripped, clause body preserved.
    s11 = ("/*@\n"
           "  ensures helper_pre_ok(x) [POSTCONDITION FAILED];\n"
           "  ensures \\result >= 0 [INVARIANT VALID];\n"
           "*/\n")
    r11 = fx.fix(s11, '')
    assert 'POSTCONDITION FAILED' not in r11.annotations, r11.annotations
    assert 'INVARIANT VALID' not in r11.annotations, r11.annotations
    assert 'helper_pre_ok(x)' in r11.annotations, r11.annotations
    assert '\\result >= 0' in r11.annotations, r11.annotations
    assert any('status-bracket' in m for m in r11.fixes_applied)

    # 12. Status-bracket guard: only acts inside annotation spans.
    s12 = ("int arr[POSTCONDITION FAILED];\n"
           "void f(){}\n")
    r12 = fx.fix(s12, '')
    assert r12.annotations == s12, r12.annotations  # outside-annotation untouched
    assert not any('status-bracket' in m for m in r12.fixes_applied)

    # 13. Status-bracket guard: mixed-case bracketed identifiers (legitimate
    # names) NOT touched.
    s13 = ("/*@\n"
           "  loop invariant arr[i] >= 0;\n"
           "*/\n")
    r13 = fx.fix(s13, '')
    assert 'arr[i]' in r13.annotations, r13.annotations  # not stripped

    # 7. Idempotency: applying twice produces no new entries.
    r7a = fx.fix(s1, '')
    r7b = fx.fix(r7a.annotations, '')
    assert r7b.fixes_applied == [], r7b.fixes_applied
    assert r7b.annotations == r7a.annotations

    print("acsl_fixer self-test OK")


if __name__ == '__main__':
    _self_test()
