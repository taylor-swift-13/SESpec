#!/usr/bin/env python3
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, wait, FIRST_COMPLETED
import csv
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import sys
import time

from openai import OpenAI
from judge_stronger import JUDGE_MODEL as DEFAULT_JUDGE_MODEL, BASE_URL as DEFAULT_BASE_URL
from judge_prompts import PROMPTS
from judge_routing import ROUTING_VERSION, route_pair

ROOT = Path(__file__).resolve().parents[1]
PD = ROOT / 'RESULTS/paper_data'
BASE_URL = os.environ.get('JUDGE_BASE_URL', DEFAULT_BASE_URL)
JUDGE_MODEL = os.environ.get('JUDGE_MODEL', DEFAULT_JUDGE_MODEL)
OUT = Path(os.environ.get('JUDGE_OUTPUT_DIR', str(PD / 'judge_split_prompts_20260912')))
MODELS = ['gpt-4o', 'gpt-5-mini', 'gpt-5.4-mini', 'gpt-5']
VERDICTS = ['B_stronger', 'A_stronger', 'equal', 'incomparable']


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read(path):
    with path.open(newline='') as f:
        return list(csv.DictReader(f))


def write(path, rows):
    temp = path.with_suffix(path.suffix + '.tmp')
    with temp.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    temp.replace(path)


def save(path, data):
    temp = path.with_suffix('.tmp')
    temp.write_text(json.dumps(data, ensure_ascii=False, indent=2) + '\n')
    temp.replace(path)


def identity(row):
    return tuple(row[k] for k in ['baseline', 'model', 'sespec_case_id', 'baseline_case_id'])


def prepare():
    original = read(PD / 'judge_pairs/repaired_pairs.csv')
    auto = read(PD / 'eval_autospec_698/manifest.csv')
    rows = auto + [r for r in original if r['baseline'] == 'specgen']
    assert len(rows) == len({identity(r) for r in rows}) == 1371
    for baseline, counts in [('autospec', [74, 102, 242, 280]), ('specgen', [110, 133, 191, 239])]:
        assert Counter(r['model'] for r in rows if r['baseline'] == baseline) == dict(zip(MODELS, counts))
    for row in rows:
        row['pair_id'] = sha('|'.join(identity(row)).encode())[:20]
        for side in ['baseline', 'sespec']:
            row[side + '_sha256'] = sha(Path(row[side + '_path']).read_bytes())
        route = route_pair(Path(row['baseline_path']).read_text(), Path(row['sespec_path']).read_text(),
                           'c' if row['baseline'] == 'autospec' else 'java',
                           row['baseline_func'], row['sespec_func'])
        row['comparison_basis'] = route['comparison_basis']
        for label in ['A', 'B']:
            row.update({label + '_' + k: str(v) for k, v in route[label].items()})
    config = dict(judge_model=JUDGE_MODEL, base_url=BASE_URL, max_tokens=2048,
                  temperature='provider_default', top_p='provider_default',
                  reasoning_effort='provider_default', order='A=baseline,B=SESpec',
                  input_truncation=False, rubric='separate_contract_and_invariant_prompts',
                  routing_version=ROUTING_VERSION, routing_code_sha256=sha((ROOT / 'tools/judge_routing.py').read_bytes()),
                  prompts={basis: dict(system_prompt=system, user_template=template)
                           for basis, (system, template) in PROMPTS.items()},
                  source_manifest_sha256=sha((PD / 'judge_pairs/repaired_pairs.csv').read_bytes()),
                  autospec_manifest_sha256=sha((PD / 'eval_autospec_698/manifest.csv').read_bytes()))
    OUT.mkdir(exist_ok=True)
    if (OUT / 'config.json').exists():
        assert json.loads((OUT / 'config.json').read_text()) == config
        assert read(OUT / 'manifest.csv') == rows
    else:
        save(OUT / 'config.json', config)
        write(OUT / 'manifest.csv', rows)
        save(OUT / 'paper_hashes_before.json',
             {str(p.relative_to(ROOT)): sha(p.read_bytes()) for p in (ROOT / 'paper').rglob('*')
              if p.is_file() and p.suffix in {'.tex', '.pdf'}})
    (OUT / 'cases').mkdir(exist_ok=True)
    return rows


def client():
    key = os.environ.get('OPENAI_API_KEY')
    if not key:
        sys.path.insert(0, str(ROOT / 'src'))
        from config import LLMConfig
        settings = LLMConfig()
        if settings.base_url.rstrip('/') != BASE_URL.rstrip('/'):
            raise RuntimeError('Configured credential endpoint differs from judge endpoint')
        key = settings.api_key
    if not key:
        raise RuntimeError('No configured API credential')
    return OpenAI(api_key=key, base_url=BASE_URL, timeout=120.0, max_retries=2)


