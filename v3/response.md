Dear Dr. Pezzè and the Associate Editor,

Thank you for handling our manuscript TSE‑2026‑02‑0150 and for forwarding the detailed reviews. We are grateful to the reviewers for their thorough and constructive comments, which have helped us substantially improve the paper. We have revised the manuscript extensively in response to all the points raised. All changes are highlighted in blue in the annotated version.

Below we provide an overview of the major revisions:

(1) We have added a formal treatment of the strongest postcondition guarantee in Section III. Definition 1 formalizes the notion of the strongest postcondition in the standard Hoare logic sense. Proposition 1 then establishes that, under two explicit assumptions—(A1) scope conditions and (A2) semantic exactness—the symbolic execution derived postcondition is indeed the strongest. The proposition is accompanied by a soundness and completeness proof: soundness ensures every reachable state satisfies it; completeness ensures every state satisfying it is reachable. This makes precise what the guarantee covers and what it does not. Outside the covered fragment, the result is characterized as a sound, best effort over approximation rather than a strongest postcondition guarantee.

(2) We have systematically expanded the empirical evaluation to directly address the reviewers’ concerns about benchmark representativeness (Reviewer 1, Reviewer 2, AE), goal-independent evaluation (Reviewer 2, Reviewer 3), and scalability evidence (Reviewer 1, Reviewer 2). 
First, we have added an entirely new Section VIII, which introduces a completely new evaluation dimension: goal-independent specification generation. We introduce SESpec-400, a 400-program C benchmark with all assertions removed, sourced from FormalBench, SpecGenBench, and native-C SV-COMP. This directly answers the reviewers’ requests for evaluating our method’s claimed goal-independence. In this section, we introduce three new evaluation metrics beyond validity: (1) specification strength (RQ6, via LLM-as-judge and implication checking pairwise comparison), (2) Pass@1 cost analysis (RQ7, time, tokens, API calls, memory), addressing the reviewers’ concerns about runtime overhead, and (3) failure-mode classification and analysis (RQ8). The analysis isolates SMT timeouts on complex proof obligations as the dominant bottleneck.
Second, in Section IX, we add two targeted case studies that address specific reviewer comments: Case 4 directly reproduces Preguss’s linear search example, demonstrating the distinction between RTE-safety synthesis (Preguss’s objective) and functional specification generation (our objective). This responds to the review comment on our comparison to Preguss. Case 5 presents a 225-line industrial single-star-sensor Kalman-update pipeline with 14 functions, 33 call sites, and 8 loops. The result exposes the verifier ceiling (Section IX-E and the matrix-multiplication case in Appendix A), not a generation failure. This directly responds to Reviewer 1’s and Reviewer 2’s concerns about scalability and provides concrete evidence of performance on a realistic industrial fragment.

(3) We have strengthened novelty positioning and external-validity discussion. Table XI and Section XII compare SESpec with representative prior tools, including Daikon, LIPuS, CLAUSE2INV, AutoSpec, ACInv, Preguss, and SpecGen, along clear axes including target, goal dependence, semantic source, data support, and validation strategy. Section XII separately discusses recent Lean-based work such as CLEVER and VERINA, clarifying that these systems target theorem proving in Lean rather than goal-independent ACSL specification generation for off-the-shelf C programs. Section XI clarifies benchmark representativeness and scalability boundaries, acknowledging that our benchmarks align with the state of the art and that we do not claim industrial-scale deployment. 

(4) We have also conducted a thorough, paper-wide revision that goes beyond the specific reviewer requests to strengthen the overall presentation and technical depth. Key enhancements include:

First, we have added a new Section X dedicated to a systematic discussion of limitations and open challenges, and substantially rewritten Section XI (Threats to Validity) to provide a more precise discussion of construct, internal, and external validity. The Abstract and Introduction have been refined to more clearly articulate the problem scope, the novelty of our approach, and the significance of the results.

