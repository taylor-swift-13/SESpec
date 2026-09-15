
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires size >= 0;
  requires \valid(a + (0..a_len-1));
  requires a_len >= size;
  ensures \result >= 1;
  ensures \forall integer k; 0 <= k < size ==> a[k] >= \result;
  ensures \exists integer k; 0 <= k < size && a[k] == \result;
  ensures count_eq(a, 0, size, \result) == \result;
*/
int foo188(int size, int * a, int a_len) {

    if (size == 0) {
        return 0;
    }

    int f = a[0];
    int max = 1;

    /*@
      loop invariant 1 <= c <= size;
      loop invariant \forall integer k; 0 <= k < c ==> a[k] >= f;
      loop invariant \exists integer k; 0 <= k < c && a[k] == f;
      loop invariant \forall integer k; 0 <= k < size ==> \at(a[k], Pre) == a[k];
      loop assigns c, f, max;
    */
    for (int c = 1; c < size; c++) {
        if (f > a[c]) {
            f = a[c];
            max = 1;
        } else if (f == a[c]) {
            max++;
        }
    }

    return max;
}
