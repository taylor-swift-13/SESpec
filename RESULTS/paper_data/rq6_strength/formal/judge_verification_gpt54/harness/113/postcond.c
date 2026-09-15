#include <limits.h>

/*@ logic integer arrlen(int *arr, integer n) = n; */

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires arr_len >= 2 ==> \valid(&arr[0] + (0..arr_len));
  assigns \nothing;
  ensures arr_len < 2 ==> \result == 1;
  ensures arr_len >= 2 ==> (\result == 0 || \result == 1);
  ensures arr_len >= 2 && (\exists integer i; 0 <= i < arr_len - 1 && arr[i] >= arr[i+1]) ==> \result == 0; */
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

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires arr_len >= 2 ==> \valid(&arr[0] + (0..arr_len));
  assigns \nothing;
  ensures arr_len < 2 ==> \result == 1;
  ensures arr_len >= 2 ==> (\result == 0 || \result == 1);
  ensures arr_len >= 2 && (\exists integer i; 0 <= i < arr_len - 1 && arr[i] >= arr[i+1]) ==> \result == 0; */
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
