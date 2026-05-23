#include <limits.h>
#include <stdlib.h>

/*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@ requires (1 <= d <= seed + 1) && (arr[0] == 1) && (d <= arr_len) && (\forall integer k; 0 <= k < d ==> arr[k] >= 1) && (!(d <= seed) ==> d == seed + 1);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int d, int k, int seed) {
    /*@ assert (\exists integer k; 0 <= k < d && arr[k] >= 0); */
    /*@ assert (result == 0); */
    /*@ assert (d == 1 || d > 1); */
    /*@ assert (d == 0 || d >= 1); */
    /*@ assert (arr_len == seed + 1); */
    /*@ assert (arr[0] == 1); */
    /*@ assert (\forall integer k; 1 <= k < d ==> arr[k] == arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < d ==> arr[k] == arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < d ==> arr[k] >= 1); */
    /*@ assert (\exists integer k; 0 <= k < d && arr[k] >= 1); */
    /*@ assert (\exists integer k; 0 <= k < d && arr[k] > 0); */
    /*@ assert (\exists integer k; 0 <= k < d && arr[k] == 1); */
    /*@ assert (1 <= d); */
    /*@ assert (1 <= d || d == 0); */
    /*@ assert (0 <= seed || 0 <= d); */
    /*@ assert (0 <= seed || 0 <= d - 1); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= d); */
    /*@ assert (0 <= d - 1); */
    /*@ assert (0 <= d - 1 || d <= seed); */
    /*@ assert (0 <= d - 1 || d <= seed + 1); */
}

/*@ requires (\exists integer k; 0 <= k < d && arr[k] >= 0) && (result == 0) && (d == 1 || d > 1) && (d == 0 || d >= 1) && (arr_len == seed + 1) && (arr[0] == 1) && (\forall integer k; 1 <= k < d ==> arr[k] == arr[k]) && (\forall integer k; 0 <= k < d ==> arr[k] == arr[k]) && (\exists integer k; 0 <= k < d ==> arr[k] >= 1) && (\exists integer k; 0 <= k < d && arr[k] >= 1) && (\exists integer k; 0 <= k < d && arr[k] > 0) && (\exists integer k; 0 <= k < d && arr[k] == 1) && (1 <= d) && (1 <= d || d == 0) && (0 <= seed || 0 <= d) && (0 <= seed || 0 <= d - 1) && (0 <= result) && (0 <= d) && (0 <= d - 1) && (0 <= d - 1 || d <= seed) && (0 <= d - 1 || d <= seed + 1);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int d, int k, int seed) {
    /*@ assert (1 <= d <= seed + 1); */
    /*@ assert (arr[0] == 1); */
    /*@ assert (d <= arr_len); */
    /*@ assert (\forall integer k; 0 <= k < d ==> arr[k] >= 1); */
    /*@ assert (!(d <= seed) ==> d == seed + 1); */
}