Second, we have expanded supplementary case studies. In Appendix A, we have added four new case studies that explore different technical boundaries: GCD (inductive-helper synthesis), MulLoop (sign-sensitive invariant synthesis), Ackermann (recursion beyond ACSL/SMT automation), and matrix multiplication (verifier-timeout boundary). These are now organized alongside the main cases in a new Table IX, providing a comprehensive view of SESpec's capabilities and limitations across diverse program patterns.

Third, we have deepened methodological and system description. We have rewritten Section V on verifier-guided refinement to include a clear three-layer structure (syntax repair, strategy-driven refinement, Houdini pruning), with full details in Algorithm 4 and Table I. We have added a new Section VI-B on prompt construction, with all prompt templates now listed in Appendix B. We have also refined Section III-D (LLM Fallback) and Section VII (Experiments) to provide more accurate analysis and explicit findings for each research question.

## Associate Editor

> 1. The novelty relative to prior work is not sharply delineated.

We agree and have systematically strengthened the positioning of our contribution.
First, we added Table XI and rewrote Section XII to compare SESpec with representative prior tools along five axes: target, goal dependence, semantic source, data support, and validation strategy. The table covers Daikon, LIPuS, CLAUSE2INV, AutoSpec, ACInv, Preguss, and SpecGen; Section XII separately discusses recent Lean-based work such as CLEVER and VERINA. Second, the revised discussion identifies ACInv as the closest conceptual neighbor, but explains the key difference: ACInv uses static loop/data abstractions; SESpec uses path sensitive symbolic state snapshots that preserve path conditions, alias/separation facts, and cross field relations, information that static abstractions lose. Third, we clarify the distinction from other approaches: Preguss is safety oriented (RTE elimination), SpecGen is Java/JML based, and Lean based systems require rewriting programs in Lean, whereas SESpec works directly on off the shelf C source. We also include a concrete case comparison (Case 4, Section IX) reproducing Preguss's linear search example, and add a comparison with SpecGen on the new dataset in Section VIII.


> 2. The methodology needs tighter normalization and clearer definitions.

We have clarified and tightened the evaluation methodology on three fronts, directly addressing Reviewer 3's concerns.

First, Pass@k is now unambiguously defined in Section VII‑C as the number of independent generation attempts, where each attempt is a complete pipeline run that may include internal refinement and pruning. Refinement iterations are not counted as additional Pass@k samples: they are treated as verifier-guided internal repair steps within the same complete pipeline attempt, rather than as additional independent generation attempts. We therefore report Pass@k over independent attempts, and separately report the cost of complete Pass@1 runs in wall-clock time, token usage, API calls, and peak memory.

Second, we justify the model selection used in the evaluation. Both experiments are centered on OpenAI model families to reduce cross-provider pretraining-data differences that could confound the comparison, while Section VII additionally includes Claude 3.7 Sonnet as a representative strong code-capable LLM. The results show that SESpec's improvements are not specific to a single LLM.

Third, we add a systematic failure‑mode classification in Section VIII‑E and Table VIII, breaking down unsolved cases by SMT timeouts, postcondition/assigns obligations, unknown/failed prover responses, and syntax errors. This clarifies where the approach faces engineering challenges versus fundamental limitations.

> 3. The evaluation results are limited in scope and complexity, and it is unclear whether the approach can scale to realistic, large-scale benchmarks.
> 4. The benchmark selection is not representative and is overly small.

We have substantially expanded the evidence and placed the scale in the broader formal-verification context. First, we refer the AE to Item (2) of our major revisions overview for the detailed changes.  We added Section VIII, which introduces SESpec 400, a 400 program goal independent benchmark with three new evaluation metrics beyond Validity: specification strength (RQ6), Pass@1 cost analysis (RQ7), and failure mode classification (RQ8). The cost analysis directly addresses the reviewers’ concerns about runtime overhead, and the failure analysis isolates SMT timeouts on verifying proof obligations as the dominant bottleneck. We also added Section IX E, a 225 line industrial pipeline stress test as a scale boundary case; the residual failures expose the verifier ceiling, not a generation failure. Second, we situate this scale in the context of recent automated verification work. As noted in Sections XI and XII, this scale boundary is common in functional-correctness verification: ATP-based pipelines often time out or return Unknown on nonlinear, quantified, and recursively defined obligations. Lean-based systems such as CLEVER and VERINA avoid part of this ATP bottleneck by moving the problem into proof construction and proof search, but their current evaluations are still concentrated on relatively small programs. We therefore present ITP integration in Section X as a future direction whose scalability depends on continued progress in LLM-assisted proof construction.

