#!/bin/bash
# Builds the deliverable PDFs:
#   whole.pdf    complete version (main body + appendix), no red revision marks;
#                appendix references are clickable in-PDF jumps.
#   main.pdf     main body only, no red; appendix references read
#                "Appendix X in the supplementary material" (resolved via whole.aux).
#   appendix.pdf appendix only, no red; labels/citations resolve against whole.aux.
#   diff.pdf     latexdiff markup version with red (not rebuilt by this script).
set -e
cd "$(dirname "$0")"
LATEX="pdflatex -interaction=nonstopmode"

# Clean stale aux/bbl files (format changes break hyperref/xr parsing otherwise)
rm -f whole.aux whole.bbl whole.log whole.out main.aux main.bbl main.log main.out \
      appendix.aux appendix.bbl appendix.log appendix.out

# 1. whole (must be built first: main.pdf and appendix.pdf resolve through whole.aux)
$LATEX -jobname=whole "\def\CLEANVERSION{1}\input{main.tex}"
bibtex whole > /dev/null
$LATEX -jobname=whole "\def\CLEANVERSION{1}\input{main.tex}"
$LATEX -jobname=whole "\def\CLEANVERSION{1}\input{main.tex}"

# 2. main (main body only, supplementary-material references)
$LATEX -jobname=main "\def\CLEANVERSION{1}\def\NOAPPENDIX{1}\input{main.tex}"
bibtex main > /dev/null
$LATEX -jobname=main "\def\CLEANVERSION{1}\def\NOAPPENDIX{1}\input{main.tex}"
$LATEX -jobname=main "\def\CLEANVERSION{1}\def\NOAPPENDIX{1}\input{main.tex}"

# 3. appendix (appendix only; reseed aux from whole before every pass so that
#    main-body labels and bibliography numbers resolve)
cp whole.aux appendix.aux
$LATEX -jobname=appendix "\def\CLEANVERSION{1}\def\APPENDIXONLY{1}\input{main.tex}"
cp whole.aux appendix.aux
$LATEX -jobname=appendix "\def\CLEANVERSION{1}\def\APPENDIXONLY{1}\input{main.tex}"

echo "Built whole.pdf, main.pdf, appendix.pdf (diff.pdf untouched)."
