
/*@
  assigns \nothing;
  ensures (\exists integer c; l <= c <= m && count_not_divisible(l, c+1, code) == b) ==> \result >= l && \result <= m && count_not_divisible(l, \result+1, code) == b && (\forall integer t; l <= t < \result ==> count_not_divisible(l, t+1, code) != b);
  ensures !(\exists integer c; l <= c <= m && count_not_divisible(l, c+1, code) == b) ==> \result == -1;
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
