#include <limits.h>

/*@ logic integer gcd(integer a, integer b) =
  b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b); */

/*@ requires n > y;
  requires n >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \true;
  ensures \result >= 0; */
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

/*@ requires n > y;
  requires n >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \true;
  ensures \result >= 0; */
int check_B_implies_A(int n, int y) {
    return stub_B(n, y);
}
