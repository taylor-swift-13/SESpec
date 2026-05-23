#include <limits.h>

/*@ logic integer nondiv_count(integer a, integer l, integer u) =
      u < l ? 0 : nondiv_count(a, l, u - 1) + ((u % a) != 0 ? 1 : 0); */

/*@ requires a != 0;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= r;
  ensures \result != -1 ==> nondiv_count(a, l, \result) == n;
  ensures \result == -1 || (l <= \result && \result <= r);
  ensures \result == -1 || (nondiv_count(a, l, \result) == n); */
int stub_A(int a, int n, int l, int r);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int a, int n, int l, int r);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int a, int n, int l, int r) {
    return stub_A(a, n, l, r);
}

/*@ requires a != 0;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= r;
  ensures \result != -1 ==> nondiv_count(a, l, \result) == n;
  ensures \result == -1 || (l <= \result && \result <= r);
  ensures \result == -1 || (nondiv_count(a, l, \result) == n); */
int check_B_implies_A(int a, int n, int l, int r) {
    return stub_B(a, n, l, r);
}
