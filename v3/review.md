Dear Mr. Yang:

The reviews of your manuscript, Integrating Symbolic Execution with LLMs for Automated Generation of Program Specifications  TSE-2026-02-0150, have been received and are attached below. The reviewers and Editors felt that a number of major issues needed to be addressed in your paper before it would be acceptable for publication. Thus, we will not be able to consider it further for publication in its current form.  

However, because we believe the work has merit, we invite you to consider submitting a thoroughly reworked manuscript that takes all the reviewers' and Editors' comments into consideration. It would be given a new Manuscript ID and be fully reviewed again.

You may resubmit your paper, but it will be treated as a NEW submission and given a new log number.  If you choose to resubmit your paper please refer to this original log number (TSE-2026-02-0150), and we will include your previous manuscript's history in it's files and forward the necessary information to the Editor-in-Chief and Associate Editor.  The manuscript will then undergo a new review process.
 
In addition to preparing the revised version of your manuscript, you must include a point-by-point response to each of the reviewers' comments.
Please ensure that there is an unmarked version of your manuscript uploaded as the main file. You may also include a version with highlighted changes as an additional file.
Once you have submitted your files, you will receive a confirmation email and the new manuscript ID
We hope that you will find the comments from the reviewers to be useful in your future work.  If you have any questions, please feel free to contact us. 

Sincerely,

Dr. Mauro Pezzè, EIC
Transactions on Software Engineering
tse-eic@usi.ch, mauro.pezze@unimib.it
=======================================

AE Comments: 
Associate Editor
Comments to the Author:
Thank you for submitting to TSE.

The reviewers acknowledged that the paper is novel and useful, but they also identified several key issues:

1. The novelty relative to prior work is not sharply delineated.
2. The methodology needs tighter normalization and clearer definitions.
3. The evaluation results are limited in scope and complexity, and it is unclear whether the approach can scale to realistic, large-scale benchmarks.
4. The benchmark selection is not representative and is overly small.
5. Runtime, memory usage, and AI token consumption are lacking.
6. There is a potential absence of analysis on soundness and completeness.
7. There is a potential absence of discussion on runtime overhead.

We hope you find the reviews useful in further improving the quality of the paper.
Reviewer Comments
Reviewer: 1

Public Comments (these will be made available to the author)
The paper is highly professionally written and is innovative in an area of growth for software engineering.

It makes strong technical contributions and seeks to expand its scope of applicability. The attempt to validate the results through experiments is commendable.

However, the results appear quite limited in scope and complexity. The benchmarks selected appear carefully curated and are small in number. For example, the SV-COMP benchmarks contain over 14000 benchmarks, yet only 21 are included here, and the average Line of Code length is 22 (in other words, extremely small, whereas SV-COMP benchmarks include examples with 100,000s of lines of code). Their relevance is overstated: e.g., the Sun Search example from the aerospace domain is simplistic (not complex as stated), extremely small, and lacks any relevant characteristics of the aerospace domain.
The approach's performance in terms of runtime, memory use, and AI tokens used is lacking.
Thus, the work reported appears preliminary, and it appears to lack universal relevance. It is unclear if it is possible to upscale the work on realistic benchmarks with truly complex and varied data structures, running on hundreds of thousands of lines of code, with complex Control Flow and external library calls.

Thus, while the work is commendable, its publication in TSE appears premature due to the absence of a demonstration of the technique on relevant and realistic benchmarks.

Reviewer: 2

Public Comments (these will be made available to the author)
# Summary
This paper proposes SESpec, a novel framework that integrates symbolic execution, LLMs, and formal verification to automatically generate precise program specifications, including preconditions, postconditions, and loop invariants. The framework utilizes symbolic execution to derive exact semantic information and guide LLMs through template-based invariant generation, thereby reducing hallucinations and improving correctness. The framework also employs an iterative, verification-driven refinement mechanism to ensure validity and strength of the generated specifications. Extensive experiments demonstrate its performance advantage over existing approaches in terms of numerical programs and complex control flows.

# Strength
+ Novel integration of symbolic execution and LLMs
+ Well-designed invariant template for prompting based on strict formalism
+ Comprehensive experimental design and analysis
+ Clear and easy-to-follow presentation

