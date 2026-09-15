#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires size > 0;
  requires size <= array_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1; */
int stub_A(int size, int * array, int array_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int size, int * array, int array_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int size, int * array, int array_len) {
    return stub_A(size, array, array_len);
}

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires size > 0;
  requires size <= array_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1; */
int check_B_implies_A(int size, int * array, int array_len) {
    return stub_B(size, array, array_len);
}
