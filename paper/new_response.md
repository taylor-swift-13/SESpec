# Response to the Reviewers

Dear Dr. Yue and the Associate Editor,

Thank you for considering the revision of manuscript TSE-2026-07-0653 and for forwarding the new review. We appreciate Reviewer 1's confirmation that their earlier questions have been addressed. Below we respond point by point to Reviewer 2's comments. Changes in the marked manuscript are shown in red.

## Reviewer 2, Comment 1: Scope of generated preconditions

We have removed the “weakest” and “minimal” characterization of the default precondition in Section III-B. The revised text calls it a *sufficient precondition for the supported symbolic-execution model*. Pairwise separation and finite value or length bounds are default generation choices, not semantic requirements of every C program. We now state explicitly that a contract containing `\separated` excludes executions in which those particular pointers alias, while this restriction does not mean the framework cannot handle aliasing in other supported cases. This limits the strongest-postcondition claim to executions satisfying the stated precondition and the supported memory model.

## Reviewer 2, Comment 2: Specification-strength methodology and judge order

We have revised RQ6 and its prompt appendix to compare preconditions, postconditions, and loop invariants separately. Preconditions are ordered by inclusion of their accepted input domains; postconditions are compared by implication on the common input domain; and invariants are compared at corresponding loop points. A missing `requires` or `ensures` clause is interpreted as `true`. The paper no longer infers a single overall strength ranking from a stronger postcondition on a narrower domain. Table VII and Fig. 4 report the dimension-wise results, and the full-set Frama-C/WP implication check provides a separate formal cross-check for the AutoSpec pairs. We state that WP's unresolved obligations cannot distinguish a false implication from one whose proof was not completed.

The judge uses GPT-5.4, a 2,048-token output limit, no input truncation, and provider-default temperature, top-p, and reasoning effort. Appendix C records these settings and the A/B-order experiment; Appendix B gives the separate prompts. Two master's-level researchers with formal-verification backgrounds examined the 2,989 non-deterministic dimension-level decisions; 2,957 were left unchanged and 32 were corrected. The remaining 766 pairs had no substantive predicate on either side and were deterministically classified as equal. Table VII and Fig. 4 report the corrected results.

## Reviewer 2, Comment 3: Symbolic-store encoding and undefined behavior

Section III-A now distinguishes the symbolic store as a mapping from its logical encoding. The encoding function \(\rho\) turns a store into equalities between each tracked location at the program point and its symbolic expression over initial values. Proposition 1 uses this relation, along with the path condition, over the common tracked endpoint locations. Its assumptions now require exact representation of relevant memory and aliasing operations, path completeness, and defined execution under the modeled C semantics. The text also states that undefined behavior detected during symbolic execution is reported as an error; it does not yield an exact strongest postcondition. These changes make the proof's state relation and scope explicit.

## Reviewer 2, Comment 4: Construction and semantic checks of SESpec-400

Appendix D now describes the translation procedure and its limits. GPT-5.4 translated 250 FormalBench and 59 SpecGenBench Java programs to C; the other 91 cases are native C. The appendix specifies how primitive types, array lengths, allocation, control flow, and returns were adapted, and gives an example of a Java program excluded because it could not be translated into the supported C fragment. All 400 selected C programs compile under GCC C11.

We also added a differential-execution check covering 4,325 comparable executions across all 309 Java/C pairs, using deterministic edge-case and seeded pseudorandom inputs. Of these executions, 4,323 had matching observed returns and modified integer arrays. The other two inputs, both for case 112, triggered a negative-shift undefined-behavior check in C while Java defined the operation. Thus 308 of 309 pairs had no observed discrepancy on their tested inputs. We describe this as empirical evidence on the common defined-behavior domain, not a proof of unrestricted cross-language equivalence.

## Reviewer 2, Comment 5: Effectiveness versus equal budget, and failure-inclusive cost

