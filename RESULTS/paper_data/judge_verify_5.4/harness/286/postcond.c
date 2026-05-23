#include <limits.h>
#include <stdlib.h>

/*@ requires j + 1 > 0; */
int stub_A(int j);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int j);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int j) {
    return stub_A(j);
}

/*@ requires j + 1 > 0; */
int check_B_implies_A(int j) {
    return stub_B(j);
}
