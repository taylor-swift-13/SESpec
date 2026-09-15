# Paper experiment data

This directory follows the paper's sections. Raw experiment outputs are preserved; the organization changes directory paths, not the measurements or generated specifications.

| Directory | Paper section | Contents |
| --- | --- | --- |
| `benchmark/` | Goal-independent evaluation setup | C and Java inputs; case alignment report |
| `rq5_validity/` | RQ5 | Per-method, per-model runs in `runs/`; aggregate validity results and refinement ablation |
| `rq6_strength/` | RQ6 and Appendix C | `judge/` comparisons and order checks, `expert/` reviews, `formal/` WP checks |
| `rq7_cost/` | RQ7 | Cost reanalysis and its source audit |
| `rq8_failures/` | RQ8 | Failure-characterization run and logs |
| `case_studies/` | Case Studies | Case-specific inputs and analyses |
| `appendix_d_translation/` | Appendix D | Java/C translation checks |

Directory names use lowercase `snake_case`. Dated run directories retain their dates so distinct experiments remain identifiable. Method directories under `rq5_validity/runs/` use `autospec`, `llm_c`, `llm_java`, `sespec`, `sespec_no_refine`, `sespec_trivial_refine`, and `specgen`. Inside each method, the original model and case identifiers are unchanged.

Some archived JSON and logs contain the absolute paths used when the experiments were run. Those strings are retained as provenance; the live analysis scripts use the paths above. New RQ7 reanalysis should be generated under `rq7_cost/reanalysis/`.
