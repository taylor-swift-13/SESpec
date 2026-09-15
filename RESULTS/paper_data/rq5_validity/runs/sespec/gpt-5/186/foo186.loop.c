
/*@
  // Count occurrences of a given value v in a half-open slice [lo, hi)
  logic integer count_eq_slice(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq_slice(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo186(int size, int * a, int a_len) {

    if (size == 0) {
        return 0;
    }

    int f = a[0];
    int total = 1;

    /*@
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop invariant \forall integer k; 0 <= k < c ==> f <= a[k];
      loop invariant \exists integer k; 0 <= k < c && a[k] == f;
      loop invariant total >= 1;
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns c, f, total;
    */
    for (int c = 1; c < size; c++) {
        if (f > a[c]) {
            f = a[c];
            total = 1;
        } else if (f == a[c]) {
            total++;
        }
    }

    return total;
}
