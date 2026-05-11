// Pattern: in-place array permutation / partition where the loop body
// swaps two positions guarded by a data-dependent test. The right
// invariant is usually a SET-LEVEL claim ("multiset of array contents is
// preserved") combined with a per-element bound (`0 <= a[k] < n`).

/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(a + (0..n-1));
  requires n >= 0;
  requires \forall integer i; 0 <= i < n ==> 0 <= a[i] < n;
  ensures \forall integer i; 0 <= i < n ==> 0 <= a[i] < n;
  ensures \forall integer v; 0 <= v < n ==>
            count_eq(a, 0, n, v) == \at(count_eq(a, 0, n, v), Pre);
  assigns a[0..n-1];
*/
void cycle_sort(int* a, int n) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < n ==> 0 <= a[k] < n;
      loop invariant \forall integer v; 0 <= v < n ==>
                       count_eq(a, 0, n, v) == \at(count_eq(a, 0, n, v), Pre);
      loop assigns i, a[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        if (a[i] == i) {
            i++;
        } else {
            // swap a[i] and a[a[i]]
            int j = a[i];
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
}
