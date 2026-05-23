#include <limits.h>

/*@ requires count >= 0;
  assigns \nothing;
  ensures count == \at(count, Pre);
  ensures \result >= 0;
  ensures \result <= (2 * count) * (2 * count);
  ensures count == 0 ==> \result == 0;
  ensures count > 0 ==> \result >= 0;
  ensures \result == 0 ==> count >= 0;
  ensures \result > 0 ==> count > 0; */
int stub_A(int count);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int count);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int count) {
    return stub_A(count);
}

/*@ requires count >= 0;
  assigns \nothing;
  ensures count == \at(count, Pre);
  ensures \result >= 0;
  ensures \result <= (2 * count) * (2 * count);
  ensures count == 0 ==> \result == 0;
  ensures count > 0 ==> \result >= 0;
  ensures \result == 0 ==> count >= 0;
  ensures \result > 0 ==> count > 0; */
int check_B_implies_A(int count) {
    return stub_B(count);
}
