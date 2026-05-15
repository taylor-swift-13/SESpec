#!/usr/bin/env bash
# Run regression matrix invocations in parallel (use_se=on only):
#   motivation_example/0, motivation_example/2, LIG-MM/1, linear/1, linear/3,
#   sespec/4 (global-state smoke test)
#
# Usage:  OPENAI_API_KEY=... ./run_regression.sh
#         (PATH must include frama-c — script prepends opam default bin)

set -u

REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
TS="$(date +%Y%m%d_%H%M%S)"
RESULTS_ROOT="${SRC}/results/matrix_runs/regression_${TS}"
LOG_DIR="${RESULTS_ROOT}/_runner_logs"
REFINE_COUNT="${REFINE_COUNT:-10}"

mkdir -p "${LOG_DIR}"

export PATH="/home/yangfp/.opam/default/bin:${PATH}"

if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2
    exit 1
fi

# (label, bench, case, se_flag)
JOBS=(
    "motivation0_seon  motivation_example  0   --use-se"
    "motivation2_seon  motivation_example  2   --use-se"
    "ligmm1_seon       LIG-MM              1   --use-se"
    "linear1_seon      linear              1   --use-se"
    "linear3_seon      linear              3   --use-se"
    "sespec4_seon      sespec              4   --use-se"
    "sygus86_seon      syGus_code2inv      86  --use-se"
    "sygus88_seon      syGus_code2inv      88  --use-se"
)

declare -A PIDS=()

cd "${SRC}"

for spec in "${JOBS[@]}"; do
    read -r tag bench case_id se <<<"${spec}"
    out="${RESULTS_ROOT}/${tag}"
    log="${LOG_DIR}/${tag}.log"
    echo "▶ ${tag}  (bench=${bench} case=${case_id} ${se})  →  ${out}"
    "${PY}" sespec_matrix.py \
        --bench "${bench}" \
        --cases "${case_id}" \
        --models gpt-4o \
        --labels sespec_default \
        --refine-count "${REFINE_COUNT}" \
        --workers 1 \
        ${se} \
        --matrix-root "${out}" \
        >"${log}" 2>&1 &
    PIDS["${tag}"]=$!
done

echo
echo "Launched ${#PIDS[@]} jobs. Waiting…"

declare -A STATUS=()
for tag in "${!PIDS[@]}"; do
    wait "${PIDS[${tag}]}"
    STATUS["${tag}"]=$?
done

echo
echo "===== Results (${RESULTS_ROOT}) ====="
printf "%-22s %-8s %s\n" "tag" "rc" "summary"
for spec in "${JOBS[@]}"; do
    read -r tag _ _ _ <<<"${spec}"
    rc="${STATUS[${tag}]:-?}"
    csv="${RESULTS_ROOT}/${tag}/summary.csv"
    if [[ -f "${csv}" ]]; then
        body="$(tail -n +2 "${csv}" | head -n1)"
    else
        body="(no summary.csv)"
    fi
    printf "%-22s %-8s %s\n" "${tag}" "${rc}" "${body}"
done
