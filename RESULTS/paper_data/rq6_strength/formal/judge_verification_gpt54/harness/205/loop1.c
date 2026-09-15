#include <limits.h>

/*@ requires (args_len >= 0 ==> 0 <= ret <= args_len) && (arr_len >= 0 ==> 0 <= len <= arr_len) && (ret + len >= 0) && (ret >= 0 && len >= 0) && ((ret < args_len && len < arr_len) ==> ret + len < args_len + arr_len) && ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= \at(args_len,Pre) && 0 <= len <= \at(arr_len,Pre))) && ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= args_len)) && ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= len <= arr_len)) && ((!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))) && (Array == \at(Array,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int Array, int *args, int args_len, int *arr, int arr_len, int k, int len, int *ret) {
    /*@ assert (ret < args_len && len < arr_len ==> ret + len >= 0); */
    /*@ assert (ret >= 0 ==> ret + len >= len); */
    /*@ assert (ret >= 0 && len >= 0); */
    /*@ assert (ret == len ==> ret + len == 2 * ret); */
    /*@ assert (ret == len ==> 0 <= ret); */
    /*@ assert (ret == 0 || len == 0 || ret + len >= 0); */
    /*@ assert (ret == 0 || len == 0 || ret + len > 0); */
    /*@ assert (ret == 0 ==> len == 0 || ret + len >= 0); */
    /*@ assert (ret <= ret + len); */
    /*@ assert (ret <= ret + len || ret - len <= args_len); */
    /*@ assert (ret <= ret + len || len <= ret + len); */
    /*@ assert (ret <= ret + len && len <= ret + len); */
    /*@ assert (ret <= len + args_len || ret <= ret + len); */
    /*@ assert (ret <= args_len || ret <= ret + len); */
    /*@ assert (ret <= args_len || len <= ret + len); */
    /*@ assert (ret <= args_len ==> ret <= ret + len); */
    /*@ assert (ret < args_len ==> len < arr_len || ret <= args_len); */
    /*@ assert (ret < args_len ==> len < arr_len || ret < args_len); */
    /*@ assert (ret < args_len ==> len < arr_len || ret + len >= 0); */
    /*@ assert (ret < args_len && len < arr_len ==> ret + len < args_len + arr_len); */
    /*@ assert (ret - len <= ret); */
    /*@ assert (ret + len == 0 ==> ret == 0 && len == 0); */
    /*@ assert (ret + len <= args_len + arr_len || ret <= ret + len); */
    /*@ assert (ret + len <= args_len + arr_len || len <= ret + len); */
    /*@ assert (len <= ret + len); */
    /*@ assert (len <= ret + len || ret <= ret + len); */
    /*@ assert (len <= ret + len || ret <= len + args_len); */
    /*@ assert (len <= ret + len || ret - len <= args_len); */
    /*@ assert (len <= ret + arr_len || ret <= ret + len); */
    /*@ assert (len <= ret + arr_len || len <= ret + len); */
    /*@ assert (len <= arr_len || ret <= ret + len); */
    /*@ assert (len <= arr_len || len <= ret + len); */
    /*@ assert (len <= arr_len ==> len <= ret + len); */
    /*@ assert (len < arr_len ==> ret < args_len || len <= arr_len); */
    /*@ assert (len < arr_len ==> ret < args_len || len < arr_len); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= ret + len); */
    /*@ assert (0 <= len); */
}

/*@ requires (ret < args_len && len < arr_len ==> ret + len >= 0) && (ret >= 0 ==> ret + len >= len) && (ret >= 0 && len >= 0) && (ret == len ==> ret + len == 2 * ret) && (ret == len ==> 0 <= ret) && (ret == 0 || len == 0 || ret + len >= 0) && (ret == 0 || len == 0 || ret + len > 0) && (ret == 0 ==> len == 0 || ret + len >= 0) && (ret <= ret + len) && (ret <= ret + len || ret - len <= args_len) && (ret <= ret + len || len <= ret + len) && (ret <= ret + len && len <= ret + len) && (ret <= len + args_len || ret <= ret + len) && (ret <= args_len || ret <= ret + len) && (ret <= args_len || len <= ret + len) && (ret <= args_len ==> ret <= ret + len) && (ret < args_len ==> len < arr_len || ret <= args_len) && (ret < args_len ==> len < arr_len || ret < args_len) && (ret < args_len ==> len < arr_len || ret + len >= 0) && (ret < args_len && len < arr_len ==> ret + len < args_len + arr_len) && (ret - len <= ret) && (ret + len == 0 ==> ret == 0 && len == 0) && (ret + len <= args_len + arr_len || ret <= ret + len) && (ret + len <= args_len + arr_len || len <= ret + len) && (len <= ret + len) && (len <= ret + len || ret <= ret + len) && (len <= ret + len || ret <= len + args_len) && (len <= ret + len || ret - len <= args_len) && (len <= ret + arr_len || ret <= ret + len) && (len <= ret + arr_len || len <= ret + len) && (len <= arr_len || ret <= ret + len) && (len <= arr_len || len <= ret + len) && (len <= arr_len ==> len <= ret + len) && (len < arr_len ==> ret < args_len || len <= arr_len) && (len < arr_len ==> ret < args_len || len < arr_len) && (0 <= ret) && (0 <= ret + len) && (0 <= len);
    assigns \nothing;
*/
void check_B_implies_A(int Array, int *args, int args_len, int *arr, int arr_len, int k, int len, int *ret) {
    /*@ assert (args_len >= 0 ==> 0 <= ret <= args_len); */
    /*@ assert (arr_len >= 0 ==> 0 <= len <= arr_len); */
    /*@ assert (ret + len >= 0); */
    /*@ assert (ret >= 0 && len >= 0); */
    /*@ assert ((ret < args_len && len < arr_len) ==> ret + len < args_len + arr_len); */
    /*@ assert ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= \at(args_len,Pre) && 0 <= len <= \at(arr_len,Pre))); */
    /*@ assert ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= args_len)); */
    /*@ assert ((0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= len <= arr_len)); */
    /*@ assert ((!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))); */
    /*@ assert (Array == \at(Array,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
}
