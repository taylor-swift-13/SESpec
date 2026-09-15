#include <limits.h>

/*@ requires radius >= 0;
  requires radius == 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures radius > 0 ==> \result >= 0;
  ensures \result >= 0; */
int stub_A(int radius);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int radius);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int radius) {
    return stub_A(radius);
}

/*@ requires radius >= 0;
  requires radius == 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures radius > 0 ==> \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int radius) {
    return stub_B(radius);
}
