#include <limits.h>

/*@ logic integer gcd(integer a, integer b) =
      b == 0 ? a : gcd(b, a % b); */

/*@ requires n > 0 && y > 0;
  assigns \nothing;
  ensures (\old(n) <= 0 || \old(y) <= 0) ==> \result == \old(n) * \old(y);
  ensures (\old(n) > 0 && \old(y) > 0) ==> \result > 0; */
int stub_A(int n, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int y) {
    return stub_A(n, y);
}

/*@ requires n > 0 && y > 0;
  assigns \nothing;
  ensures (\old(n) <= 0 || \old(y) <= 0) ==> \result == \old(n) * \old(y);
  ensures (\old(n) > 0 && \old(y) > 0) ==> \result > 0; */
int check_B_implies_A(int n, int y) {
    return stub_B(n, y);
}
