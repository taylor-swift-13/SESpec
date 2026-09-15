#!/usr/bin/env python3
"""Position-bias audit with A=SESpec and B=baseline.

The reported normalized verdict uses the original orientation
(A=baseline, B=SESpec), so it can be compared directly with the main run.
"""
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
import csv
import json
import os
from pathlib import Path
import sys
import time

from openai import OpenAI

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rerun_contract_judge as base
from judge_prompts import PROMPTS
from judge_routing import comparison_view
from paper_data_paths import resolve_path

ROOT = Path(__file__).resolve().parents[1]
PD = ROOT / 'RESULTS/paper_data'
SOURCE = PD / 'rq6_strength/judge/implication_pre_post_invariant_gpt54_openlux_20260912'
OUT = PD / 'rq6_strength/judge/position_swap_gpt54_openlux_20260912'
MODEL = os.environ.get('JUDGE_MODEL', 'gpt-5.4')
BASE_URL = os.environ.get('JUDGE_BASE_URL', 'https://api.openlux.ai/v1')


def read_csv(path):
    with path.open(newline='') as stream:
        return list(csv.DictReader(stream))


def save_json(path, value):
    temp = path.with_suffix(path.suffix + '.tmp')
    temp.write_text(json.dumps(value, ensure_ascii=False, indent=2) + '\n')
    temp.replace(path)


def swap_verdict(verdict):
    return {'A_stronger': 'B_stronger', 'B_stronger': 'A_stronger'}.get(verdict, verdict)


def swapped_template(basis, lang_b):
    system, template = PROMPTS[basis]
    template = template.replace(
        'Specification B (C/ACSL):\n```c',
        'Specification B ({lang_b}):\n```{lang_b}',
    )
    return system, template, lang_b


def run_one(api, row):
    start = time.monotonic()
    basis = row['comparison_basis']
    result = dict(row, status='error', verdict='', normalized_verdict='',
                  order='A=SESpec,B=baseline', judge_model=MODEL,
                  timestamp=datetime.now(timezone.utc).isoformat())

    deterministic = base.deterministic_result(row)
    if deterministic:
        original_verdict, _ = deterministic
        result.update(status='rated', verdict=swap_verdict(original_verdict),
                      normalized_verdict=original_verdict,
                      response_model='deterministic-rule', finish_reason='rule',
                      raw_response='', elapsed_seconds=round(time.monotonic() - start, 3))
        return result

    baseline_language = 'c' if row['baseline'] == 'autospec' else 'java'
    baseline_source = resolve_path(row['baseline_path']).read_text()
    sespec_source = resolve_path(row['sespec_path']).read_text()
    spec_a = comparison_view(sespec_source, 'c', row['sespec_func'], basis)
    spec_b = comparison_view(
        baseline_source, baseline_language, row['baseline_func'], basis,
        expected_arity=int(row['B_parameter_count']),
    )
    system, template, lang_b = swapped_template(basis, baseline_language)
    prompt = template.format(lang_a='c', lang_b=lang_b, spec_a=spec_a, spec_b=spec_b)
    result['input_sha256'] = base.sha(prompt.encode())
    try:
        response = api.chat.completions.create(
            model=MODEL,
            messages=[{'role': 'system', 'content': system},
                      {'role': 'user', 'content': prompt}],
            max_tokens=2048,
        )
        raw = response.choices[0].message.content or ''
        parsed = json.loads(raw)
        if response.choices[0].finish_reason != 'stop':
            raise ValueError('incomplete response')
        verdict = base.implication_verdict(basis, parsed)
        result.update(status='rated', verdict=verdict,
                      normalized_verdict=swap_verdict(verdict),
                      response_model=response.model,
                      finish_reason=response.choices[0].finish_reason,
                      raw_response=raw,
                      usage=response.usage.model_dump() if response.usage else {})
    except Exception as exc:
        result['error_type'] = type(exc).__name__
        result['http_status'] = getattr(exc, 'status_code', None)
    result['elapsed_seconds'] = round(time.monotonic() - start, 3)
    return result


def write_results(tasks):
    results = []
    for task in tasks:
        path = OUT / 'cases' / (task['task_id'] + '.json')
        results.append(json.loads(path.read_text()) if path.exists() else dict(task, status='pending'))
    fields = sorted({key for row in results for key in row if key not in {'judge_output', 'usage'}})
    with (OUT / 'results.csv').open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows([{key: row.get(key, '') for key in fields} for row in results])
    return results


def summarize(results):
    original = {row['task_id']: row for row in read_csv(SOURCE / 'results.csv')}
    rows = []
    for baseline in ['autospec', 'specgen']:
        for basis in PROMPTS:
            subset = [row for row in results if row['baseline'] == baseline
                      and row['comparison_basis'] == basis and row['status'] == 'rated']
            comparable = [row for row in subset if original[row['task_id']]['status'] == 'rated']
            agree = sum(row['normalized_verdict'] == original[row['task_id']]['verdict']
                        for row in comparable)
            old = Counter(original[row['task_id']]['verdict'] for row in comparable)
            new = Counter(row['normalized_verdict'] for row in comparable)
            rows.append({
                'baseline': baseline, 'comparison_basis': basis,
                'compared': len(comparable), 'agreements': agree,
                'agreement_percent': round(100 * agree / len(comparable), 1) if comparable else 0,
                **{f'original_{key}': old[key] for key in base.VERDICTS},
                **{f'swapped_{key}': new[key] for key in base.VERDICTS},
            })
    with (OUT / 'summary.csv').open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=rows[0])
        writer.writeheader()
        writer.writerows(rows)
    return rows


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / 'cases').mkdir(exist_ok=True)
    manifest = read_csv(SOURCE / 'manifest.csv')
    tasks = base.comparison_tasks(manifest)
    config = {
        'judge_model': MODEL, 'base_url': BASE_URL, 'max_tokens': 2048,
        'temperature': 'provider_default', 'top_p': 'provider_default',
        'reasoning_effort': 'provider_default', 'order': 'A=SESpec,B=baseline',
        'input_truncation': False, 'total_tasks': len(tasks),
        'source_run': str(SOURCE),
    }
    save_json(OUT / 'config.json', config)
    todo = [row for row in tasks
            if not (OUT / 'cases' / (row['task_id'] + '.json')).exists()]
    key = os.environ.get('OPENAI_API_KEY')
    if not key:
        raise RuntimeError('OPENAI_API_KEY is not configured')
    api = OpenAI(api_key=key, base_url=BASE_URL, timeout=120.0, max_retries=2)
    print(json.dumps({'scheduled': len(todo), 'total': len(tasks)}), flush=True)
    with ThreadPoolExecutor(max_workers=8) as executor:
        futures = {executor.submit(run_one, api, row): row for row in todo}
        for index, future in enumerate(as_completed(futures), 1):
            row = future.result()
            save_json(OUT / 'cases' / (row['task_id'] + '.json'), row)
            if index % 25 == 0 or index == len(futures):
                counts = Counter(
                    json.loads(path.read_text()).get('status')
                    for path in (OUT / 'cases').glob('*.json')
                )
                print(index, '/', len(futures), dict(counts), flush=True)
    results = write_results(tasks)
    print(json.dumps(summarize(results), indent=2), flush=True)


if __name__ == '__main__':
    main()
