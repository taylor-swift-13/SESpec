# RQ6 strength comparisons

## Authoritative completed human review

The authors confirmed on 2026-10-12 that the current paper reports completed human-reviewed results. The authoritative records are in `judge/implication_pre_post_invariant_gpt54_openlux_20260912/`:

- `expert_reviewed_results.csv`: 2,989 substantive dimension-level decisions, 2,957 unchanged and 32 corrected.
- `expert_review_corrections.csv`: individual corrections.
- `expert_reviewed_summary.csv`: aggregates of the 2,989 substantive decisions.
- `paper_expert_reviewed_summary.csv`: full paper totals, adding 766 deterministic equal decisions (3,755 comparisons overall).

The different denominators are intentional. The 766 deterministic equal decisions are not additional human-reviewed decisions. Raw `results.csv` and `summary.csv` precede human correction.

The separate 100-pair template under `expert/human_evaluation/` and its supporting human reviews are separate materials, not the records of the completed paper review. Blank reviewer CSVs in that template do not imply that the paper review is incomplete. All review ratings are human-reviewed, as clarified by the authors. Supporting subsets must not replace the authoritative paper totals.


The paper reports the dimension-wise judge results after expert correction, the
A/B-order audit, and the independent Frama-C/WP cross-check. Earlier prompt
iterations and pilot evaluations remain here for provenance.

| Location | Role |
| --- | --- |
| `judge/implication_pre_post_invariant_gpt54_openlux_20260912/` | Final separate precondition, postcondition, and invariant judge results; `expert_reviewed_results.csv` records the corrections |
| `judge/position_swap_gpt54_openlux_20260912/` | A/B-order audit |
| `expert/human_evaluation/` | Separate historical 100-pair template; its blank CSVs are not the completed paper review records |
| `formal/strength_full_autospec_20260912/` | Complete-set Frama-C/WP implication check |
| Other dated directories | Historical analyses, prompt pilots, and supporting checks |

The CSV and JSON files keep their original case identifiers and archived source
paths. Live tools resolve those source paths through `tools/paper_data_paths.py`.