> 5. Runtime, memory usage, and AI token consumption are lacking.

The new added Section VIII‑D reports cost on SESpec‑400 under the same Pass@1 protocol, with averages reported per valid run where applicable, not as raw LLM-completion counts. The reported dimensions include wall‑clock time, token use, API‑call counts, and peak RSS (~500 MB). We refer the AE to Item (2) of our major revisions overview for the detailed breakdown.

> 6. There is a potential absence of analysis on soundness and completeness.

We have added a formal soundness and completeness analysis in Section III. Please refer to Item (1) of our major revisions overview, which describes Definition 1 and Proposition 1, and the accompanying soundness and completeness proof for the strongest‑postcondition guarantee.

> 7. There is a potential absence of discussion on runtime overhead.

We have added a runtime-overhead discussion in Section VIII-D. Please refer to our response to Comment 5 and Item (2) of the major revisions overview. The main conclusion is, SESpec's added framework complexity mainly appears as higher token use; its wall-clock time and API-call count are much closer to the baselines than the raw token totals alone suggest.


## Reviewer 1

> The results appear quite limited in scope and complexity. The benchmarks selected appear carefully curated and are small in number...

We have addressed this concern in our response to the Associate Editor (Comments 3–4), and summarize the key changes here.

First, Section XI now explicitly clarifies the 21-program subset is "not a uniform sample of the full SV-COMP suite"; it is retained only for a direct AutoSpec comparison. Second, we added an entirely new evaluation dimension in Section VIII: SESpec‑400, a 400‑program goal‑independent benchmark with all assertions removed, plus new metrics for specification strength (RQ6), Pass@1 cost analysis (RQ7), and failure‑mode classification (RQ8). We also added a 225‑line industrial pipeline stress test in Section IX‑E as a scale‑boundary case.
Third, Section XI now explicitly states that we do not claim industrial‑scale deployment, and that our benchmarks represent small‑ to medium‑scale verification tasks consistent with the state of the art. We also note in Sections XI and XII that this boundary is common in functional-correctness verification: ATP-based pipelines often time out or return Unknown on hard obligations, while recent Lean-based systems such as CLEVER and VERINA also remain evaluated on relatively small programs because proof construction and proof search remain difficult. This is why we frame ITP integration as a future route that may scale with stronger LLM proof automation, not as current evidence of industrial-scale verification.

We believe these additions substantially broaden the evaluation scope and make the boundary of our claims precise.

> Their relevance is overstated: e.g., the Sun Search example from the aerospace domain is simplistic...

We agree that the pIp fragments are small and do not represent a full aerospace system. We have therefore clarified in Section VII that pIp is a “small, self-contained industrial sample” rather than evidence of industrial-scale performance. To provide stronger evidence beyond small fragments, we added Section VIII (SESpec‑400, 400 programs) and Section IX‑E (a 225‑line industrial pipeline case). In that pipeline, SESpec produces specifications for 13 of 14 functions and Frama‑C/WP discharges 601/625 VCs (96.2%); the residual failures expose the verifier ceiling, not a generation failure. This provides concrete evidence on a realistic industrial fragment while keeping the scope claim precise.

In Sections X–XI, we also discuss the fundamental reasons behind the current scalability boundary. Section X notes that migrating to an interactive theorem prover (ITP) may be promising because it exposes a richer proof surface for LLM-generated proof scripts; however, scaling this route depends on progress in LLM-assisted proof construction and proof search, and we leave this integration to future work.

> The approach's performance in terms of runtime, memory use, and AI tokens used is lacking.

