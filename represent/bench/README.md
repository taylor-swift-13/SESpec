Current bench snapshot for `represent/bench`.

**Dataset Construction**
This benchmark collection is built from three source families: `FormalBench`, `SpecGenBench`, and `SV-COMP`.
self-contained programs that stay within the practical support range of JML/OpenJML and ACSL/Frama-C. Duplicate variants are removed, and cases with unsupported language features, heavy library dependence, or clearly invalid translations are excluded or skipped.

Source buckets:
- `FormalBench`
  Collected from the FormalBench repository and the FormalBench HuggingFace dataset snapshot.
- `SpecGenBench`
  Collected from `represent/external/specgen-artifact/benchmark/SpecGenBench/...`.
- `SV-COMP`
  Collected from `represent/external/specgen-artifact/benchmark/SVCOMP/...`.
  Local numeric-loop datasets are also merged into this bucket:
  `src/input/linear`, `src/input/NLA_lipus`, and `src/input/numer-s`.

**Layout**
- Flattened outputs only:
  - `java_flat/`
  - `c_flat/`
- `mapping.tsv` is the authoritative mapping table.
- File names now start with their source family:
  - `FormalBench_...`
  - `SpecGenBench_...`
  - `SVCOMP_...`

**Selection Rules**
- Deduplicated by normalized Java source content.
- C-facing bench files are kept even if some later experiments may skip them at runtime.


**Generation Command**
```bash
python3 -m represent.scripts.materialize_bench --formalbench-target 350 --target-total 500
```

**Expected Invariants**
- `mapping.tsv` row count equals the number of files in `java_flat/` and `c_flat/`.
- No duplicate Java sources remain after selection.
- File names are stable ids for experiment runners.
