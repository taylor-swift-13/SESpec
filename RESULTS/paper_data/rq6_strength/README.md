# RQ6 strength comparisons

The paper reports the dimension-wise judge results after expert correction, the
A/B-order audit, and the independent Frama-C/WP cross-check. Earlier prompt
iterations and pilot evaluations remain here for provenance.

| Location | Role |
| --- | --- |
| `judge/implication_pre_post_invariant_gpt54_openlux_20260912/` | Final separate precondition, postcondition, and invariant judge results; `expert_reviewed_results.csv` records the corrections |
| `judge/position_swap_gpt54_openlux_20260912/` | A/B-order audit |
| `expert/human_evaluation/` | Prepared two-reviewer evaluation package; the checked rating CSVs are currently unfilled |
| `formal/strength_full_autospec_20260912/` | Complete-set Frama-C/WP implication check |
| Other dated directories | Historical analyses, prompt pilots, and supporting checks |

The CSV and JSON files keep their original case identifiers and archived source
paths. Live tools resolve those source paths through `tools/paper_data_paths.py`.
