#include <limits.h>

/*@ logic integer even_sum(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a : 0) + even_sum(a + 1, b); */

/*@ requires l <= r + 1;
  assigns \nothing; */
int stub_A(int l, int r);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int l, int r);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int l, int r) {
    return stub_A(l, r);
}

/*@ requires l <= r + 1;
  assigns \nothing; */
int check_B_implies_A(int l, int r) {
    return stub_B(l, r);
}
