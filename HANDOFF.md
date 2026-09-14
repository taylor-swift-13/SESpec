# Session Handoff

Last updated: 2026-07-13 (Asia/Shanghai)

## Current objective and status

This session produced and repeatedly refined a bilingual slide deck comparing QCP with Frama-C/WP on concrete C-verification examples. The current deliverables are complete and compile successfully. The deck emphasizes concrete specifications, generated proof goals, and measured proof-engineering cost rather than broad feature tables.

## Deliverables

- `slides/qcp_vs_framac.tex`: English Beamer source.
- `slides/qcp_vs_framac.pdf`: compiled English deck.
- `slides/qcp_vs_framac_zh.tex`: Chinese `ctexbeamer` source.
- `slides/qcp_vs_framac_zh.pdf`: compiled Chinese deck.
- Both versions currently contain 18 pages and should remain structurally aligned.

## Current slide structure

1. Title.
2. Bottom line / appropriate use cases of the two tools.
3. Pipeline comparison.
4. QCP's direct use of Rocq definitions and libraries.
5. A simple higher-order example: the real LiteOS `LOS_ListEmpty` function and its generic linked-list contract.
6. HumanEval p044 `change_base`: core C implementation.
7. p044: QCP specification versus a faithful ACSL specification using `\sum` and `\lambda`.
8. p044: the specialized recursive `horner` predicate and loop invariant.
9. p044: the three auxiliary assertions and the resulting 44/44 proof result.
10. Memory specification language versus local WP support.
11. p025 allocation contracts.
12. p025 spatial conjunction, partially initialized arrays, and the consequence of ignored `\fresh` clauses.
13. Interactive-proof comparison using excerpts of actual QCP and Frama-C/Why3 generated goals.
14. Size and shape of the exported Frama-C Coq artifact.
15. p076: SMT result and completion with Coq.
16. Sorting: QCP `Permutation` versus ACSL occurrence-count specification.
17. Sorting: why 15 local assertions were needed around the swap.
18. Takeaways.

The following slides/examples were explicitly removed at the user's request and should not be restored without asking:

- Evidence and Reproduction Paths.
- HumanEval p051 `remove_vowels`.
- The Expressiveness Gap Is More Than One Lambda.
- Summary of Local HumanEval Comparisons.
- Engineering Guidance / 工程选择建议.
- The original continuation-based mergesort example.
- Displays of QCP proof tactics such as `pre_process`, `sep_apply`, `rewrite`, and `entailer`.

## Important corrections and presentation decisions

### Generated goal versus source contract

An earlier version incorrectly presented a QCP `Ensure` clause as a generated Rocq goal. This was corrected. Slide 13 now uses a readable excerpt of the actual generated theorem `sortArray_return_wit_1` from:

`/home/yangfp/QualifiedCProgramming/SeparationLogic/examples/QCP_demos_human/sortArray_goal.v`

Its essential shape is:

```text
(returnSize_pre # Int |-> numsSize_pre) **
IntArray.seg nums_pre 0 i l0 **
IntArray.seg nums_pre i numsSize_pre l2
|-- EX l1,
    [| Permutation l l1 /\
       increasing l1 /\
       Zlength l1 = numsSize_pre |] &&
    IntArray.full nums_pre numsSize_pre l1 **
    (returnSize_pre # Int |-> numsSize_pre).
```

The slide explicitly says that quantified variables and hypotheses are omitted. Do not relabel this as the original C contract.

The Frama-C side uses a small normalized excerpt of the actual Why3-generated Coq file:

`/home/yangfp/CAV/Frama-C/sort/wp-session/interactive/lemma_occ_frame.v`

The excerpt contains translation-layer objects such as `addr`, `shift`, `havoc`, `valid_rw`, and `wp_goal`. The full file is 630 lines and declares 84 axioms before the proof goal. The current accessible wording is:

> Only a small excerpt is shown. The full generated Coq file is 630 lines long and introduces 84 axioms for memory and C operations before the proof goal.

### p044 `change_base`

Evidence files:

- `/home/yangfp/CAV/Frama-C/p044/change_base_faithful.c`
- `/home/yangfp/CAV/Frama-C/p044/change_base_mono.c`
- `/home/yangfp/CAV/Frama-C/README.md`

Recorded results:

- Faithful higher-order ACSL version: 26/30 with Frama-C 27.1; the lambda-bearing form is the relevant obstacle in this local experiment.
- Specialized recursive `horner` version plus Coq: 44/44.
- The specialized version uses three assertions and four Coq proofs.

Semantic explanations used in the slides:

- `fold_left (fun acc c => acc * base + (c - 48)) output 0 = x` means: scan the output digits from left to right, append each digit to the accumulated base-`base` number, and reconstruct the original input `x`.
- `horner(a, n, b)` interprets the `n` consecutive characters beginning at address `a` as a base-`b` integer. Thus `horner(out + digits, ...)` refers to a suffix of the original output buffer, even though it is the first `n` characters relative to the shifted pointer.
- `val_inv` states that the original input equals the value already represented by the written suffix plus the remaining quotient scaled by the appropriate power of the base.
- `bpow_step` unfolds one power of the base.
- `msd_step` decomposes the first digit of a Horner expression.
- `val_step` combines arithmetic facts to establish preservation of the loop invariant.

