#!/usr/bin/env bash
set -euo pipefail

cd /home/yangfp/SESpec

export OPENAI_API_KEY="${OPENAI_API_KEY:-你的key}"

if [[ "${OPENAI_API_KEY}" == "你的key" ]]; then
  echo "Please set OPENAI_API_KEY before running this script."
  echo "Example: OPENAI_API_KEY=sk-... bash represent/scripts/run_matrix.sh linear"
  exit 1
fi

GROUP="${1:-all}"
shift || true

conda run -n SpecAutoGen python -m represent.scripts.run_matrix --group "${GROUP}" "$@"
