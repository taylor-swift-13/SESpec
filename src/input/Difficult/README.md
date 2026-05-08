# Difficult Bench

Representative hard SESpec cases collected from existing inputs.

| Case | Source | Main difficulty |
| --- | --- | --- |
| `1.c` | `loop/foo70.c` | Nondeterministic loop, branch-sensitive parity invariant |
| `2.c` | `loop/foo65.c` | Nested nondeterministic loops with relational parity invariant |
| `3.c` | `sv-comp_autospec/0011.c` | Sequential loops; later assertion depends on earlier loop exit facts |
| `4.c` | `sv-comp_autospec/0013.c` | Nested loops and arithmetic bound propagation |
| `5.c` | `NLA_lipus/19.c` | Nonlinear polynomial invariant over fifth powers |
| `6.c` | `LIG-MM/1.c` | Linked-list traversal with ACSL assertions and preserved inputs |
| `7.c` | `LIG-MM/23.c` | Linked-list traversal after helper call; predicate/contract reuse needed |
| `8.c` | `FormalBench/10.c` | Array permutation-like update with data-dependent swap |
| `9.c` | `SpecGenBench/44.c` | Array-indexed loop stride and path-dependent bound |
| `10.c` | `SV_COMP/28.c` | Multi-helper array merge sort, malloc, recursive helper |
| `11.c` | `SV_COMP/36.c` | Recursive numeric helper contract synthesis |
| `12.c` | `frama-c-hard/2.c` | Recursive GCD helper and caller assertion |
| `13.c` | `c_flat/SVCOMP_0093__SVCOMP__MergeSortIterative__MergeSortIterative.c` | Multi-helper iterative merge sort with array segments |
| `14.c` | `c_flat/SVCOMP_0205__SVCOMP__const1__const1.c` | Constant propagation with many assertion obligations |
| `15.c` | `c_flat/FormalBench_0008__FormalBenchHF__base__programs__MaxProduct.c` | Nested array scan with product/max relation |
| `16.c` | `c_flat/FormalBench_0013__FormalBenchHF__base__programs__FirstMissingPositive.c` | Array mutation with index/value constraints |
| `17.c` | `c_flat/SpecGenBench_0331__SpecGenBench__common__MoveZeroes__MoveZeroes.c` | Array compaction with write/read index relation |
| `18.c` | `c_flat/SpecGenBench_0296__SpecGenBench__common__DominantIndex__DominantIndex.c` | Max-index scan with relational numeric invariants |
| `19.c` | `c_flat/SpecGenBench_0298__SpecGenBench__common__Fibonacci__Fibonacci.c` | Array recurrence over sequential loop state |
| `20.c` | `c_flat/SVCOMP_0091__SVCOMP__InsertionSort__InsertionSort.c` | Insertion sort with nested array loops |
| `21.c` | `c_flat/SVCOMP_0152__SVCOMP__StringStartEnd02__StringStartEnd02.c` | String-like pointer/array traversal helper |
| `22.c` | `c_flat/SVCOMP_0248__SVCOMP__multinewarray__multinewarray.c` | Multidimensional array initialization and assertions |
| `23.c` | `c_flat/SVCOMP_0200__SVCOMP__cast1__cast1.c` | Cast-heavy assertion obligations |
| `24.c` | `c_flat/SVCOMP_0226__SVCOMP__fcmpx_dcmpx1__fcmpx_dcmpx1.c` | Floating comparison assertion obligations |
| `25.c` | `c_flat/FormalBench_0039__FormalBenchHF__base__programs__Sum.c` | Array summation with loop accumulator relation |
| `26.c` | `c_flat/FormalBench_0115__FormalBenchHF__base__programs__GetInvCount.c` | Nested inversion-count array loops |
