
/*@
  axiomatic NonDivCount {
    logic integer nondiv_count(integer code, integer l, integer u);

    axiom nondiv_count_empty:
      \forall integer code, l, u; l > u ==> nondiv_count(code, l, u) == 0;

    axiom nondiv_count_step:
      \forall integer code, l, u; l <= u && code != 0 ==>
        nondiv_count(code, l, u) ==
          nondiv_count(code, l, u - 1) + ((u % code != 0) ? 1 : 0);
  }
*/

/*@
  requires code != 0;
  requires l <= m + 1;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= m;
  ensures \result != -1 ==> nondiv_count(code, l, \result) == b;
  ensures \result != -1 ==> \forall integer c; l <= c < \result ==> nondiv_count(code, l, c) != b;
*/
int foo342(int code, int b, int l, int m) {

  int result = 0;

  /*@
    loop invariant l <= c <= m + 1;
    loop invariant result >= 0;
    loop invariant result == nondiv_count(code, l, c - 1);
    loop invariant \forall integer k; l <= k < c ==> nondiv_count(code, l, k) != b;
    loop assigns c, result;
    loop variant m - c + 1;
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
