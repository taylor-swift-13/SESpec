#include <limits.h>

/*@ logic integer digit_prod(integer x, integer y) =
    x > y ? 1 : ((x % 10) * digit_prod(x + 1, y)) % 10; */

/*@ requires 0 <= a <= b;
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures (b - a) >= 5 ==> \result == 0;
  ensures 0 <= \result && \result <= 9; */
int stub_A(int a, int b);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int a, int b);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int a, int b) {
    return stub_A(a, b);
}

/*@ requires 0 <= a <= b;
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures (b - a) >= 5 ==> \result == 0;
  ensures 0 <= \result && \result <= 9; */
int check_B_implies_A(int a, int b) {
    return stub_B(a, b);
}
