#include <limits.h>
#include <stdlib.h>

/*@ logic integer dpval(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    dpval(k - 1) + 2 * dpval(k - 2); */

/*@ requires n >= 1; */
int stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ requires n >= 1; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
