# represent

This workspace isolates reproduction code, external copies, runners, and results.

Main entrypoints:

- `python -m represent.scripts.materialize_bench`
- `python -m represent.scripts.run_smoke --project sespec --model gpt-4o`
- `python -m represent.scripts.summarize_pass1`

Expected setup:

- conda env: `SpecAutoGen`
- Frama-C: `opam exec --switch=frama-c.27.1 -- frama-c`
- OpenJML: `/home/yangfp/CAV-JAVA/.tools/openjml`
- API config: copy `represent/config/models.example.yaml` to `represent/config/models.yaml`

