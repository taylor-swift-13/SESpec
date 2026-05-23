#include <limits.h>

/*@ requires n >= 1;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures (\forall integer k; 0 <= k < n - 1 && k % 2 == 0 ==> arr[k] == arr[k + 1]) ==> \result == arr[n - 1];
  ensures \result == arr[n - 1] || (\exists integer k; 0 <= k < n - 1 && k % 2 == 0 && arr[k] != arr[k + 1] && \result == arr[k]);
  ensures \result >= arr[0] || \result <= arr[0]; */
int stub_A(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@ requires n >= 1;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures (\forall integer k; 0 <= k < n - 1 && k % 2 == 0 ==> arr[k] == arr[k + 1]) ==> \result == arr[n - 1];
  ensures \result == arr[n - 1] || (\exists integer k; 0 <= k < n - 1 && k % 2 == 0 && arr[k] != arr[k + 1] && \result == arr[k]);
  ensures \result >= arr[0] || \result <= arr[0]; */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
