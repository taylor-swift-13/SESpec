#include <limits.h>

/*@ predicate ints_unchanged{L1,L2}(int* ints, integer n) =
    \forall integer k; */

/*@ requires array >= 1;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result < array;
  ensures array == 1 ==> \result == 0;
  ensures array > 1 ==> \result <= array - 1; */
int stub_A(int * ints, int ints_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * ints, int ints_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * ints, int ints_len, int array) {
    return stub_A(ints, ints_len, array);
}

/*@ requires array >= 1;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result < array;
  ensures array == 1 ==> \result == 0;
  ensures array > 1 ==> \result <= array - 1; */
int check_B_implies_A(int * ints, int ints_len, int array) {
    return stub_B(ints, ints_len, array);
}
