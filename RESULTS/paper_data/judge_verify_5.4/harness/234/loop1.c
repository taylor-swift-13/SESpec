#include <limits.h>

/*@ logic integer min_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] < min_arr{L}(arr, n-1) ? arr[n-1] : min_arr{L}(arr, n-1)); */
/*@ logic integer max_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] > max_arr{L}(arr, n-1) ? arr[n-1] : max_arr{L}(arr, n-1)); */

/*@ requires (1 <= n <= arr_len) && (\forall integer k; 0 <= k < n ==> arr[k] <= big) && (\forall integer k; 0 <= k < n ==> sum <= arr[k]) && (\exists integer k; 0 <= k < n && arr[k] == big) && (\exists integer k; 0 <= k < n && arr[k] == sum) && (big >= sum) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)) && ((n < arr_len) ==> big >= sum) && ((n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] <= big)) && ((n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> sum <= arr[k])) && ((n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == big)) && ((n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == sum));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int big, int k, int n) {
    /*@ assert ((\exists integer k; 0 <= k < n && sum == arr[k])); */
    /*@ assert ((\exists integer k; 0 <= k < n && big == arr[k])); */
    /*@ assert (sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k])); */
    /*@ assert (sum == arr[0] || sum <= arr[0]); */
    /*@ assert (sum == arr[0] || \exists integer k; 0 <= k <= n && sum == arr[k]); */
    /*@ assert (sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k]); */
    /*@ assert (sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k])); */
    /*@ assert (sum <= big); */
    /*@ assert (sum <= arr[0]); */
    /*@ assert (big == arr[0] || big >= arr[0]); */
    /*@ assert (big == arr[0] || big == arr[n-1] || (\exists integer k; 0 <= k < n && big == arr[k])); */
    /*@ assert (big == arr[0] || \exists integer k; 0 <= k <= n && big == arr[k]); */
    /*@ assert (big == arr[0] || \exists integer k; 0 <= k < n && big == arr[k]); */
    /*@ assert (big == arr[0] || (\exists integer k; 0 <= k < n && big == arr[k])); */
    /*@ assert (arr[0] <= big); */
    /*@ assert (\forall integer k; 0 <= k < n ==> sum <= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> sum <= arr[k] <= big); */
    /*@ assert (\forall integer k; 0 <= k < n ==> big >= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] <= big); */
    /*@ assert (\exists integer k; 0 <= k < n && sum == arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < n && big == arr[k]); */
    /*@ assert (1 <= n); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= n || n <= arr_len); */
    /*@ assert (0 <= n || 1 <= arr_len); */
    /*@ assert (0 < n); */
    /*@ assert ((\exists integer k; 0 <= k < n && big == arr[k]) && (\exists integer k; 0 <= k < n && sum == arr[k])); */
}

/*@ requires ((\exists integer k; 0 <= k < n && sum == arr[k])) && ((\exists integer k; 0 <= k < n && big == arr[k])) && (sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k])) && (sum == arr[0] || sum <= arr[0]) && (sum == arr[0] || \exists integer k; 0 <= k <= n && sum == arr[k]) && (sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k]) && (sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k])) && (sum <= big) && (sum <= arr[0]) && (big == arr[0] || big >= arr[0]) && (big == arr[0] || big == arr[n-1] || (\exists integer k; 0 <= k < n && big == arr[k])) && (big == arr[0] || \exists integer k; 0 <= k <= n && big == arr[k]) && (big == arr[0] || \exists integer k; 0 <= k < n && big == arr[k]) && (big == arr[0] || (\exists integer k; 0 <= k < n && big == arr[k])) && (arr[0] <= big) && (\forall integer k; 0 <= k < n ==> sum <= arr[k]) && (\forall integer k; 0 <= k < n ==> sum <= arr[k] <= big) && (\forall integer k; 0 <= k < n ==> big >= arr[k]) && (\forall integer k; 0 <= k < n ==> arr[k] <= big) && (\exists integer k; 0 <= k < n && sum == arr[k]) && (\exists integer k; 0 <= k < n && big == arr[k]) && (1 <= n) && (0 <= n) && (0 <= n || n <= arr_len) && (0 <= n || 1 <= arr_len) && (0 < n) && ((\exists integer k; 0 <= k < n && big == arr[k]) && (\exists integer k; 0 <= k < n && sum == arr[k]));
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int big, int k, int n) {
    /*@ assert (1 <= n <= arr_len); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] <= big); */
    /*@ assert (\forall integer k; 0 <= k < n ==> sum <= arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < n && arr[k] == big); */
    /*@ assert (\exists integer k; 0 <= k < n && arr[k] == sum); */
    /*@ assert (big >= sum); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert ((n < arr_len) ==> big >= sum); */
    /*@ assert ((n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] <= big)); */
    /*@ assert ((n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> sum <= arr[k])); */
    /*@ assert ((n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == big)); */
    /*@ assert ((n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == sum)); */
}
