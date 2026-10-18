TSE-2026-07-0653 - Decision (Major Revision Required) 

TSE-2026-07-0653, "Integrating symbolic execution with LLMs for automated generation of C program specifications"

10-Sep-2026

Dear Mr. Yang:

The review process of your manuscript Integrating symbolic execution with LLMs for automated generation of C program specifications has been completed. Based on the peer review process for your submission, your manuscript requires a major revision. We invite you to respond to the reviewers' comments, included at the bottom of this letter, and revise your manuscript accordingly.

1. To revise your manuscript, you may click here https://ieee.atyponrex.com/submission/submissionBoard/REX-PROD-2-A5BA0F61-DF64-4C9F-8BB4-873166487427-E662A6D8-CFA4-4070-87EB-B782A9C24477-01711/current?idtype=external

2. In addition to preparing the revised version of your manuscript, you must include a point-by-point response to each of the reviewers' comments in the designated area. You may also include these responses in an attached file with your revised manuscript.

3. Please upload an unmarked version of your manuscript as the main file. You may also include a version with highlighted changes or annotated text as an additional file.

Please note, some reviewers may have recommended that you discuss additional literature when revising your manuscript. If you feel that the recommended literature does not contribute to the scholarly content of the article or is otherwise irrelevant, please note your concerns in your response to reviewer feedback.

When reviewing the paper please be aware that there is a Mandatory Overlength Page Charges (MOPC) for papers exceeding 12 pages (14 pages for regular papers that extend previous conference papers).  The  MOPC does not apply to survey papers, appendices and supplementary material.  You may consider revising your paper by presenting the core contribution in 12 pages, and sharing useful details with the readers in the appendices and supplementary material, to both make incentive reader who may appreciate reading the essential contribution in 12 pages first, and move on with important details later, and avoid MOPC.

Once you have submitted your files, you will receive a confirmation email and an updated manuscript ID. In order to facilitate the timely publication of manuscripts submitted to Transactions on Software Engineering, please submit your revised manuscript by 09-Dec-2026 .

Your kind cooperation is greatly appreciated.

Sincerely yours,

Dr. Tao Yue, EIC
Transactions on Software Engineering
taoyue@gmail.com
**************************************************************
AE Comments: 
Associate Editor
Comments to the Author:
Thank you for your resubmission.
Reviewer 1 identified a list of issues that are go beyond a minor revision. Please take this opportunity to carefully address these issues.
Also, please kindly prepare a response letter for the next revision.
Reviewer Comments
Reviewer: 1

Public Comments (these will be made available to the author)
The authors have addressed all my previous questions. I've no other quetions.

Reviewer: 2

Public Comments (these will be made available to the author)
This revision introduces SESPEC, a framework that combines symbolic execution, LLM-based synthesis, and Frama-C/WP verification to automatically generate C specifications (preconditions, postconditions, loop invariants). It's a clear improvement over the earlier version. The assumptions behind the strongest-postcondition result are now spelled out, the goal-independent evaluation has been substantially expanded via SESPEC-400, and there are new ablation, cost, strength, and failure-mode analyses, plus more detailed case studies and prompt templates.

I think the underlying problem is important, and the combination of path-sensitive symbolic information, structured LLM synthesis, and verifier-guided refinement is a technically interesting idea. The experimental coverage is also broader than is typical in this space—numerical programs, pointers/structs, linked lists, and a separate goal-independent benchmark. The added discussion of limitations and threats to validity is welcome. Overall, I'm positive on the paper, but a few things still need attention before it's ready, mainly around how generated preconditions are interpreted and how specification strength is compared.

1. Drop the "weakest/minimal precondition" language. Section III-B argues that validity, pairwise separation, and finite bounds together form a minimal precondition, and that anything weaker would break symbolic execution. But pairwise separation rules out perfectly legitimate executions where aliasing is allowed, and the finite value/length bounds are really an artifact of the chosen symbolic model rather than something semantically required by the C program. The TripleAbsMax example makes this pretty clear — \separated(pIp, pIp->ret) gets imposed as a precondition before the "path-complete" postcondition is even derived. I'd suggest something like "sufficient precondition for the supported symbolic-execution model" instead of "weakest/minimal," and it would help to say explicitly what behaviors the no-alias assumption excludes. That alone would sharpen the scope of the strongest-postcondition claim considerably.

