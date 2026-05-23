#include <limits.h>

/*@ logic integer inv_between(int *arr, integer n, integer i, integer j) =
  j <= i + 1 ? 0 : inv_between(arr, n, i, j - 1) + (arr[i] > arr[j - 1] ? 1 : 0); */
/*@ logic integer inv_prefix(int *arr, integer n, integer i) =
  i <= 0 ? 0 : inv_prefix(arr, n, i - 1) + inv_between(arr, n, i - 1, n); */

/*@ requires 0 <= n <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] && arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
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

/*@ requires 0 <= n <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] && arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
