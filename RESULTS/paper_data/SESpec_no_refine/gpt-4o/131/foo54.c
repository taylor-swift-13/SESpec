
/*@
  logic integer max_element(int* a, integer lo, integer hi) =
    lo >= hi ? Integer.MIN_VALUE
             : (a[hi - 1] > max_element(a, lo, hi - 1) ? a[hi - 1] : max_element(a, lo, hi - 1));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns res;
  ensures \result == max_element(a, 0, a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
*/
int foo54(int * a, int a_len) {

    int res = Integer.MIN_VALUE;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant res == max_element(a, 0, i);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns i, res;
    */
    for (int i = 0; i < a_len; i++) {
        res = ((a[i] > res) ? a[i] : res);
    }

    return res;
}
