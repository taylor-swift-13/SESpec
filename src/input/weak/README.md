# Weak SESpec Cases

This directory contains SESpec inputs where the default SESpec run was verifier-valid but the semantic-completeness judge marked the generated specification as weak or incomplete.

Selection criteria:

- `valid_pass == true` in `sespec_default` results.
- `judge_score == 0`.
- The judge reason explicitly mentions weak/incomplete specifications, such as vacuous `ensures \true`, missing return semantics, bounds-only loop invariants, or missing memory/effect semantics.
- Cases are prioritized when the weakness appears across multiple models.

See `weak_cases.csv` for the source case, failed models, weakness category, example judge reason, and example generated candidate path.

Additional SV-COMP numeric-loop cases were added by selecting scalar loop programs whose SESpec output was verifier-valid but judged incomplete because loop invariants were bounds-only, failed to determine the final value, or failed to characterize the numeric loop effect.
