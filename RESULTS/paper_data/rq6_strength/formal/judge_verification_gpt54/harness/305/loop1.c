#include <limits.h>

/*@ requires (0 <= left) && (right < n) && (left <= right + 1) && (arr_len == \at(arr_len,Pre)) && (n == \at(n,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)) && ((0 < \at(n,Pre) - 1) ==> (0 <= left <= right + 1)) && ((0 < \at(n,Pre) - 1) ==> (right < \at(n,Pre))) && ((!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int k, int left, int n, int p, int right) {
    /*@ assert (\forall integer k; right <= k < n-1 ==> arr[k] <= arr[k+1] || arr[k] >= arr[k+1]); */
    /*@ assert (right == n - 1 || arr[right] >= arr[right + 1]); */
    /*@ assert (right <= n - 1); */
    /*@ assert (right < n); */
    /*@ assert (right + 1 <= n); */
    /*@ assert (left == 0 || arr[left - 1] <= arr[left]); */
    /*@ assert (left == 0 || arr[left - 1] < arr[left]); */
    /*@ assert (left == 0 || arr[left - 1] < arr[left] || right == n - 1 || arr[right] >= arr[right + 1]); */
    /*@ assert (left == 0 || arr[left - 1] < arr[left] || arr[left - 1] <= arr[left]); */
    /*@ assert (\forall integer k; left <= k <= right ==> 0 <= k < n); */
    /*@ assert (\forall integer k; 0 <= k < left ==> arr[k] <= arr[left] || arr[k] >= arr[left]); */
    /*@ assert (\exists integer p; left <= p); */
    /*@ assert (0 <= left); */
}

/*@ requires (\forall integer k; right <= k < n-1 ==> arr[k] <= arr[k+1] || arr[k] >= arr[k+1]) && (right == n - 1 || arr[right] >= arr[right + 1]) && (right <= n - 1) && (right < n) && (right + 1 <= n) && (left == 0 || arr[left - 1] <= arr[left]) && (left == 0 || arr[left - 1] < arr[left]) && (left == 0 || arr[left - 1] < arr[left] || right == n - 1 || arr[right] >= arr[right + 1]) && (left == 0 || arr[left - 1] < arr[left] || arr[left - 1] <= arr[left]) && (\forall integer k; left <= k <= right ==> 0 <= k < n) && (\forall integer k; 0 <= k < left ==> arr[k] <= arr[left] || arr[k] >= arr[left]) && (\exists integer p; left <= p) && (0 <= left);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int k, int left, int n, int p, int right) {
    /*@ assert (0 <= left); */
    /*@ assert (right < n); */
    /*@ assert (left <= right + 1); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert ((0 < \at(n,Pre) - 1) ==> (0 <= left <= right + 1)); */
    /*@ assert ((0 < \at(n,Pre) - 1) ==> (right < \at(n,Pre))); */
    /*@ assert ((!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))); */
}
