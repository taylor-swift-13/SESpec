#include <limits.h>

/*@ requires size >= 1;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
  ensures \result <= size; */
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

/*@ requires size >= 1;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
  ensures \result <= size; */
int check_B_implies_A(int size) {
    return stub_B(size);
}
