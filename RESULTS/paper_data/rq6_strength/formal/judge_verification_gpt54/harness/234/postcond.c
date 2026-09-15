#include <limits.h>

/*@ logic integer min_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] < min_arr{L}(arr, n-1) ? arr[n-1] : min_arr{L}(arr, n-1)); */
/*@ logic integer max_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] > max_arr{L}(arr, n-1) ? arr[n-1] : max_arr{L}(arr, n-1)); */

/*@ requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]); */
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

/*@ requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]); */
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
