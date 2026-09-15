
/*@
  logic integer count_non_divisible(integer l, integer m, integer code) =
    (l > m) ? 0 : ((l % code != 0) ? 1 : 0) + count_non_divisible(l + 1, m, code);
*/

/*@
  logic boolean result_matches_count(integer l, integer r, integer code, integer b) =
    count_non_divisible(l, r, code) == b;
*/

/*@
  requires l <= m;
  requires code != 0;
  requires count_non_divisible(l, m, code) >= b;
  assigns \nothing;
*/
int foo193(int code, int b, int l, int m) {

    int result = 0;

    /*@
      loop invariant l <= c <= m + 1;
      loop invariant m == \at(m,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns c, result;
      loop variant m - c;
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
