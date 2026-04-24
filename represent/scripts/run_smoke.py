from __future__ import annotations

import argparse
import json

from represent.api.config import get_settings
from represent.runners import run_autospec, run_sespec, run_specgen


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--project", choices=["sespec", "autospec", "specgen", "all"], default="all")
    parser.add_argument("--model", default=None)
    args = parser.parse_args()

    settings = get_settings()
    models = [args.model] if args.model else settings.model_list[:1]
    results = []
    for model in models:
        if args.project in ("sespec", "all"):
            results.append(run_sespec(model))
        if args.project in ("autospec", "all"):
            results.append(run_autospec(model))
        if args.project in ("specgen", "all"):
            results.append(run_specgen(model))
    print(json.dumps(results, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

