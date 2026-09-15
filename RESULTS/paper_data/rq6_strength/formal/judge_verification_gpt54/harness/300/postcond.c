#include <limits.h>

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires 0 < Array <= array_len;
  requires \forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1];
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result < Array; */
int stub_A(int * array, int array_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * array, int array_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * array, int array_len, int Array) {
    return stub_A(array, array_len, Array);
}

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires 0 < Array <= array_len;
  requires \forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1];
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result < Array; */
int check_B_implies_A(int * array, int array_len, int Array) {
    return stub_B(array, array_len, Array);
}
