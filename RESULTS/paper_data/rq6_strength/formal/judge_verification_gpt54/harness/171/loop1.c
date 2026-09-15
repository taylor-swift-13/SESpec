#include <limits.h>

/*@ requires (count >= 0) && (result >= 0) && (tmp >= 0) && (result + tmp == count) && (c == \at(c,Pre)) && (n == \at(n,Pre)) && (Array == \at(Array,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (arr1_len == \at(arr1_len,Pre)) && (arr1 == \at(arr1,Pre)) && (\forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k],Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre)) && ((count < \at(c,Pre)) ==> \true) && ((count < \at(c,Pre)) ==> (result >= 0)) && ((count < \at(c,Pre)) ==> (tmp >= 0)) && ((!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int Array, int *arr, int *arr1, int arr1_len, int arr_len, int c, int count, int k, int n, int tmp) {
    /*@ assert (tmp < n ==> result < Array || tmp >= 0); */
    /*@ assert (result < Array ==> tmp < n || result >= 0); */
    /*@ assert (count - result == tmp || count - tmp == result); */
    /*@ assert (tmp == count - result); */
    /*@ assert (tmp <= count); */
    /*@ assert (result >= tmp || tmp >= result); */
    /*@ assert (result >= 0 && tmp >= 0); */
    /*@ assert (result >= 0 && tmp >= 0 && count >= 0); */
    /*@ assert (result == count - tmp); */
    /*@ assert (result == count - tmp || tmp == count - result); */
    /*@ assert (result == 0 || tmp == 0 || result + tmp >= 0); */
    /*@ assert (result <= count); */
    /*@ assert (result <= count && tmp <= count); */
    /*@ assert (result + tmp == count); */
    /*@ assert (result + tmp == count || result + tmp + 1 == count); */
    /*@ assert (result + tmp <= count); */
    /*@ assert (count == result + tmp); */
    /*@ assert (count == result + tmp || count == result + tmp - 1); */
    /*@ assert (count == result + tmp || count == result + tmp + 1); */
    /*@ assert (count == 0 || result + tmp == count); */
    /*@ assert (count - tmp == result); */
    /*@ assert (count - result == tmp); */
    /*@ assert (0 <= tmp); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result && 0 <= tmp); */
    /*@ assert (0 <= count); */
    /*@ assert ((result < arr1_len && tmp < arr_len) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp])); */
    /*@ assert ((result < arr1_len && tmp < arr_len) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp])); */
    /*@ assert ((result < Array && tmp < n) ==> (result < Array && tmp < n)); */
    /*@ assert ((result < Array && tmp < n) ==> (arr1[result] >= arr[tmp] || arr1[result] <= arr[tmp])); */
    /*@ assert ((result < Array && tmp < n) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp])); */
    /*@ assert ((result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] >= arr[tmp])); */
    /*@ assert ((result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp])); */
    /*@ assert ((result < Array && tmp < n) ==> (arr1[result] != arr[tmp] || arr1[result] == arr[tmp])); */
}

/*@ requires (tmp < n ==> result < Array || tmp >= 0) && (result < Array ==> tmp < n || result >= 0) && (count - result == tmp || count - tmp == result) && (tmp == count - result) && (tmp <= count) && (result >= tmp || tmp >= result) && (result >= 0 && tmp >= 0) && (result >= 0 && tmp >= 0 && count >= 0) && (result == count - tmp) && (result == count - tmp || tmp == count - result) && (result == 0 || tmp == 0 || result + tmp >= 0) && (result <= count) && (result <= count && tmp <= count) && (result + tmp == count) && (result + tmp == count || result + tmp + 1 == count) && (result + tmp <= count) && (count == result + tmp) && (count == result + tmp || count == result + tmp - 1) && (count == result + tmp || count == result + tmp + 1) && (count == 0 || result + tmp == count) && (count - tmp == result) && (count - result == tmp) && (0 <= tmp) && (0 <= result) && (0 <= result && 0 <= tmp) && (0 <= count) && ((result < arr1_len && tmp < arr_len) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp])) && ((result < arr1_len && tmp < arr_len) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp])) && ((result < Array && tmp < n) ==> (result < Array && tmp < n)) && ((result < Array && tmp < n) ==> (arr1[result] >= arr[tmp] || arr1[result] <= arr[tmp])) && ((result < Array && tmp < n) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp])) && ((result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] >= arr[tmp])) && ((result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp])) && ((result < Array && tmp < n) ==> (arr1[result] != arr[tmp] || arr1[result] == arr[tmp]));
    assigns \nothing;
*/
void check_B_implies_A(int Array, int *arr, int *arr1, int arr1_len, int arr_len, int c, int count, int k, int n, int tmp) {
    /*@ assert (count >= 0); */
    /*@ assert (result >= 0); */
    /*@ assert (tmp >= 0); */
    /*@ assert (result + tmp == count); */
    /*@ assert (c == \at(c,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (Array == \at(Array,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (arr1_len == \at(arr1_len,Pre)); */
    /*@ assert (arr1 == \at(arr1,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k],Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre)); */
    /*@ assert ((count < \at(c,Pre)) ==> \true); */
    /*@ assert ((count < \at(c,Pre)) ==> (result >= 0)); */
    /*@ assert ((count < \at(c,Pre)) ==> (tmp >= 0)); */
    /*@ assert ((!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)))); */
}
