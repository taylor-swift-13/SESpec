
/*@
  logic integer min_value(int* a, integer lo, integer hi) =
    lo >= hi ? Integer.MAX_VALUE
             : (a[hi - 1] < min_value(a, lo, hi - 1) ? a[hi - 1] : min_value(a, lo, hi - 1));
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires a_len > 0;
  ensures \result == min_value(a, 0, a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
*/
int foo55(int * a, int a_len) {

    if (a_len == 0) return -1;
    int res = Integer.MAX_VALUE;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant res == min_value(a, 0, i);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns i, res;
    */
    for (int i = 0; i < a_len; i++) {
        res = (a[i] < res ? a[i] : res);
    }

    return res;
}
