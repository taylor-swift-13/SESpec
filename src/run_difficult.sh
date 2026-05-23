#!/usr/bin/env bash
# Run every Difficult/<id>.c case in parallel.
# Usage:  OPENAI_API_KEY=... ./run_difficult.sh [parallelism] [case_id1 case_id2 ...]
#         parallelism defaults to 8; if no case ids given, all .c under
#         Difficult/ are run.

set -u

REPO_ROOT="/home/yangfp/SESpec"
SRC="${REPO_ROOT}/src"
PY="/home/yangfp/miniconda3/envs/SpecAutoGen/bin/python"
PARALLEL="${1:-8}"
shift || true
CASES=("$@")
if [[ ${#CASES[@]} -eq 0 ]]; then
    while IFS= read -r f; do
        CASES+=("$(basename "${f}" .c)")
    done < <(ls "${SRC}/input/Difficult"/*.c 2>/dev/null | sort -V)
fi

TS="$(date +%Y%m%d_%H%M%S)"
RESULTS_ROOT="${SRC}/results/matrix_runs/difficult_${TS}"
LOG_DIR="${RESULTS_ROOT}/_runner_logs"
mkdir -p "${LOG_DIR}"

export PATH="/home/yangfp/.opam/default/bin:${PATH}"
if [[ -z "${OPENAI_API_KEY:-}" ]]; then
    echo "OPENAI_API_KEY is not set" >&2
    exit 1
fi

cd "${SRC}"

declare -A PIDS=()
declare -A STATUS=()
RUNNING=0

drain() {
    local target=$1
    while [[ ${RUNNING} -gt ${target} ]]; do
        for tag in "${!PIDS[@]}"; do
            pid="${PIDS[${tag}]}"
            if ! kill -0 "${pid}" 2>/dev/null; then
                wait "${pid}" 2>/dev/null
                STATUS["${tag}"]=$?
                unset PIDS["${tag}"]
                RUNNING=$((RUNNING - 1))
            fi
        done
        sleep 1
    done
}

for case_id in "${CASES[@]}"; do
    drain $((PARALLEL - 1))
    out="${RESULTS_ROOT}/case_${case_id}"
    log="${LOG_DIR}/case_${case_id}.log"
    "${PY}" sespec_matrix.py \
        --bench Difficult \
        --cases "${case_id}" \
        --models gpt-4o \
        --labels sespec_default \
        --workers 1 \
        --use-se \
        --matrix-root "${out}" \
        >"${log}" 2>&1 &
    PIDS["case_${case_id}"]=$!
    RUNNING=$((RUNNING + 1))
done

drain 0

echo
echo "===== Difficult results (${RESULTS_ROOT}) ====="
printf "%-12s %-8s %s\n" "case" "rc" "summary"
for case_id in "${CASES[@]}"; do
    tag="case_${case_id}"
    rc="${STATUS[${tag}]:-?}"
    csv="${RESULTS_ROOT}/${tag}/summary.csv"
    if [[ -f "${csv}" ]]; then
        body="$(tail -n +2 "${csv}" | head -n1)"
    else
        body="(no summary.csv)"
    fi
    printf "%-12s %-8s %s\n" "${case_id}" "${rc}" "${body}"
done

# also write a summary csv
final="${RESULTS_ROOT}/all_summary.csv"
echo "case_id,rc,success,valid,syntax,satisfy,seconds,tokens" >"${final}"
for case_id in "${CASES[@]}"; do
    csv="${RESULTS_ROOT}/case_${case_id}/summary.csv"
    if [[ -f "${csv}" ]]; then
        line="$(tail -n +2 "${csv}" | head -n1)"
        # csv has: label,bench,model,total,success,valid,syntax,satisfy,skip,...,total_seconds,total_tokens
        success=$(echo "${line}" | awk -F',' '{print $5}')
        valid=$(echo "${line}" | awk -F',' '{print $6}')
        syntax=$(echo "${line}" | awk -F',' '{print $7}')
        satisfy=$(echo "${line}" | awk -F',' '{print $8}')
        seconds=$(echo "${line}" | awk -F',' '{print $(NF-1)}')
        tokens=$(echo "${line}" | awk -F',' '{print $NF}')
        echo "${case_id},${STATUS[case_${case_id}]:-?},${success},${valid},${syntax},${satisfy},${seconds},${tokens}" >>"${final}"
    else
        echo "${case_id},${STATUS[case_${case_id}]:-?},,,,,," >>"${final}"
    fi
done
echo
echo "Aggregated CSV: ${final}"
