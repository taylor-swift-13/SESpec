#include <limits.h>

/*@ predicate TRUE = \true; */

/*@ requires arr_len == 1;
  requires \valid(&arr[0]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \exists integer imax, imin;
            0 <= imax < arr_len &&
            0 <= imin < arr_len;
  ensures \result >= 0;
  ensures \result <= 100 || \result > 100;
  ensures \result == 0 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] == arr[0]); */
int stub_A(int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@ requires arr_len == 1;
  requires \valid(&arr[0]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \exists integer imax, imin;
            0 <= imax < arr_len &&
            0 <= imin < arr_len;
  ensures \result >= 0;
  ensures \result <= 100 || \result > 100;
  ensures \result == 0 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] == arr[0]); */
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
