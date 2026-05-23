
/*@
  logic integer count_non_divisible(int start, int end, int divisor) =
    (start > end) ? 0 : ((start % divisor != 0) ? 1 : 0) + count_non_divisible(start + 1, end, divisor);
*/

/*@
  requires code > 0;
  requires b >= 0;
  requires l <= m;
  assigns \nothing;
  ensures \result == -1 || (l <= \result <= m && count_non_divisible(l, \result, code) == b);
*/
int foo195(int code, int b, int l, int m) {

    int ret = 0;

    /*@
      loop invariant l <= c <= m + 1;
      loop invariant ret == count_non_divisible(l, c - 1, code);
      loop invariant (c <= m) ==> (ret <= b);
      loop invariant (!(c <= m)) ==> ((ret == 0) && (m == \at(m,Pre)) && (l == \at(l,Pre)) && (b == \at(b,Pre)) && (code == \at(code,Pre)));
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
