#!/usr/bin/env bash
# Run the regression bench with refine_count=10 across three models:
#   gpt-4o, gpt-5-mini, gpt-5.4-mini
#
# Usage:
#   OPENAI_API_KEY=... ./run_regression_3models_refine10.sh
#
# Optional:
#   WORKERS=10 ./run_regression_3models_refine10.sh

set -u

REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
TS="$(date +%Y%m%d_%H%M%S)"
RESULTS_ROOT="${SRC}/results/matrix_runs/regression_${TS}_refine10_3models"
LOG_DIR="${RESULTS_ROOT}/_runner_logs"
WORKERS="${WORKERS:-30}"

mkdir -p "${LOG_DIR}"

export PATH="/home/yangfp/.opam/default/bin:${PATH}"

if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2
    exit 1
fi

JOBS=(
    "motivation0_seon  motivation_example  0"
    "motivation2_seon  motivation_example  2"
    "ligmm1_seon       LIG-MM              1"
    "linear1_seon      linear              1"
    "linear3_seon      linear              3"
)

declare -A PIDS=()

cd "${SRC}"

for spec in "${JOBS[@]}"; do
    read -r tag bench case_id <<<"${spec}"
    out="${RESULTS_ROOT}/${tag}"
    log="${LOG_DIR}/${tag}.log"
    echo "▶ ${tag}  (bench=${bench} case=${case_id} models=3 refine=10 workers=${WORKERS})  →  ${out}"
    "${PY}" -c "
import sys
import sespec_matrix as m

m.PRESETS['sespec_default']['refine_count'] = 10
sys.argv = [
    'sespec_matrix.py',
    '--bench', '${bench}',
    '--cases', '${case_id}',
    '--models', 'gpt-4o', 'gpt-5-mini', 'gpt-5.4-mini',
    '--labels', 'sespec_default',
    '--workers', '${WORKERS}',
    '--use-se',
    '--matrix-root', '${out}',
]
raise SystemExit(m.main())
" >"${log}" 2>&1 &
    PIDS["${tag}"]=$!
done

echo
echo "Launched ${#PIDS[@]} jobs. Waiting..."

declare -A STATUS=()
for tag in "${!PIDS[@]}"; do
    wait "${PIDS[${tag}]}"
    STATUS["${tag}"]=$?
done

echo
echo "===== Results (${RESULTS_ROOT}) ====="
printf "%-22s %-8s %s\n" "tag" "rc" "summary"
for spec in "${JOBS[@]}"; do
    read -r tag _ _ <<<"${spec}"
    rc="${STATUS[${tag}]:-?}"
    csv="${RESULTS_ROOT}/${tag}/summary.csv"
    if [[ -f "${csv}" ]]; then
        tail -n +2 "${csv}" | while IFS= read -r body; do
            printf "%-22s %-8s %s\n" "${tag}" "${rc}" "${body}"
        done
    else
        printf "%-22s %-8s %s\n" "${tag}" "${rc}" "(no summary.csv)"
    fi
done
