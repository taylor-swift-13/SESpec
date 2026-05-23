#!/usr/bin/env bash
# Incremental repair-axis ablation that fills in the two missing rungs between
#   sespec_no_se_no_exm_no_repair  (∅: refine=0, SE off, examples off)
# and
#   sespec_default                 (refine=10, SE on, examples on).
#
# Adds:
#   sespec_no_se_no_exm   refine=10, SE off, examples off   (+repair only)
#   sespec_no_exm         refine=10, SE on,  examples off   (+repair +SE)
#
# Writes into the same matrix_root as the 4-variant run so all four rungs
# share output layout and can be aggregated together.
#
# Usage:
#   OPENAI_API_KEY=... ./run_sespec_repair_ablation.sh
#
# Optional:
#   WORKERS=24
#   MATRIX_ROOT=/abs/path/to/existing_matrix_run   (defaults to the 4-variant root)

set -u

REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
MATRIX_ROOT="${MATRIX_ROOT:-${SRC}/results/matrix_runs/20260514_215427_input_sespec_4variants_3models}"
LOG_DIR="${MATRIX_ROOT}/_runner_logs"
WORKERS="${WORKERS:-24}"
RESUME="${RESUME:-1}"

MODELS=(gpt-4o gpt-5-mini gpt-5.4-mini)
LABELS=(
    sespec_no_se_no_exm
)

mkdir -p "${LOG_DIR}"

export PATH="/home/yangfp/.opam/default/bin:${PATH}"

if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2
    exit 1
fi

cd "${SRC}"

mapfile -t CASES < <(find input/sespec -maxdepth 1 -type f -name '*.c' -printf '%f\n' | sed 's/\.c$//' | sort -V)

if [[ "${#CASES[@]}" -eq 0 ]]; then
    echo "No cases found under ${SRC}/input/sespec" >&2
    exit 1
fi

echo "Matrix root: ${MATRIX_ROOT}"
echo "Bench: sespec"
echo "Cases: ${#CASES[@]}"
echo "Labels: ${LABELS[*]}"
echo "Models: ${MODELS[*]}"
echo "Concurrency: ${WORKERS}"
echo "Resume mode: ${RESUME}"
echo "refine_count for new labels: 10"
echo

"${PY}" -c "
import sys
import sespec_matrix as m

# Base preset uses refine_count=10 (matches sespec_default in the 4-variant run).
m.PRESETS['sespec_default']['refine_count'] = 10
m.PRESETS['sespec_no_se_no_exm'] = dict(
    m.PRESETS['sespec_default'],
    refine_count=10,
    use_se=False,
    use_examples=False,
)
sys.argv = [
    'sespec_matrix.py',
    '--bench', 'sespec',
    '--cases', *'''${CASES[*]}'''.split(),
    '--models', *'''${MODELS[*]}'''.split(),
    '--labels', *'''${LABELS[*]}'''.split(),
    '--workers', '${WORKERS}',
    '--matrix-root', '${MATRIX_ROOT}',
]
if '${RESUME}' == '1':
    sys.argv.append('--resume')
raise SystemExit(m.main())
" 2>&1 | tee "${LOG_DIR}/sespec_repair_ablation.log"

echo
echo "===== DONE ${MATRIX_ROOT} ====="
csv="${MATRIX_ROOT}/summary.csv"
if [[ -f "${csv}" ]]; then
    cat "${csv}"
fi