Every displayed ACSL annotation should retain a nearby natural-language explanation.

### p025 allocation and memory

Evidence files:

- QCP: `/home/yangfp/QualifiedCProgramming/QCP_examples/humaneval/IntArrayClaude/C_25.c`
- Frama-C: `/home/yangfp/CAV/Frama-C/p025/factorize.c`

Terminology:

- `IntArray` is the C structure type; `IntArray::...` names predicates or definitions in QCP's `IntArray` namespace/module.
- `data_at` describes an initialized memory cell.
- `undef_data_at` describes allocated but not yet initialized storage.
- `IntArray::seg(data, 0, size, factors)` describes an initialized prefix whose values are `factors`.
- `IntArray::undef_seg(data, size, n0)` describes the remaining uninitialized suffix.
- Separating conjunction records disjoint ownership, which enables the separation-logic frame rule to preserve untouched memory implicitly.

Claim boundary: ACSL provides `\valid`, `\fresh`, and `\separated`; do not claim globally that Frama-C cannot reason about `malloc`. The precise local observation is that the tested WP version reports allocation/initialization/danglingness clauses as unsupported and ignores `\fresh`. The recorded p025 results are 41/57 and 44/61 for the two relevant runs.

When `\fresh` is ignored, the missing fact is separation between the allocated `data` array and the entire `out` structure. `out->size` is used as the clearest well-typed aliasing counterexample because both it and an array element have type `int`; the issue is not limited to the `size` field.

### Other measured examples

- p076: SMT proves 19/23 goals; the WP -> Why3 -> Coq path reaches 23/23.
- Selection sort source: `/home/yangfp/CAV/Frama-C/sort/sort.c`.
- Sort result: 53/53 goals, distributed as Qed 22, Alt-Ergo 23, Z3 4, and Coq 4.
- The sort example uses 15 assertions after a swap to expose unchanged regions, swapped cells, segment decompositions, an index fact, and the final whole-array swap relation.
- QCP sort contract: `/home/yangfp/QualifiedCProgramming/QCP_examples/QCP_demos_human/sortArray.c`.

## Higher-order linked-list example

The deck uses the actual LiteOS function:

```c
static inline int LOS_ListEmpty(LOS_DL_LIST *node)
```

Its QCP contract quantifies a value type `{A}`, a representation predicate `storeA : Z -> A -> Assertion`, and a logical list `l`, using `store_dll`. It replaced the harder continuation/monadic mergesort example. Source:

`/home/yangfp/QualifiedCProgramming/QCP_examples/Applications_human/LiteOS/GetSortLinkNextExpireTime.c`

Relevant region is approximately lines 123--140. Preserve the real function name and signature whenever the contract is shown.

## Build and verification

From `/home/yangfp/SESpec/slides`:

```bash
pdflatex -interaction=nonstopmode -halt-on-error qcp_vs_framac.tex
pdflatex -interaction=nonstopmode -halt-on-error qcp_vs_framac.tex
lualatex -interaction=nonstopmode -halt-on-error qcp_vs_framac_zh.tex
lualatex -interaction=nonstopmode -halt-on-error qcp_vs_framac_zh.tex
```

Both sources compiled successfully with two passes at the end of the session. For visual inspection of a specific PDF page, Ghostscript was used, for example:

```bash
gs -q -dSAFER -dBATCH -dNOPAUSE \
  -dFirstPage=13 -dLastPage=13 \
  -sDEVICE=png16m -r115 \
  -sOutputFile=/tmp/qcp-slide-13.png \
  qcp_vs_framac.pdf
```

Slide 13 contains two code excerpts and therefore uses small text; it was visually inspected and remained readable, but it is the first page to recheck after layout changes.

## User preferences established in this session

- Prefer concrete examples over abstract capability tables.
- Put a plain-language explanation beside every displayed ACSL annotation.
- Include the actual function name and signature with a contract.
- Show proof goals, not proof tactics.
- Use simpler higher-order examples; avoid continuation/monad machinery unless essential.
- Keep the English and Chinese decks synchronized.
- Do not delete unrelated slide content while making a requested local edit.
- Use precise, evidence-backed wording and avoid broad claims about Frama-C.
- Keep explanations accessible enough for a presentation audience that may not know Gallina, separation logic, or ACSL internals.

## Repository state and continuation notes

The repository already had a very large dirty working tree containing many modified, deleted, and untracked files unrelated to this slide task. No attempt was made to clean, reset, or otherwise alter those changes. The `slides/` directory is currently untracked according to `git status`; treat all existing changes as user-owned.

For the next session:

1. Read this file and inspect both TeX sources before editing.
2. Make the same semantic change in English and Chinese unless the user explicitly requests only one version.
3. Rebuild both PDFs with the engines above.
4. Recheck page count and visually inspect any dense page that changed.
5. Validate quantitative claims against the source files listed here rather than relying only on slide text.
