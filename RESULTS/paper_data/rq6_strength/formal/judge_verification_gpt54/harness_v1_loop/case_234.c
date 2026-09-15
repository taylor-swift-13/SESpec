#include <limits.h>

/*@logic integer min_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] < min_arr{L}(arr, n-1) ? arr[n-1] : min_arr{L}(arr, n-1));*/
/*@logic integer max_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] > max_arr{L}(arr, n-1) ? arr[n-1] : max_arr{L}(arr, n-1));*/

/*@ requires (1 <= n <= arr_len) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (big >= sum) && (\forall integer k) && ((n < arr_len) ==> big >= sum) && ((n >= arr_len) ==> (\forall integer k) && ((n >= arr_len) ==> (\forall integer k) && ((n >= arr_len) ==> (\exists integer k) && ((n >= arr_len) ==> (\exists integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int *big, int *k, int *n) {
    /*@ assert ((\exists integer k) && ((\exists integer k) && (sum == arr[0] || sum == arr[n-1] || (\exists integer k) && (sum == arr[0] || sum <= arr[0]) && (sum == arr[0] || \exists integer k) && (sum == arr[0] || \exists integer k) && (sum == arr[0] || (\exists integer k) && (sum <= big) && (sum <= arr[0]) && (big == arr[0] || big >= arr[0]) && (big == arr[0] || big == arr[n-1] || (\exists integer k) && (big == arr[0] || \exists integer k) && (big == arr[0] || \exists integer k) && (big == arr[0] || (\exists integer k) && (arr[0] <= big) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= n) && (0 <= n) && (0 <= n || n <= arr_len) && (0 <= n || 1 <= arr_len) && (0 < n) && ((\exists integer k); */
}

/*@ requires ((\exists integer k) && ((\exists integer k) && (sum == arr[0] || sum == arr[n-1] || (\exists integer k) && (sum == arr[0] || sum <= arr[0]) && (sum == arr[0] || \exists integer k) && (sum == arr[0] || \exists integer k) && (sum == arr[0] || (\exists integer k) && (sum <= big) && (sum <= arr[0]) && (big == arr[0] || big >= arr[0]) && (big == arr[0] || big == arr[n-1] || (\exists integer k) && (big == arr[0] || \exists integer k) && (big == arr[0] || \exists integer k) && (big == arr[0] || (\exists integer k) && (arr[0] <= big) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= n) && (0 <= n) && (0 <= n || n <= arr_len) && (0 <= n || 1 <= arr_len) && (0 < n) && ((\exists integer k);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int *big, int *k, int *n) {
    /*@ assert (1 <= n <= arr_len) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (big >= sum) && (\forall integer k) && ((n < arr_len) ==> big >= sum) && ((n >= arr_len) ==> (\forall integer k) && ((n >= arr_len) ==> (\forall integer k) && ((n >= arr_len) ==> (\exists integer k) && ((n >= arr_len) ==> (\exists integer k); */
}
