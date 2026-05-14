#!/usr/bin/env bash
# Run src/input/sespec/*.c across four SESpec ablation variants and three models.
# sespec_default uses refine_count=10; the no_repair* variants disable refine,
# and progressively also disable examples / symbolic execution.
#
# Models:
#   gpt-4o, gpt-5-mini, gpt-5.4-mini
#
# Usage:
#   OPENAI_API_KEY=... ./run_sespec_input_3models_refine10.sh
#
# Optional:
#   WORKERS=10 ./run_sespec_input_3models_refine10.sh

set -u

REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
TS="$(date +%Y%m%d_%H%M%S)"
MATRIX_ROOT="${SRC}/results/matrix_runs/${TS}_input_sespec_4variants_3models"
LOG_DIR="${MATRIX_ROOT}/_runner_logs"
WORKERS="${WORKERS:-30}"

MODELS=(gpt-4o gpt-5-mini gpt-5.4-mini)
LABELS=(
    sespec_default
    sespec_no_repair
    sespec_no_exm_no_repair
    sespec_no_se_no_exm_no_repair
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
echo "sespec_default refine_count: 10"
echo

"${PY}" -c "
import sys
import sespec_matrix as m

m.PRESETS['sespec_default']['refine_count'] = 10
m.PRESETS['sespec_no_repair'] = dict(m.PRESETS['sespec_default'], refine_count=0)
m.PRESETS['sespec_no_exm_no_repair'] = dict(
    m.PRESETS['sespec_default'],
    refine_count=0,
    use_examples=False,
)
m.PRESETS['sespec_no_se_no_exm_no_repair'] = dict(
    m.PRESETS['sespec_default'],
    refine_count=0,
    use_examples=False,
    use_se=False,
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
raise SystemExit(m.main())
" 2>&1 | tee "${LOG_DIR}/sespec.log"

echo
echo "===== DONE ${MATRIX_ROOT} ====="
csv="${MATRIX_ROOT}/summary.csv"
if [[ -f "${csv}" ]]; then
    cat "${csv}"
fi
