#include <limits.h>

/*@ requires (max1 >= arr[0]) && (\forall integer j; 0 <= j < i ==> arr[j] <= max1) && ((i < \at(n,Pre)) ==> (max1 >= arr[0])) && ((i < \at(n,Pre)) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))) && ((!(i < \at(n,Pre))) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))) && (k == \at(k,Pre)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int i, int j, int k, int max1, int n) {
    /*@ assert (max1 >= arr[i-1] || i == 1); */
    /*@ assert (max1 == arr[0] || max1 >= arr[i-1]); */
    /*@ assert (max1 == arr[0] || max1 >= arr[0]); */
    /*@ assert (max1 == arr[0] || max1 > arr[0]); */
    /*@ assert (max1 == arr[0] || \exists integer j; 0 <= j < i && max1 == arr[j]); */
    /*@ assert (max1 == arr[0] || (\exists integer j; 0 <= j < i && max1 == arr[j])); */
    /*@ assert (i >= 1 ==> max1 >= arr[i-1]); */
    /*@ assert (i == 1 ==> max1 == arr[0]); */
    /*@ assert (arr[0] <= max1); */
    /*@ assert (arr[0] <= max1 && (\forall integer j; 0 <= j < i ==> arr[j] <= max1)); */
    /*@ assert (\forall integer j; 1 <= j < i ==> max1 >= arr[j]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> max1 >= arr[j]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> max1 == arr[j] || max1 >= arr[j]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> max1 == arr[j] || max1 > arr[j]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> arr[j] <= max1); */
    /*@ assert (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) >= 0); */
    /*@ assert (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0 || (max1 - arr[j]) % k != 0); */
    /*@ assert (\exists integer j; 0 <= j < i ==> max1 == arr[j]); */
    /*@ assert (\exists integer j; 0 <= j < i && max1 == arr[j]); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= i); */
    /*@ assert ((\exists integer j; 0 <= j < i && max1 == arr[j]) || max1 == arr[0]); */
}

/*@ requires (max1 >= arr[i-1] || i == 1) && (max1 == arr[0] || max1 >= arr[i-1]) && (max1 == arr[0] || max1 >= arr[0]) && (max1 == arr[0] || max1 > arr[0]) && (max1 == arr[0] || \exists integer j; 0 <= j < i && max1 == arr[j]) && (max1 == arr[0] || (\exists integer j; 0 <= j < i && max1 == arr[j])) && (i >= 1 ==> max1 >= arr[i-1]) && (i == 1 ==> max1 == arr[0]) && (arr[0] <= max1) && (arr[0] <= max1 && (\forall integer j; 0 <= j < i ==> arr[j] <= max1)) && (\forall integer j; 1 <= j < i ==> max1 >= arr[j]) && (\forall integer j; 0 <= j < i ==> max1 >= arr[j]) && (\forall integer j; 0 <= j < i ==> max1 == arr[j] || max1 >= arr[j]) && (\forall integer j; 0 <= j < i ==> max1 == arr[j] || max1 > arr[j]) && (\forall integer j; 0 <= j < i ==> arr[j] <= max1) && (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) >= 0) && (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0 || (max1 - arr[j]) % k != 0) && (\exists integer j; 0 <= j < i ==> max1 == arr[j]) && (\exists integer j; 0 <= j < i && max1 == arr[j]) && (1 <= i) && (0 <= i) && ((\exists integer j; 0 <= j < i && max1 == arr[j]) || max1 == arr[0]);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int i, int j, int k, int max1, int n) {
    /*@ assert (max1 >= arr[0]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> arr[j] <= max1); */
    /*@ assert ((i < \at(n,Pre)) ==> (max1 >= arr[0])); */
    /*@ assert ((i < \at(n,Pre)) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))); */
    /*@ assert ((!(i < \at(n,Pre))) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)))); */
    /*@ assert (k == \at(k,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre)); */
}
