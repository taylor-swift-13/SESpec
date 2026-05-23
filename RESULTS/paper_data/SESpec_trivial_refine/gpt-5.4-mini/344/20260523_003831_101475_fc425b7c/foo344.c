
        /*@
  logic integer count_nondiv2(integer l, integer u, integer code) =
    u < l ? 0 :
    count_nondiv2(l, u - 1, code) + ((u % code) != 0 ? 1 : 0);
*/
/*@ 
  requires code != 0;
  requires b > 0;
  requires l <= m;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= m;
  ensures \result != -1 ==> \result % code != 0;
  ensures \result != -1 ==> count_nondiv2(l, \result, code) == b;
  ensures \result != -1 ==> \forall integer t; l <= t < \result ==> count_nondiv2(l, t, code) < b;
*/
int foo344(int code, int b, int l, int m) {
    int ret = 0;

    /*@
      loop invariant l <= c <= m + 1;
      loop invariant 0 <= ret < b;
      loop invariant ret == count_nondiv2(l, c - 1, code);
      loop invariant \forall integer t; l <= t < c ==> count_nondiv2(l, t, code) < b;
      loop assigns ret, c;
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            ret++;
            if (ret == b) {
                return c;
            }
        }
    }

    return -1;
}
