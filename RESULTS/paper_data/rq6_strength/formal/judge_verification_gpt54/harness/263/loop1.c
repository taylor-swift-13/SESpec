#include <limits.h>

/*@ requires (0 <= start <= \at(n,Pre)) && (-1 <= end < \at(n,Pre)) && (start <= end + 1) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)) && ((0 <= \at(n,Pre) - 1) ==> (start <= end + 1)) && ((0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= start <= \at(n,Pre)))) && ((0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= end < \at(n,Pre)))) && ((!(0 <= \at(n,Pre) - 1)) ==> ((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int end, int k, int n, int start) {
    /*@ assert (start == 0 || start <= end + 1); */
    /*@ assert (start == 0 || start - 1 < n); */
    /*@ assert (end == n - 1 || end + 1 < n); */
    /*@ assert (start >= 0 && end < n); */
    /*@ assert (start == 0 || start > 0); */
    /*@ assert (start == 0 || start <= n); */
    /*@ assert (start == 0 || end == n - 1 || start <= end + 1); */
    /*@ assert (start == 0 || arr[start-1] < start-1); */
    /*@ assert (start == 0 || arr[start-1] < start - 1); */
    /*@ assert (start == 0 || arr[start - 1] < start - 1); */
    /*@ assert (start <= end + 1 ==> start - 1 <= end); */
    /*@ assert (end == n-1 || arr[end+1] > end+1); */
    /*@ assert (end == n - 1 || end < n - 1); */
    /*@ assert (end == n - 1 || arr[end+1] > end+1); */
    /*@ assert (end == n - 1 || arr[end+1] > end + 1); */
    /*@ assert (end == n - 1 || arr[end + 1] > end + 1); */
    /*@ assert (end < n); */
    /*@ assert (end < n || end == n - 1); */
    /*@ assert (end + 1 <= n); */
    /*@ assert (0 <= start); */
    /*@ assert (0 <= start || start == 0); */
    /*@ assert (0 <= start && end + 1 <= n); */
}

/*@ requires (start == 0 || start <= end + 1) && (start == 0 || start - 1 < n) && (end == n - 1 || end + 1 < n) && (start >= 0 && end < n) && (start == 0 || start > 0) && (start == 0 || start <= n) && (start == 0 || end == n - 1 || start <= end + 1) && (start == 0 || arr[start-1] < start-1) && (start == 0 || arr[start-1] < start - 1) && (start == 0 || arr[start - 1] < start - 1) && (start <= end + 1 ==> start - 1 <= end) && (end == n-1 || arr[end+1] > end+1) && (end == n - 1 || end < n - 1) && (end == n - 1 || arr[end+1] > end+1) && (end == n - 1 || arr[end+1] > end + 1) && (end == n - 1 || arr[end + 1] > end + 1) && (end < n) && (end < n || end == n - 1) && (end + 1 <= n) && (0 <= start) && (0 <= start || start == 0) && (0 <= start && end + 1 <= n);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int end, int k, int n, int start) {
    /*@ assert (0 <= start <= \at(n,Pre)); */
    /*@ assert (-1 <= end < \at(n,Pre)); */
    /*@ assert (start <= end + 1); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert ((0 <= \at(n,Pre) - 1) ==> (start <= end + 1)); */
    /*@ assert ((0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= start <= \at(n,Pre)))); */
    /*@ assert ((0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= end < \at(n,Pre)))); */
    /*@ assert ((!(0 <= \at(n,Pre) - 1)) ==> ((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
}
