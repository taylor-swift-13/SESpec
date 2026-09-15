
/*@
  logic integer count_non_divisible(integer start, integer end, integer divisor) =
    start > end ? 0 : (start % divisor != 0 ? 1 : 0) + count_non_divisible(start + 1, end, divisor);
*/

int foo344(int code, int b, int l, int m) {

    int ret = 0;

    /*@
      loop invariant m == \at(m,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns c, ret;
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            ret++;
        }
        if (ret == b) {
            return c;
        }
    }

    return -1;
}
