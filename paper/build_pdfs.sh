#!/usr/bin/env bash
# Build all four standalone LaTeX entries and refresh split-document references.
# Requires pdfLaTeX, BibTeX, and Python 3. No special TeX flags are necessary.
set -euo pipefail
cd "$(dirname "$0")"
LATEX_BIN="${LATEX_BIN:-pdflatex}"
BIBTEX_BIN="${BIBTEX_BIN:-bibtex}"
if ! command -v "$BIBTEX_BIN" >/dev/null 2>&1; then
  if command -v bibtex.original >/dev/null 2>&1; then
    BIBTEX_BIN=bibtex.original
  else
    echo 'BibTeX is required. Set BIBTEX_BIN to its executable.' >&2
    exit 1
  fi
fi
pass() {
  "$LATEX_BIN" -interaction=nonstopmode -halt-on-error -file-line-error "$1.tex" > "$1.build.txt" 2>&1 || {
    tail -n 80 "$1.build.txt" >&2
    return 1
  }
}
with_bibliography() {
  echo "Building $1.pdf"
  pass "$1"
  "$BIBTEX_BIN" "$1" > "$1.bib-build.txt" 2>&1 || {
    cat "$1.bib-build.txt" >&2
    return 1
  }
  pass "$1"
  pass "$1"
}
# Do not delete references/*.tex; these snapshots support independent builds.
rm -f {whole,main,appendix,diff}.{aux,bbl,blg,log,out,toc,lof,lot}
with_bibliography whole
python3 support/refresh_references.py whole
with_bibliography main
python3 support/refresh_references.py main
echo 'Building appendix.pdf'
pass appendix
pass appendix
python3 support/refresh_references.py appendix
# Import the actual appendix page numbers and hyperlink targets into main.
pass main
pass main
python3 support/refresh_references.py main
# Keep cross-document page references in appendix current as well.
pass appendix
with_bibliography diff
for entry in whole main appendix diff; do
  if grep -E 'There were undefined references|Citation .* undefined|Reference .* undefined|multiply defined' "$entry.log"; then
    echo "Unresolved or duplicated references in $entry.log" >&2
    exit 1
  fi
done
echo 'Built whole.pdf, main.pdf, appendix.pdf and blue-marked diff.pdf.'
