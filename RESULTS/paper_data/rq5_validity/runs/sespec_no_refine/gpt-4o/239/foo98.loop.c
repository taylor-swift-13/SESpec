
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(ar + (0..ar_len-1));
  requires ar_len >= n;
  requires n >= 0;
  ensures \forall integer k; 1 <= k <= n ==> count_eq(ar, 0, n, k) <= 1;
  ensures \result >= 1 && \result <= n;
  assigns \nothing;
*/
int foo98(int * ar, int ar_len, int n) {

    int missing = 1;
    if (n == 0 || n == 1) {
        return missing;
    }

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant 1 <= missing <= n;
                       (ar[k - 1] == k ==> missing == k);
      loop invariant \forall integer k; 1 <= k < i ==> 
                       (ar[k - 1] != k ==> missing != k);
      loop assigns i, missing;
    */
    for (int i = 1; i <= n; i++) {
        if (ar[i - 1] == i) {
            missing = i;
        } else if (ar[i - 1] != i) {
            return i;
        }
    }

    return missing;
}
