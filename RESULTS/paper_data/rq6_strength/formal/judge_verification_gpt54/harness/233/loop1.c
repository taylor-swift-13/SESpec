#include <limits.h>

/*@ predicate TRUE = \true; */

/*@ requires (1 <= n) && (result >= num) && (result >= arr[0]) && (num <= arr[0]) && (\forall integer k; 0 <= k < n ==> arr[k] <= result) && (\forall integer k; 0 <= k < n ==> arr[k] >= num) && (\exists integer k; 0 <= k < n && arr[k] == result) && (\exists integer k; 0 <= k < n && arr[k] == num) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)) && ((n >= arr_len) ==> result - num >= 0);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int k, int n, int num) {
    /*@ assert (result >= arr[0] && num <= arr[0]); */
    /*@ assert (result == arr[0] || result >= num); */
    /*@ assert (result == arr[0] || result >= arr[0]); */
    /*@ assert (result == arr[0] || result == num || \exists integer k; 0 <= k < n && result == arr[k]); */
    /*@ assert (result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k]); */
    /*@ assert (result == arr[0] || num == arr[0] || result >= num); */
    /*@ assert (result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k]); */
    /*@ assert (num == arr[0] || num == arr[n-1] || \exists integer k; 0 <= k < n && num == arr[k]); */
    /*@ assert (num == arr[0] || num <= result); */
    /*@ assert (num == arr[0] || num <= arr[0]); */
    /*@ assert (num == arr[0] || \exists integer k; 0 <= k < n && num == arr[k]); */
    /*@ assert (num <= result); */
    /*@ assert (num <= arr[0]); */
    /*@ assert (num <= arr[0] || num <= result); */
    /*@ assert (n <= arr_len || num <= arr[0]); */
    /*@ assert (arr[0] <= result); */
    /*@ assert (arr[0] <= result || result == arr[0]); */
    /*@ assert (arr[0] <= result || result <= arr[0]); */
    /*@ assert (arr[0] <= result || num <= arr[0]); */
    /*@ assert (arr[0] <= result || n <= arr_len); */
    /*@ assert (arr[0] <= result || 0 <= result - num); */
    /*@ assert (\forall integer k; 0 <= k < n ==> result >= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> result >= arr[k] && num <= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> num <= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> num <= arr[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < n ==> num <= arr[k] && arr[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] <= result); */
    /*@ assert (\exists integer k; 0 <= k < n && result >= arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < n && result == arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < n && num == arr[k]); */
    /*@ assert (1 <= n); */
    /*@ assert (0 <= result - num); */
    /*@ assert (0 <= result - num || num <= arr[0]); */
    /*@ assert (0 <= result - num || n <= arr_len); */
    /*@ assert (0 <= n); */
    /*@ assert (0 < n); */
}

/*@ requires (result >= arr[0] && num <= arr[0]) && (result == arr[0] || result >= num) && (result == arr[0] || result >= arr[0]) && (result == arr[0] || result == num || \exists integer k; 0 <= k < n && result == arr[k]) && (result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k]) && (result == arr[0] || num == arr[0] || result >= num) && (result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k]) && (num == arr[0] || num == arr[n-1] || \exists integer k; 0 <= k < n && num == arr[k]) && (num == arr[0] || num <= result) && (num == arr[0] || num <= arr[0]) && (num == arr[0] || \exists integer k; 0 <= k < n && num == arr[k]) && (num <= result) && (num <= arr[0]) && (num <= arr[0] || num <= result) && (n <= arr_len || num <= arr[0]) && (arr[0] <= result) && (arr[0] <= result || result == arr[0]) && (arr[0] <= result || result <= arr[0]) && (arr[0] <= result || num <= arr[0]) && (arr[0] <= result || n <= arr_len) && (arr[0] <= result || 0 <= result - num) && (\forall integer k; 0 <= k < n ==> result >= arr[k]) && (\forall integer k; 0 <= k < n ==> result >= arr[k] && num <= arr[k]) && (\forall integer k; 0 <= k < n ==> num <= arr[k]) && (\forall integer k; 0 <= k < n ==> num <= arr[k] <= result) && (\forall integer k; 0 <= k < n ==> num <= arr[k] && arr[k] <= result) && (\forall integer k; 0 <= k < n ==> arr[k] <= result) && (\exists integer k; 0 <= k < n && result >= arr[k]) && (\exists integer k; 0 <= k < n && result == arr[k]) && (\exists integer k; 0 <= k < n && num == arr[k]) && (1 <= n) && (0 <= result - num) && (0 <= result - num || num <= arr[0]) && (0 <= result - num || n <= arr_len) && (0 <= n) && (0 < n);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int k, int n, int num) {
    /*@ assert (1 <= n); */
    /*@ assert (result >= num); */
    /*@ assert (result >= arr[0]); */
    /*@ assert (num <= arr[0]); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < n ==> arr[k] >= num); */
    /*@ assert (\exists integer k; 0 <= k < n && arr[k] == result); */
    /*@ assert (\exists integer k; 0 <= k < n && arr[k] == num); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert ((n >= arr_len) ==> result - num >= 0); */
}
