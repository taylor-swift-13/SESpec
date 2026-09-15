#include <limits.h>

/*@ requires (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0) && (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre)) && (k == \at(k,Pre)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int i, int j, int k, int max1, int n, int res, int t) {
    /*@ assert (res <= i * (max1 / k + 1) || i <= n); */
    /*@ assert (res % 1 == 0); */
    /*@ assert (i == 0 ==> res == 0); */
    /*@ assert (i <= n || 0 <= res); */
    /*@ assert (\forall integer j; 0 <= j < i ==> max1 >= arr[j]); */
    /*@ assert (\forall integer j; 0 <= j < i ==> arr[j] <= max1); */
    /*@ assert (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) >= 0); */
    /*@ assert (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0); */
    /*@ assert (\forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k == 0)); */
    /*@ assert (\forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k == 0) || ((max1 - arr[j]) % k != 0)); */
    /*@ assert (\exists integer t; res == t); */
    /*@ assert (\exists integer t; res == t * 1); */
    /*@ assert (0 <= res || i <= n); */
    /*@ assert (0 <= i); */
}

/*@ requires (res <= i * (max1 / k + 1) || i <= n) && (res % 1 == 0) && (i == 0 ==> res == 0) && (i <= n || 0 <= res) && (\forall integer j; 0 <= j < i ==> max1 >= arr[j]) && (\forall integer j; 0 <= j < i ==> arr[j] <= max1) && (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) >= 0) && (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0) && (\forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k == 0)) && (\forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k == 0) || ((max1 - arr[j]) % k != 0)) && (\exists integer t; res == t) && (\exists integer t; res == t * 1) && (0 <= res || i <= n) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int i, int j, int k, int max1, int n, int res, int t) {
    /*@ assert (\forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0); */
    /*@ assert (\forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre)); */
    /*@ assert (k == \at(k,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
}
