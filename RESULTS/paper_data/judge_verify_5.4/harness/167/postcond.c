#include <limits.h>

/*@ requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires n >= 0 && n <= arr_len;
  requires k > 0;
  assigns \nothing;
  ensures (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre)); */
int stub_A(int * arr, int arr_len, int n, int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len, int n, int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len, int n, int k) {
    return stub_A(arr, arr_len, n, k);
}

/*@ requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires n >= 0 && n <= arr_len;
  requires k > 0;
  assigns \nothing;
  ensures (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre)); */
int check_B_implies_A(int * arr, int arr_len, int n, int k) {
    return stub_B(arr, arr_len, n, k);
}
