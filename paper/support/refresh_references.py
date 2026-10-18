#!/usr/bin/env python3
"""Refresh source-level cross-reference snapshots for the four LaTeX entries.

Run from any directory after compiling the named entry. The generated .tex
files are deliberately not .aux files: Overleaf can compile main.tex or
appendix.tex directly after a fresh upload or a cache reset.
"""
from __future__ import annotations
import argparse
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REFS = ROOT / 'references'
COUNTERS = ('figure', 'table', 'algocf', 'equation', 'definition', 'theorem', 'proposition')


def groups(text: str) -> list[str]:
    """Read adjacent balanced TeX groups, respecting escaped braces."""
    result: list[str] = []
    i = 0
    while i < len(text):
        if text[i].isspace():
            i += 1
            continue
        if text[i] != '{':
            raise ValueError(f'Expected a TeX group near {text[i:i+60]!r}')
        depth, start = 1, i + 1
        i += 1
        while i < len(text) and depth:
            if text[i] == '\\':
                i += 2
                continue
            if text[i] == '{':
                depth += 1
            elif text[i] == '}':
                depth -= 1
            i += 1
        if depth:
            raise ValueError('Unbalanced TeX group')
        result.append(text[start:i-1])
    return result


def read_aux(stem: str) -> tuple[dict[str, list[str]], dict[str, str]]:
    path = ROOT / f'{stem}.aux'
    if not path.exists():
        raise FileNotFoundError(f'Compile {stem}.tex before refreshing references: {path}')
    labels: dict[str, list[str]] = {}
    citations: dict[str, str] = {}
    for line in path.read_text().splitlines():
        if line.startswith('\\newlabel{'):
            key, value = groups(line[len('\\newlabel'):])[:2]
            labels[key] = groups(value)
        elif line.startswith('\\bibcite{'):
            key, value = groups(line[len('\\bibcite'):])[:2]
            citations[key] = value
    return labels, citations


def appendix_label_names() -> set[str]:
    names: set[str] = set()
    for path in (ROOT / 'appendix_chapters').glob('*.tex'):
        text = re.sub(r'(?<!\\)%[^\n]*', '', path.read_text())
        names.update(re.findall(r'\\label\{([^}]+)\}', text))
        # These custom heading commands also define a label in argument 2.
        names.update(re.findall(r'\\PromptSub(?:sub)?section\{[^\n]*?\}\{([^}]+)\}', text))
    return names


def write_labels(filename: str, labels: dict[str, list[str]], target_pdf: str,
                 prefix_alias: bool = False) -> None:
    output = [f'% Generated cross-document labels pointing to {target_pdf}.',
              '% Refresh with build_pdfs.sh after structural edits.']
    for key, original_fields in labels.items():
        fields = (original_fields + [''] * 5)[:5]
        fields[4] = target_pdf
        value = ''.join('{' + field + '}' for field in fields)
        output.append('\\newlabel{' + key + '}{' + value + '}')
        if prefix_alias:
            output.append('\\newlabel{w-' + key + '}{' + value + '}')
    (REFS / filename).write_text('\n'.join(output) + '\n')


def write_citations(citations: dict[str, str]) -> None:
    output = ['% Citation numbers shared with main.pdf; links open its bibliography.',
              '\\makeatletter']
    for key, number in citations.items():
        # Same form hyperref uses for a bibcite, but with an external PDF URL.
        output.append('\\expandafter\\gdef\\csname b@' + key + '\\endcsname{%')
        output.append('  \\hyper@@link[cite]{main.pdf}{cite.' + key + '}{' + number + '}}')
    output.append('\\makeatother')
    (REFS / 'appendix_citations.tex').write_text('\n'.join(output) + '\n')


def refresh(stage: str) -> None:
    REFS.mkdir(exist_ok=True)
    labels, citations = read_aux(stage)
    if stage == 'whole':
        app_names = appendix_label_names()
        missing = app_names - labels.keys()
        if missing:
            raise ValueError(f'Appendix labels missing from whole.aux: {sorted(missing)}')
        write_labels('appendix_labels.tex', {k:v for k,v in labels.items() if k in app_names},
                     'appendix.pdf', prefix_alias=True)
        write_labels('main_labels.tex', {k:v for k,v in labels.items() if k not in app_names}, 'main.pdf')
        write_citations(citations)
        log = (ROOT / 'whole.log').read_text(errors='replace')
        output = ['% Resume the numbering used by the complete whole.tex document.']
        for counter in COUNTERS:
            match = re.search(r'V3NEW-COUNTER-' + counter + r':(\d+)', log)
            if not match:
                raise ValueError(f'Missing whole-document counter: {counter}')
            output.append('\\setcounter{' + counter + '}{' + match.group(1) + '}')
        (REFS / 'appendix_counters.tex').write_text('\n'.join(output) + '\n')
    elif stage == 'main':
        whole_labels, whole_citations = read_aux('whole')
        if citations != whole_citations:
            different = [k for k in whole_citations.keys() | citations.keys()
                         if whole_citations.get(k) != citations.get(k)]
            raise ValueError(f'Bibliography numbering differs between whole and main: {different}')
        write_labels('main_labels.tex', labels, 'main.pdf')
        write_citations(citations)
    elif stage == 'appendix':
        write_labels('appendix_labels.tex', labels, 'appendix.pdf', prefix_alias=True)
    print(f'Refreshed cross-reference snapshots from {stage}.aux ({len(labels)} labels).')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('stage', choices=['whole', 'main', 'appendix'])
    args = parser.parse_args()
    refresh(args.stage)
