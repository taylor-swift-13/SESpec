#include <limits.h>

/*@ requires array >= 0;
  requires \valid_read(a + (0 .. array-1));
  assigns \nothing;
  ensures array == 0 ==> \result >= 0;
  ensures array > 0 ==> \result >= 0;
  ensures array > 0 ==> \result <= array + 1;
  ensures \result >= 0;
  ensures \result >= 0; */
int stub_A(int * a, int a_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int array) {
    return stub_A(a, a_len, array);
}

/*@ requires array >= 0;
  requires \valid_read(a + (0 .. array-1));
  assigns \nothing;
  ensures array == 0 ==> \result >= 0;
  ensures array > 0 ==> \result >= 0;
  ensures array > 0 ==> \result <= array + 1;
  ensures \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int * a, int a_len, int array) {
    return stub_B(a, a_len, array);
}
