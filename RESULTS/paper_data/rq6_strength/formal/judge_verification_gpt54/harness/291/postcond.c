#include <limits.h>
#include <stdlib.h>

/*@ requires c >= 1; */
int stub_A(int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int c) {
    return stub_A(c);
}

/*@ requires c >= 1; */
int check_B_implies_A(int c) {
    return stub_B(c);
}
