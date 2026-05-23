#include <limits.h>

/*@ logic integer prod{L}(int *a, integer l, integer u) =
  (l >= u) ? 1 : ((integer)a[l] * prod(a, l + 1, u)); */
/*@ logic integer suffixsum(int *a, integer i, integer n) =
  (i >= n) ? 0 : prod(a, i, n) + suffixsum(a, i + 1, n); */
/*@ logic integer contrib(int *a, integer i, integer j) =
  (j <= i) ? 0 : contrib(a, i, j - 1) + prod(a, i, j - 1); */
/*@ logic integer row_contrib_sum(int *a, integer i, integer n) =
  (i >= n) ? 0 : contrib(a, i, n) + row_contrib_sum(a, i + 1, n); */

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures n == 0 ==> \result >= 0;
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

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures n == 0 ==> \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