2. RQ6's strength methodology needs a more careful treatment of preconditions, and there's a possible position bias to address. The appendix tells the LLM judge to "heavily favor" postconditions and loop invariants over preconditions, with SESPEC always shown as specification B. But preconditions are part of what makes a contract strong — a specification with stronger postconditions over a much narrower input domain isn't automatically the stronger contract, and this matters here because SESPEC itself is generating the validity/separation/bound assumptions. I'd rather see strength defined through something closer to an assumption/guarantee or contract-refinement criterion that weighs requires and ensures together. It would also help to swap the A/B order and check whether the conclusions hold up, and to state plainly which model and inference settings the judge used. The WP implication experiment is a nice piece of supporting evidence, but with a definite ordering on only 51 of 242 pairs for gpt-5.4-mini, it can't carry this argument on its own.

3. The strongest-postcondition proposition is better, but the notation is still a bit loose. The added scope and path-completeness assumptions help. That said, expressions like (PC_\pi \land \sigma_{end,\pi}) treat \sigma — previously introduced as a symbolic-store mapping — as if it were a logical formula, and the proof then reasons about it as a relation between initial and final states. It would be worth spelling out how a symbolic store is encoded as equalities over pre-/post-state variables, and what's assumed about undefined behavior and the memory model. This is mostly a presentation issue, but fixing it would make Proposition 1 much easier to check and reuse.

4. SESPEC-400 needs more on how it was built and whether semantics were preserved. The paper says 250 FormalBench and 59 SpecGenBench Java programs were translated to C, preserving control flow and data dependencies. Given that the comparison against SPECGEN crosses the Java/JML and C/ACSL worlds, this translation step is doing a lot of methodological work. Could you say more — in the paper or supplementary material — about how Java integer semantics, arrays, references, exceptions, etc. were mapped, whether any programs were altered or dropped, and how you checked that the translated versions were semantically equivalent? A translation script would go a long way here.

5. The cost and baseline comparisons should separate "effectiveness" from "same budget." Table V reports SESPEC at Pass@5 against baselines run at their best reported configurations, which is fine for an effectiveness comparison but isn't really compute-normalizedone —worth saying so explicitly, along with the generation/sample budgets of the competing methods where known. Also, Fig. 5's "average cost per valid run" conditions on success, which can hide the real cost of methods that fail more often. Average cost per attempted program, or ideally expected cost per successfully obtained specification, would give a cleaner picture.

6. The RQ8 conclusion overreaches slightly. The logs do show timeouts dominating the observed prover failures, mostly from loop-invariant obligations. But the paper notes it's still unclear whether some remaining failures come from specification errors versus verifier/modeling limits. So saying the bottleneck is the verifier "rather than specification synthesis" is too strong a claim. Something like "residual failures manifest predominantly as solver timeouts under the current backend" would be more accurate, while acknowledging the experiment doesn't fully separate hard-but-correct specifications from synthesis errors that happen to produce hard proof obligations.

7. The industrial case study needs a quality measure beyond VC discharge rate. 601/625 discharged VCs is a nice number, but the paper also mentions that the accepted spec for mat_mul collapses to ensures \true. A high discharge rate doesn't tell you much about functional coverage in that case. It would help to report how many of the 14 functions end up with non-vacuous functional postconditions, how many get only safety/frame properties, and which ones are effectively left unsummarized—that would make the industrial result much more meaningful.

8. Consider dropping the "OOPSLA" benchmark suite from the evaluation. The OOPSLA dataset largely overlaps with programs that later collections such as Code2Inv already absorbed and extended, so including it separately doesn't add much independent signal and risks double-counting similar instances across benchmarks. I'd suggest either removing it from the reported benchmark set or, if the authors want to keep it for continuity with prior work, explicitly noting the overlap with Code2Inv (and any other benchmarks derived from it) and clarifying what OOPSLA contributes beyond what's already covered.

None of this undermines the core idea. The revision does a good job clarifying SESPEC's scope and separating exact symbolic summaries from verifier-checked best-effort synthesis, and it's appropriately upfront that verifier acceptance doesn't imply semantic completeness. The added experiments and case studies make the empirical case noticeably stronger.

A few small things to fix along the way: a typo ("AUTOSPECserves"), some spacing issues, and language around "exact," "minimal," "stronger," and "dominant bottleneck" that's a bit stronger than the evidence supports. Also, pick one term—"goal-independent" or "goal-free"—and stick with it.