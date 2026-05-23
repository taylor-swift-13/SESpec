
/*@
  logic integer prefix_sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : prefix_sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@ requires ... ; assigns \nothing; ensures ... ; ... */
int foo194(...) { ... }
