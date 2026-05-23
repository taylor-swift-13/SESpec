
/*@
  // Counts how many integers x in [lo, hi) are NOT divisible by d.
  logic integer count_not_divisible(integer lo, integer hi, integer d) =
    (hi <= lo) ? 0 :
      count_not_divisible(lo, hi - 1, d) + (((hi - 1) % d != 0) ? 1 : 0);
*/

int foo344(int code, int b, int l, int m) {

    int ret = 0;
        
    /*@
      loop invariant ret >= 0;
      loop invariant (c <= m) ==> (ret >= 0);
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
