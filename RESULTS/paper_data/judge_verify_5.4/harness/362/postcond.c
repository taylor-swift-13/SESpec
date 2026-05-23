#include <limits.h>

/*@ assigns \nothing;
  ensures size == \old(size);
  ensures size > 1 ==> \result == size / 2 + 1;
  ensures size > 1 ==> \result >= 1;
  ensures size > 1 ==> \result <= size; */
int stub_A(int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int size) {
    return stub_A(size);
}

/*@ assigns \nothing;
  ensures size == \old(size);
  ensures size > 1 ==> \result == size / 2 + 1;
  ensures size > 1 ==> \result >= 1;
  ensures size > 1 ==> \result <= size; */
int check_B_implies_A(int size) {
    return stub_B(size);
}