# Weakness
+ Potential concerns on scalability
+ Potential absence of analysis on soundness and completeness
+ Potential absence of discussions on runtime overhead

# Comments
+ Generally, the paper presents a compelling and well-structured approach to automated program specification generation by tightly integrating symbolic execution with LLMs. The overall design is technically sound and clearly motivated, with the symbolic execution component providing precise semantic grounding that effectively complements the reasoning capabilities of LLMs. In particular, the invariant templates derived from strict formal semantics, are rigorous yet practical. The experimental evaluation is generally comprehensive, covering diverse benchmarks and including ablation and comparative studies. The paper is also well-written and easy to follow, with clear explanations of each component and their interactions. Nevertheless, certain limitations remain in this work, which may undermine the significance of its contributions.
+ The main limitation lies in the scalability of the approach. Since the framework heavily relies on symbolic execution to extract semantic information and guide invariant generation, it may inherit the well-known limitations of symbolic execution, such as path explosion on large or complex programs. While the current evaluation demonstrates strong results on benchmarks with moderate-scale programs, it remains unclear how the method would perform when applied to larger real-world systems with deep control flow and extensive interprocedural interactions.
+ Another limitation is the lack of explicit analysis regarding the soundness and completeness of the approach or its components. Although the generated specifications are validated through a formal verifier, the involvement of LLMs in invariant synthesis and refinement introduces uncertainty that is not formally characterized. In particular, it is claimed in section III.A that the symbolic execution procedure can produce the strongest postconditions of a function. It would be better to provide relevant soundness/completeness analysis on the symbolic execution procedure so that the claim can be rigorously supported.
+ Concerning the baseline approaches involved for comparison, some recent LLM-based approaches, such as Clause2Inv proposed by Cao et al. (ISSTA 2025), claim that they can achieve near-perfect performance on datasets including SyGuS, OOPSLA, and SV-COMP. It would be better to include these approaches into comparison to better highlight the advantages of the proposed framework. Also, despite the language gap between the proposed work and SpecGen, it is still possible to establish mutual translations between Java/JML and C/ACSL for the established benchmark to achieve comparison, given that most programs included are simplistic, without involving complex features specific to the C programming language.
+ Finally, the paper does not provide sufficient discussion on the runtime overhead of the proposed framework. The integration of symbolic execution, iterative LLM interactions, and repeated calls to a formal verifier suggests that the approach may incur non-trivial computational costs, in terms of both execution time and model tokens consumed. A more thorough evaluation of runtime performance would help assess the practical applicability of the approach in real-world development or verification pipelines.

# Questions

1. Could the authors provide more descriptions on the "Layer 2 - Adaptive Refinement" mentioned in section IV.D? Is this process implemented by prompting the LLM only?
2. Could the authors provide analysis for one representative case where SESpec fails (e.g., nested loops or complex data-flow dependencies)?

Reviewer: 3

Public Comments (these will be made available to the author)


SESpec proposes a specification-synthesis pipeline that couples path-sensitive symbolic execution (QCP), LLM-guided conjecture, and deductive verification (Frama-C/WP with ACSL) to synthesize loop invariants, preconditions, and postconditions for C programs. The key idea is to exploit symbolic states as semantic "scaffolding": for loop-free regions, SESpec computes postconditions from symbolic execution; for loops, it derives equality-constraint skeletons that constrain the LLM's search space toward invariants consistent with the symbolic memory model. A four-stage refinement loop (syntax repair → adaptive refinement → regeneration → elimination) iteratively steers candidates toward verification.

The paper has a useful systems contribution—symbolic-state-derived ACSL skeleton templates are a pragmatic mechanism to stabilize LLM output—and the empirical results on inductive structures and masked goals are compelling. The division of labor is also well-motivated: symbolic execution supplies precise path conditions and aliasing information (within its model) while the LLM supplies higher-level invariant "shapes" and inductive predicates that symbolic methods typically struggle to guess. The new pIp and list-S suites appear to fill a real gap in existing LLM-based spec synthesis evaluations.

That said, the current presentation overstates the guarantees, and the novelty relative to the closest prior work is not delineated sharply enough. The experimental methodology also needs tighter normalization and clearer definitions.

