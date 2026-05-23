
/*@
  logic integer count_non_divisible(int start, int end, int divisor) =
    (start > end) ? 0 : (start % divisor != 0 ? 1 : 0) + count_non_divisible(start + 1, end, divisor);
*/

/*@
  requires code > 0;
  requires l <= c;
  requires b >= 0;
  ensures \result == -1 || (l <= \result <= c && count_non_divisible(l, \result, code) == b);
*/
int foo194(int code, int b, int l, int c) {
    int ret = 0;

    /*@
      loop invariant l <= loop <= c + 1;
      loop invariant ret == count_non_divisible(l, loop - 1, code);
      loop invariant c == \at(c, Pre);
      loop invariant l == \at(l, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant code == \at(code, Pre);
      loop assigns loop, ret;
    */
    for (int loop = l; loop <= c; loop++) {
        if (loop % code != 0) {
            ret++;
        }
        if (ret == b) {
            return loop;
        }
    }

    return -1;
}