Section VII's RQ4 text now identifies Table V as an effectiveness comparison under each method's reported configuration, not a compute-matched comparison. SESpec uses at most five complete generation attempts per program. The original AutoSpec study repeated each program five times with internal iterative synthesis and verification; ACInv's published analysis includes 1, 3, 5, and 10 augmentation cycles. These are different LLM-call, token, and verifier budgets, so Table V is not described as compute-normalized.

We removed the former RQ7 cost table and revised Fig. 5 to stack the cost of valid and failed attempts in each bar. The new analysis covers all 400 gpt-5.4-mini programs for each of the five workflows and reports mean time, token use, and API calls per attempted program. In particular, failed runs contribute 48.1 of SESpec's 318.2 seconds per attempt, versus 519.4 of AutoSpec's 932.1 and 235.0 of SpecGen's 375.5. Dividing total time by the number of valid results yields 338.6, 1,462.1, and 758.6 seconds per obtained valid specification, respectively.

## Reviewer 2, Comment 6: Scope of the RQ8 conclusion

We agree that the prover logs do not establish that every residual failure originates in the verifier rather than in specification synthesis. We revised the RQ8 discussion and Finding accordingly. The paper now states that the observed failures manifest predominantly as SMT timeouts on complex proof obligations, and that Timeout, Unknown, and Failed outcomes cannot distinguish an incorrect generated specification from a correct but difficult obligation that the current ATP backend does not discharge. Our manual inspection of the programs, generated specifications, and unresolved obligations more often points to verifier limitations, particularly for complex loop, array, and heap reasoning, but we explicitly describe this as qualitative evidence that does not rule out synthesis errors in individual cases.

## Reviewer 2, Comment 7: Specification quality in the industrial case

We agree that the 601/625 WP discharge rate measures verifier acceptance, rather than how much functional behavior the generated contracts capture. We therefore added a contract-level manual audit of all 14 functions in the industrial pipeline. We count a postcondition as functional only if it gives a non-vacuous relation between an output or return value and the inputs; in particular, `ensures \true` is not counted as functional behavior.

Ten functions have non-vacuous functional postconditions (`limit_abs`, `q_to_C`, `q_to_Ksi`, `triple_fabs_max`, `vec_cross3`, `vec_scale`, `vec_add`, `vec_sub`, `StsCompensate`, and `StsFilter`). The other four lack a complete functional summary: `StsModify` provides only output bounds, `mat_mul` has the vacuous `ensures \true`, and the no-op helper `q_normalize` and the top-level `CS_Sts_Gyro_Modify_Single_pipeline` have no explicit accepted contract. The revised case study reports these counts and names alongside the WP result, and now states explicitly that the two measurements capture different aspects of quality.

## Reviewer 2, Comment 8: OOPSLA benchmark overlap

We checked the benchmark instances used in our evaluation and found no overlap between the evaluated OOPSLA and SyGuS subsets. The 133 SyGuS programs are linear-loop cases, whereas the 46 OOPSLA programs include 30 linear-loop and 16 nested/multi-loop cases. We therefore retain OOPSLA as a separate benchmark: its nested and multiple loops exercise a program class absent from our SyGuS subset and provide distinct evidence about invariant generation under more complex loop structure. Although later benchmark collections may incorporate or extend programs from earlier sources, our reported totals do not count any shared OOPSLA/SyGuS instance twice.

## Reviewer 2: Editorial points

We corrected the `AUTOSPECserves` typo and the associated spacing issues, and standardized the manuscript on the term *goal-independent*. We also reviewed the uses of “exact,” “minimal,” “stronger,” and “dominant bottleneck.” “Exact” and “strongest” are now reserved for loop-free fragments under the explicit assumptions of Proposition 1; the default generated precondition is described as sufficient for the supported symbolic-execution model rather than minimal; specification comparisons are reported by dimension; and the conclusion no longer attributes residual failures exclusively to the verifier.

We thank the reviewer for these suggestions, which helped us clarify both the scope of the formal claims and the interpretation of the experimental results.

Sincerely,

The Authors