**Novelty relative to prior art is underspecified**.
The paper frames the comparison primarily against AutoSpec and ACInv, but the conceptual overlap deserves a more surgical discussion.
- Against ACInv. ACInv already extracts loop/data-structure information via static analysis and injects it into prompts. The paper should isolate what path-sensitive symbolic state adds beyond ACInv's abstraction. Concretely: where does ACInv's information become too weak or too imprecise (e.g., must-alias vs may-alias distinctions, correlations across fields, path-dependent equalities) and how does SESpec's symbolic-state snapshot resolve it? A small side-by-side case study—one loop where ACInv fails due to loss of relational equalities but SESpec succeeds due to a specific equality skeleton mined from symbolic states—would substantiate the claimed conceptual advance.
- Against Preguss. Preguss is dismissed as goal-directed for RTE, but it also does compositional precondition synthesis. If SESpec's claim is broader (functional specs beyond safety), then either (i) demonstrate an empirical gap with at least a small reproduced comparison, or (ii) state clearly why Preguss's objective/setting makes it incommensurate. Right now the comparison is rhetorical rather than evidential.
- Against template-based invariant mining (Daikon, CLN2INV-style). The equality-constraint templates have an obvious lineage: classic invariant mining uses fixed template libraries, and recent neural-template approaches instantiate restricted forms. SESpec's novelty seems to be that templates are derived from path-complete symbolic states rather than from a static library or dynamic traces. That argument should be made explicitly, including what classes of relations become available due to symbolic-state extraction and why that is essential for C programs with pointers/structs.

A compact "positioning" subsection (or a table) would help. In §IX, I would recommend itemizing prior tools (Daikon, AutoSpec, ACInv, Preguss, SpecGen, LIG-MM/LiPuS, etc.) along clear axes: goal dependence, inductive data support, template source (fixed vs mined, dynamic vs symbolic), aliasing/memory model, refinement strategy, and target language.
This would turn the novelty claim from "we integrate symbolic execution" into a crisp technical delta.


**Soundness/strength claims are currently too strong**.
The paper repeatedly uses "strongest" and "formally verified" in ways that exceed what is actually guaranteed.
- "Strongest postcondition" (§III-A). The SP claim holds only under strong assumptions: symbolic execution must be path-complete and semantics-precise for the relevant C features (heap, structs, arrays, possibly unbounded loops approximated by bounding, etc.). The paper itself acknowledges a fallback to LLM-generated over-approximations under path explosion. Once widening, bounding, or fallback occurs, "strongest" is no longer accurate. The paper should narrow the statement to something like: "When QCP enumerates all feasible paths for the fragment under the chosen symbolic memory model and without approximation, the computed postcondition is strongest within that model; otherwise we compute a best-effort over-approximation."
- "Formally verified." What is defensible is: candidates accepted by Frama-C/WP are proved valid within WP's logic, memory model, and solver assumptions, subject to timeouts and SMT soundness. This should be stated precisely. In particular, WP's Typed model is known to be unsound under certain C idioms (pointer casts, unions, type punning, overlapping accesses). If pIp includes such patterns, the paper should either (i) exclude them explicitly, (ii) justify that they do not occur, or (iii) evaluate under a model that addresses them. Otherwise, "formally verified" reads as stronger than warranted.

**Evaluation methodology needs clearer normalization and rigor**.
Several aspects of the evaluation currently undercut the strength of the empirical claims.
- Define Pass@k unambiguously. The text appears to conflate "k independent samples" with "k refinement iterations." If Pass@1 allows up to three internal refinement rounds, then it is not comparable to a single-shot Pass@1 baseline unless you normalize by total LLM queries/tokens and (ideally) verification calls. Please report success as a function of budget: e.g., success vs. number of LLM calls, vs. tokens, and vs. wall-clock.
- Model choice. If the paper aims to claim robustness rather than being a snapshot of one model, it would help to include at least one more recent model (or a brief sensitivity study). Otherwise the reader cannot tell whether the gain is due to SESpec's structural constraints or to model idiosyncrasies.
- Failure breakdown. The 41 unsolved programs are an opportunity: categorize failures into (i) symbolic execution explosion/incompleteness, (ii) syntactic ACSL issues, (iii) semantically too-weak invariants, (iv) SMT/WP timeouts, (v) memory-model mismatch. This will clarify where SESpec needs engineering vs. where the approach fundamentally struggles.