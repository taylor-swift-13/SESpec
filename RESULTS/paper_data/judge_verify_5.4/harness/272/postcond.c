#include <limits.h>

/*@ predicate all_equal_prefix(int *arr, integer n, integer i, int v) =
    \forall integer k; */

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == \null ==> \false;
  ensures \result == "NO" ==> n == 0 || n > 0;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre); */
const char * stub_A(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * stub_B(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == \null ==> \false;
  ensures \result == "NO" ==> n == 0 || n > 0;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre); */
const char * check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
