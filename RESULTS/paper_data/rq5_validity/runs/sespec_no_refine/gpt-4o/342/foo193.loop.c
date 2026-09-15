
/*@
  logic integer count_non_divisible(integer start, integer end, integer divisor) =
    (start > end) ? 0 : ((start % divisor != 0 ? 1 : 0) + count_non_divisible(start + 1, end, divisor));
*/

/*@
  requires m >= l;
  requires code > 0;
  requires b >= 0;
  ensures \result == -1 || (l <= \result <= m && count_non_divisible(l, \result, code) == b);
*/
int foo193(int code, int b, int l, int m) {
    int result = 0;

    /*@
      loop invariant l <= c <= m + 1;
      loop invariant m == \at(m, Pre);
      loop invariant l == \at(l, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant code == \at(code, Pre);
      loop assigns c, result;
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            result++;
        }
        if (result == b) {
            return c;
        }
    }

    return -1;
}
