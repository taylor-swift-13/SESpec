#include <limits.h>

/*@ logic boolean strict_decreasing_prefix(int* a, integer lo, integer hi) =
    hi <= lo + 1 ? \true
                  : strict_decreasing_prefix(a, lo, hi - 1) && a[hi - 2] > a[hi - 1]; */

/*@ requires (0 <= i <= n) && (strict_decreasing_prefix(arr, 0, i)) && (\forall integer k; 0 <= k < i ==> (k + 1 < n ==> arr[k] > arr[k+1])) && (\forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre)) && ((i < n) ==> (i + 1 <= n)) && ((i == n) ==> strict_decreasing_prefix(arr, 0, n)) && ((i == n) ==> (\forall integer k; 0 <= k < n - 1 ==> arr[k] > arr[k+1])) && ((i > 0) ==> arr[i-1] > arr[i]);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int i, int k, int n) {
    /*@ assert (i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1])); */
    /*@ assert (i <= n + 1); */
    /*@ assert (1 <= n || n < 2); */
    /*@ assert (0 <= n); */
    /*@ assert (n == arr_len); */
    /*@ assert (n == arr_len && 2 <= n); */
    /*@ assert (i > 0 ==> arr[i-1] > arr[i]); */
    /*@ assert (i == 0 || i > 0); */
    /*@ assert (i == 0 || arr[i-1] >= arr[i]); */
    /*@ assert (i == 0 || arr[i-1] > arr[i]); */
    /*@ assert (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]); */
    /*@ assert (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]); */
    /*@ assert (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]); */
    /*@ assert (i == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]); */
    /*@ assert (i <= n); */
    /*@ assert (i <= n && 0 <= i); */
    /*@ assert (i < n ==> i + 1 <= n); */
    /*@ assert (i < n ==> arr_len == n); */
    /*@ assert (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]); */
    /*@ assert (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1); */
    /*@ assert (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]); */
    /*@ assert (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]); */
    /*@ assert (i < n + 1); */
    /*@ assert (arr_len == n); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1] || i == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]); */
    /*@ assert (2 <= n); */
    /*@ assert (2 <= n || i == 0); */
    /*@ assert (2 <= n ==> i <= n); */
    /*@ assert (2 <= n ==> i < n + 1); */
    /*@ assert (2 <= n ==> 0 <= i); */
    /*@ assert (1 <= n); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= i ==> i <= n); */
    /*@ assert (0 <= i ==> i < n + 1); */
    /*@ assert (0 <= i && i <= n); */
}

/*@ requires (i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1])) && (i <= n + 1) && (1 <= n || n < 2) && (0 <= n) && (n == arr_len) && (n == arr_len && 2 <= n) && (i > 0 ==> arr[i-1] > arr[i]) && (i == 0 || i > 0) && (i == 0 || arr[i-1] >= arr[i]) && (i == 0 || arr[i-1] > arr[i]) && (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]) && (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]) && (i == 0 || \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]) && (i == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]) && (i <= n) && (i <= n && 0 <= i) && (i < n ==> i + 1 <= n) && (i < n ==> arr_len == n) && (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]) && (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1) && (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]) && (i < n ==> \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]) && (i < n + 1) && (arr_len == n) && (\forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1]) && (\forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1) && (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]) && (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1] || i == 0) && (\forall integer k; 0 <= k < i ==> arr[k] != arr[k+1]) && (2 <= n) && (2 <= n || i == 0) && (2 <= n ==> i <= n) && (2 <= n ==> i < n + 1) && (2 <= n ==> 0 <= i) && (1 <= n) && (0 <= i) && (0 <= i ==> i <= n) && (0 <= i ==> i < n + 1) && (0 <= i && i <= n);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int i, int k, int n) {
    /*@ assert (0 <= i <= n); */
    /*@ assert (strict_decreasing_prefix(arr, 0, i)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k + 1 < n ==> arr[k] > arr[k+1])); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert ((i < n) ==> (i + 1 <= n)); */
    /*@ assert ((i == n) ==> strict_decreasing_prefix(arr, 0, n)); */
    /*@ assert ((i == n) ==> (\forall integer k; 0 <= k < n - 1 ==> arr[k] > arr[k+1])); */
    /*@ assert ((i > 0) ==> arr[i-1] > arr[i]); */
}
