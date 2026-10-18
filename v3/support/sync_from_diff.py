#!/usr/bin/env python3
"""Derive the three clean editions from diff without changing its content."""
from __future__ import annotations

import argparse
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
COUNTERS = ('figure', 'table', 'algocf', 'equation', 'definition', 'theorem', 'proposition')
APP_START = '\\clearpage\n\\appendices\n'
REF_COMMANDS = r"""\newcommand{\appref}[1]{Appendix~\ref{#1}}
\newcommand{\apptworef}[2]{Appendices~\ref{#1} and~\ref{#2}}
\newcommand{\supref}[1]{\ref{#1}}"""
MAIN_REFS = r"""% Source snapshots allow this entry to compile independently.
\input{references/appendix_labels}
\newcommand{\appref}[1]{Appendix~\ref*{w-#1} in the supplementary material}
\newcommand{\apptworef}[2]{Appendices~\ref*{w-#1} and~\ref*{w-#2} in the supplementary material}
\newcommand{\supref}[1]{\ref*{w-#1}}"""
APP_REFS = r"""
% Main-body labels and bibliography numbers are shared with main.pdf.
\input{references/main_labels}
\input{references/appendix_citations}
"""


def replace_once(text: str, old: str, new: str) -> str:
    if text.count(old) != 1:
        raise ValueError(f'Expected exactly one occurrence of {old!r}')
    return text.replace(old, new, 1)


def clean(text: str) -> str:
    # Retain argument braces: declarations such as \footnotesize stay local.
    text = re.sub(r'\\(?:rev|yfp|wsl)(?=\s*\{)', '', text)
    text = text.replace(r'\color{\revcolor}', '')
    return text.replace(r'\revcolor', 'black')


def uncomment(text: str) -> str:
    return re.sub(r'(?<!\\)%[^\n]*', '', text)


def expand_inputs(text: str) -> str:
    text = uncomment(text)
    return re.sub(r'\\input\{(diff_chapters/[^}]+)\}',
                  lambda m: expand_inputs((ROOT / (m[1] + '.tex')).read_text()), text)


def citations(text: str) -> list[str]:
    return list(dict.fromkeys(
        key.strip()
        for match in re.finditer(r'\\cite(?:\[[^\]]*\])?\{([^}]+)\}', expand_inputs(text))
        for key in match[1].split(',')))


def generated_files() -> dict[Path, str]:
    source = (ROOT / 'diff.tex').read_text()
    preamble, body = source.split('\\begin{document}', 1)
    # Remove revision definitions before removing revision calls.
    for line in (
        r'\newcommand{\wsl}[1]{{\color{red} #1}}',
        r'\newcommand{\yfp}[1]{{\color{blue} #1}}',
        '% Current v3 revisions are shown in blue.',
        r'\def\revcolor{blue}',
        r'\DeclareRobustCommand{\rev}[1]{{\color{\revcolor}#1}}',
        r'\pdfstringdefDisableCommands{\def\rev#1{#1}}',
    ):
        preamble = replace_once(preamble, line + '\n', '')
    preamble = clean(preamble)
    main_body, appendix_body = body.split(APP_START, 1)
    main_clean, appendix_clean = clean(main_body), clean(appendix_body)
    counter_snapshot = '% Record numbering for the independently compiled appendix.\n' + ''.join(
        '\\typeout{V3NEW-COUNTER-' + c + ':\\arabic{' + c + '}}\n' for c in COUNTERS)

    whole = (preamble + '\\begin{document}' + main_clean + counter_snapshot
             + APP_START + appendix_clean).replace('diff_chapters/', 'whole_chapters/')
    main = (replace_once(preamble, REF_COMMANDS, MAIN_REFS)
            + '\\begin{document}'
            + replace_once(main_clean, r'\bibliographystyle{IEEEtran}',
                           '\\input{references/appendix_nocite}\n\\bibliographystyle{IEEEtran}')
            + '\\end{document}\n').replace('diff_chapters/', 'chapters/')
    appendix = (replace_once(preamble, REF_COMMANDS, REF_COMMANDS + '\n' + APP_REFS)
                + '\\begin{document}\n\\input{references/appendix_counters}\n\\appendices\n'
                + appendix_clean).replace('diff_chapters/', 'appendix_chapters/')
    result = {ROOT / 'whole.tex': whole, ROOT / 'main.tex': main,
              ROOT / 'appendix.tex': appendix}
    for path in sorted((ROOT / 'diff_chapters').glob('*.tex')):
        content = clean(path.read_text())
        split_dir = 'appendix_chapters' if path.stem.startswith('appendix_') else 'chapters'
        for directory in ('whole_chapters', split_dir):
            result[ROOT / directory / path.name] = content.replace('diff_chapters/', directory + '/')

    main_keys = set(citations(main_body))
    app_keys = [key for key in citations(appendix_body) if key not in main_keys]
    result[ROOT / 'references/appendix_nocite.tex'] = (
        '% Bibliography entries also cited in the supplementary material.\n'
        + ('\\nocite{' + ','.join(app_keys) + '}\n' if app_keys else ''))
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check', action='store_true', help='Report stale files without modifying them.')
    args = parser.parse_args()
    expected = generated_files()
    stale = [path for path, content in expected.items()
             if not path.exists() or path.read_text() != content]
    for path in stale:
        if not args.check:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected[path])
        print(('Stale: ' if args.check else 'Updated: ') + str(path.relative_to(ROOT)))
    if args.check and stale:
        raise SystemExit(1)
    print(f'{len(expected)} generated files agree with diff; {len(stale)} '
          + ('stale.' if args.check else 'updated.'))


if __name__ == '__main__':
    main()