def run_one(api, row):
    start = time.monotonic()
    specs = {side: Path(row[side + '_path']).read_text() for side in ['baseline', 'sespec']}
    for side in ['baseline', 'sespec']:
        if sha(Path(row[side + '_path']).read_bytes()) != row[side + '_sha256']:
            raise RuntimeError('Frozen input changed')
    basis = row['comparison_basis']
    system, template = PROMPTS[basis]
    prompt = template.format(lang_a='c' if row['baseline'] == 'autospec' else 'java',
                             spec_a=specs['baseline'], spec_b=specs['sespec'])
    prompt += ('\nTarget functions: A = ' + row['baseline_func'] + '; B = ' + row['sespec_func']
               + '. Judge only these target functions.\n')
    result = dict(row, status='error', verdict='', input_sha256=sha(prompt.encode()),
                  judge_model=JUDGE_MODEL, timestamp=datetime.now(timezone.utc).isoformat())
    try:
        response = api.chat.completions.create(
            model=JUDGE_MODEL, messages=[dict(role='system', content=system),
                                       dict(role='user', content=prompt)], max_tokens=2048)
        raw = response.choices[0].message.content or ''
        result['raw_response'] = raw
        result['finish_reason'] = response.choices[0].finish_reason
        result['response_model'] = response.model
        result['usage'] = response.usage.model_dump() if response.usage else {}
        parsed = json.loads(raw)
        assert parsed.get('verdict') in VERDICTS
        assert 'comparison_basis' not in parsed or parsed['comparison_basis'] == basis
        assert response.choices[0].finish_reason == 'stop'
        result.update(status='rated', verdict=parsed['verdict'])
    except Exception as exc:
        result['error_type'] = type(exc).__name__
        result['http_status'] = getattr(exc, 'status_code', None)
    result['elapsed_seconds'] = round(time.monotonic() - start, 3)
    return result


def report(rows):
    results = []
    for row in rows:
        path = OUT / 'cases' / (row['pair_id'] + '.json')
        if path.exists():
            result = json.loads(path.read_text())
            assert identity(result) == identity(row)
            for side in ['baseline', 'sespec']:
                assert result[side + '_sha256'] == row[side + '_sha256']
            assert result['comparison_basis'] == row['comparison_basis']
        else:
            result = dict(row, status='pending', verdict='')
        results.append(result)
    fields = list(rows[0]) + ['status', 'verdict', 'elapsed_seconds', 'error_type', 'http_status']
    write(OUT / 'results.csv', [{k: r.get(k, '') for k in fields} for r in results])
    summaries = []
    for baseline in ['autospec', 'specgen']:
        for model in MODELS + ['Total']:
            subset = [r for r in results if r['baseline'] == baseline and (model == 'Total' or r['model'] == model)]
            counts = Counter(r['verdict'] for r in subset if r['status'] == 'rated')
            statuses = Counter(r['status'] for r in subset)
            bases = Counter(r.get('comparison_basis') for r in subset if r['status'] == 'rated')
            summaries.append(dict(baseline=baseline, model=model, pairs=len(subset),
                                  rated=statuses['rated'], pending=statuses['pending'], errors=statuses['error'],
                                  contract_comparisons=bases['contract'], invariant_comparisons=bases['loop_invariants'],
                                  **{key: counts[key] for key in VERDICTS}))
    write(OUT / 'summary.csv', summaries)
    status = dict(total=len(rows), **Counter(r['status'] for r in results))
    save(OUT / 'progress.json', status)
    return status


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--limit', type=int)
    parser.add_argument('--workers', type=int, default=8)
    parser.add_argument('--prepare-only', action='store_true')
    args = parser.parse_args()
    rows = prepare()
    if args.prepare_only:
        print(json.dumps(report(rows)), flush=True)
        return
    todo = []
    for row in rows:
        path = OUT / 'cases' / (row['pair_id'] + '.json')
        if not path.exists() or json.loads(path.read_text())['status'] != 'rated':
            todo.append(row)
    if args.limit:
        todo = todo[:args.limit]
    api = client()
    print(json.dumps(dict(scheduled=len(todo), workers=args.workers)), flush=True)
    last_report = time.monotonic()
    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        pending = {pool.submit(run_one, api, row): row for row in todo}
        while pending:
            done, _ = wait(pending, timeout=20, return_when=FIRST_COMPLETED)
            for future in done:
                row = pending.pop(future)
                save(OUT / 'cases' / (row['pair_id'] + '.json'), future.result())
            if time.monotonic() - last_report >= 20:
                print(json.dumps(report(rows)), flush=True)
                last_report = time.monotonic()
    for path, digest in json.loads((OUT / 'paper_hashes_before.json').read_text()).items():
        assert sha((ROOT / path).read_bytes()) == digest, path
    print(json.dumps(report(rows)), flush=True)


if __name__ == '__main__':
    main()
