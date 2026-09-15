#include <limits.h>

/*@ assigns \nothing;
  ensures \result == 0 || (\result <= value && (\result % k) == z);
  ensures value == \old(value);
  ensures k == \old(k);
  ensures z == \old(z); */
int stub_A(int value, int k, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int value, int k, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int value, int k, int z) {
    return stub_A(value, k, z);
}

/*@ assigns \nothing;
  ensures \result == 0 || (\result <= value && (\result % k) == z);
  ensures value == \old(value);
  ensures k == \old(k);
  ensures z == \old(z); */
int check_B_implies_A(int value, int k, int z) {
    return stub_B(value, k, z);
}
