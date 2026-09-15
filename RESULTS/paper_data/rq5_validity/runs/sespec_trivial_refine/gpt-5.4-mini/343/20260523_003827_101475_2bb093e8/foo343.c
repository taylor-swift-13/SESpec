
        /*@ logic integer count_nondiv(integer code, integer l, integer u) =
      u < l ? 0 : (code == 0 ? 0 : count_nondiv(code, l, u - 1) + ((u % code != 0) ? 1 : 0)); */
/*@ 
  requires code != 0;
  requires l <= c;
  requires b >= 0;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= c;
  ensures \result != -1 ==> count_nondiv(code, l, \result) == b;
  ensures \result != -1 ==> \forall integer i; l <= i < \result ==> count_nondiv(code, l, i) != b;
*/
int foo343(int code, int b, int l, int c) {
  int ret = 0;

  /*@
    loop invariant l <= loop <= c + 1;
    loop invariant ret == count_nondiv(code, l, loop - 1);
    loop invariant loop == l ==> ret == 0;
    loop invariant loop > l ==> ret != b;
    loop invariant \forall integer i; l <= i < loop ==> count_nondiv(code, l, i) != b;
    loop assigns loop, ret;
    loop variant c - loop + 1;
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
