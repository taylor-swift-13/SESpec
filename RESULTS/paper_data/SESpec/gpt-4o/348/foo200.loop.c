
/*@
  logic integer count_non_multiples(integer a, integer l, integer r) =
    (l > r) ? 0 : ((l % a != 0) ? 1 : 0) + count_non_multiples(a, l + 1, r);
*/

/*@
  requires a > 0;
  requires n >= 0;
  requires l <= r;
  ensures \result == -1 || (l <= \result <= r && count_non_multiples(a, l, \result) == n);
*/
int foo200(int a, int n, int l, int r) {
    int count = 0;

    /*@
      loop invariant l <= i <= r + 1;
      loop invariant r == \at(r, Pre);
      loop invariant l == \at(l, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns i, count;
    */
    for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count++;
        }
        if (count == n) {
            return i;
        }
    }

    return -1;
}
