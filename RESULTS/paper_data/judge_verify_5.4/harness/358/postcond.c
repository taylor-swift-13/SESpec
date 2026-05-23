#include <limits.h>

/*@ requires size >= 0;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 && size % 2 == 0 ==> 2 * \result == size;
  ensures size > 0 && size % 2 != 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1; */
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

/*@ requires size >= 0;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 && size % 2 == 0 ==> 2 * \result == size;
  ensures size > 0 && size % 2 != 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1; */
int check_B_implies_A(int size) {
    return stub_B(size);
}