We refer the reviewer to our responses to AE Comments 5 and 7 and to Item (2) of our major revisions overview, where we have addressed this concern in full. In brief, Section VIII‑D reports wall‑clock time, token use, API‑call counts, and peak RSS on SESpec‑400 under the Pass@1 protocol, with averages reported per valid run where applicable; the key conclusion is that SESpec's added complexity mainly appears as higher token use, while wall‑clock time and API‑call counts are much closer to the baselines.

## Reviewer 2

> Potential concerns on scalability... larger real-world systems with deep control flow and extensive interprocedural interactions.

We have addressed this concern in our responses to AE Comments 3–4 and in Item (2) of our major revisions overview. In summary:

First, we expanded the evidence with SESpec‑400 (Section VIII, 400 programs) and a 225‑line industrial pipeline stress test (Section IX‑E), where SESpec produces specifications for 13 of 14 functions and Frama‑C/WP discharges 601/625 VCs (96.2%); the residual failures expose the verifier ceiling, not a generation failure.

Second, Section XI now explicitly states that we do not claim results on industrial codebases of hundreds of thousands of lines or programs with extensive external library calls.

Third, we also situate this boundary in the broader context: as noted in Sections XI and XII, ATP-based pipelines often time out or return Unknown on hard obligations. Recent Lean-based systems such as CLEVER and VERINA take a different route by shifting the burden to proof construction and proof search; nevertheless, they also remain evaluated on relatively small programs. This route is still promising because its scalability may improve as LLMs become stronger at writing proof scripts, and Section X discusses ITP integration as a direction to raise this boundary.

We believe these additions clarify what SESpec can and cannot do, and ground the scalability discussion in the current state of the field.

> Although the generated specifications are validated through a formal verifier, the involvement of LLMs... is not formally characterized...

We agree and have added a formal treatment in Section III. Definition 1 formalizes the strongest postcondition in the Hoare-logic sense, and Proposition 1 establishes the strongest-postcondition guarantee for covered loop-free fragments, with soundness and completeness proved under two explicit assumptions (scope conditions and semantic exactness). For cases outside the exact symbolic-execution fragment, the revised paper distinguishes the corresponding mechanisms: loops are handled by LoopInvGen, ordinary callees by recursive FuncSpec, while self-recursive functions, recursive data structures, and unsupported function-level cases are handled by the fallback procedure. These cases may still yield verifier-checked specifications, but they no longer carry the strongest-postcondition guarantee; Section X further clarifies that verifier validity does not certify semantic completeness. 

We refer the reviewer to Item (1) of our major revisions overview and our response to AE Comment 6 for further detail.

> Concerning the baseline approaches involved for comparison, some recent LLM-based approaches, such as Clause2Inv...

We have added Clause2Inv to the numerical-invariant comparison in Table V and Section XII. Section XII now clarifies that CLAUSE2INV and LIPuS are mostly confined to numeric programs and generate invariants in SMT format, whereas SESpec targets full C/ACSL functional specifications. The revised comparison includes CLAUSE2INV on SyGuS and NLA. SESpec also covers the harder nested/multi-loop OOPSLA set, whose obligations go beyond the input scope of those numerical-invariant tools.

> Also, despite the language gap... mutual translations between Java/JML and C/ACSL...

We have included SpecGen in Section VIII as a cross-ecosystem reference. The paper clarifies that SpecGen is  the closest goal-independent system but runs in the Java/JML ecosystem, and is therefore included  as a cross-ecosystem reference rather than a direct verifier-level baseline. For C/ACSL evaluation, we use translated programs from FormalBench and SpecGenBench; SpecGen is run on the original Java versions.

> The paper does not provide sufficient discussion on the runtime overhead...

We have addressed this in Section VIII-D and Fig. 5, which report wall-clock time, token use, API-call counts, and peak RSS on SESpec-400 under the Pass@1 protocol, with averages reported per valid run where applicable. The token increase comes mainly from repeated input-side refinement context, while wall-clock time and API-call counts grow less sharply. We refer the reviewer to our responses to AE Comments 5 and 7 and to Item (2) of our major revisions overview for the full discussion.

