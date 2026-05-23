#include <limits.h>

/*@ logic integer count_nondiv(integer code, integer l, integer i) =
      i < l ? 0 : count_nondiv(code, l, i - 1) + (i % code != 0 ? 1 : 0); */

/*@ requires code != 0;
  requires 0 <= l <= c;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result && \result <= c);
  ensures \result != -1 ==> l <= \result && \result <= c;
  ensures \result != -1 ==> (\result % code != 0 || count_nondiv(code, l, \result) == b); */
int stub_A(int code, int b, int l, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int code, int b, int l, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int code, int b, int l, int c) {
    return stub_A(code, b, l, c);
}

/*@ requires code != 0;
  requires 0 <= l <= c;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result && \result <= c);
  ensures \result != -1 ==> l <= \result && \result <= c;
  ensures \result != -1 ==> (\result % code != 0 || count_nondiv(code, l, \result) == b); */
int check_B_implies_A(int code, int b, int l, int c) {
    return stub_B(code, b, l, c);
}