> Q1. Could the authors provide more descriptions on the "Layer 2 - Adaptive Refinement" mentioned in Section IV-D? Is this process implemented by prompting the LLM only?

We have substantially expanded the description of Layer 2. Section V now presents Algorithm 4 and Table I (the full category-to-strategy mapping). The answer to the reviewer’s specific question is no: Layer 2 is not implemented by prompting alone. The framework (1) classifies verifier failures into typed categories, (2) selects only the strategy blocks whose categories are non-empty, and (3) controls verifier reruns, strategy selection, symbolic context, and Houdini pruning. The LLM is used specifically for repair, but it operates within this structured control loop, not in a standalone prompting fashion. We refer the reviewer to Section V and Table I for the detailscomplete mapping.

> Q2. Could the authors provide analysis for one representative case where SESpec fails?

We have added a detailed failure case in Appendix A, using matrix multiplication as the example suggested by the reviewer. The case demonstrates a verifier-timeout boundary rather than a generation failure: SESpec generates the intended quantified specification and matching outer-loop invariants, and the innermost `s == mat_sum(..., k)` invariant is discharged by one-step induction. The remaining outer quantified invariants and postcondition involving `mat_sum` time out in Z3 because they combine recursive logic unfolding, havoc-updated array memory, and nonlinear index arithmetic. The accepted specification consequently degrades to `ensures \true`. This case is also summarized in Section IX-E, where we note that the residual failures expose the ATP backend ceiling, not a limitation of specification synthesis. We believe this provides a concrete and representative illustration of the dominant failure mode identified in our analysis.



## Reviewer 3

> Novelty relative to prior art is underspecified... Against ACInv... Against Preguss... Against template-based invariant mining...

We have systematically strengthened the novelty positioning in Section XII and Table XI, which now provide a side‑by‑side comparison with representative prior tools along five axes: target, goal dependence, semantic source, data support, and validation strategy.

The revised paper identifies ACInv as the closest conceptual neighbor, but clarifies the key difference: ACInv uses static loop/data abstractions, while SESpec uses path‑sensitive symbolic‑state snapshots that preserve path conditions, alias/separation facts, and cross‑field relations. Against Preguss, we clarify that Preguss is safety‑oriented (RTE elimination), whereas SESpec targets functional specifications; this distinction is made concrete in Case 4 (Section IX), which reproduces Preguss's linear‑search example and contrasts the RTE‑safety specification with the functional specification produced by SESpec. Against template‑based and dynamic methods (e.g., Daikon, CLN2INV), the paper emphasizes that SESpec's templates are derived from path‑complete symbolic states rather than from fixed libraries or dynamic traces.

The conclusion of Section XII now states precisely: among existing work, no prior system combines goal‑independent functional specification generation with path‑sensitive symbolic execution as the semantic driver for off‑the‑shelf C programs, the niche that SESpec occupies. 


> Soundness/strength claims are currently too strong...

We agree and have addressed this at two levels. For soundness/completeness, Section III adds Definition 1 and Proposition 1, which formalize the notion of strongest postcondition and prove the strongest postcondition guarantee for loop-free fragments under explicit assumptions; Section X now states that outside this fragment the result is a sound over-approximation, not a strongest guarantee. For strength, the new added Section VIII-C distinguishes validity from strength and adds a both-valid pairwise judge and an implication-check cross-check. We refer the reviewer to Item (1) and our response to AE Comment 6 for additional detail.

> Evaluation methodology needs clearer normalization and rigor. - Define Pass@k unambiguously... Model choice... Failure breakdown.

We refer the reviewer to our response to AE Comment 2 and Item (2) of the major revisions overview, where we have addressed this concern in full. In summary: First, Pass@k is now unambiguously defined in Section VII‑C as the number of complete generation attempts, with refinement iterations explicitly excluded from the count. Second, model choice is justified in Section VII and Section VIII-A, with Section VII additionally including Claude 3.7 Sonnet as a representative strong code-capable LLM. Third, failure classification is added in Section VIII‑E, with Fig. 6 and Table VIII breaking down non-valid cases by root cause and prover outcome.
