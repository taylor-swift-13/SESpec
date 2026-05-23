#include <limits.h>

/*@ logic integer odd_with_index(int* a, integer idx, integer lo, integer hi) =
    hi <= lo ? 0 :
    odd_with_index(a, idx, lo, hi - 1) +
      ((((a[idx] ^ a[hi - 1]) % 2) == 1) ? 1 : 0); */
/*@ logic integer paircount_prefix(int* a, integer i, integer n) =
    i <= 0 ? 0 :
    paircount_prefix(a, i - 1, n) +
      odd_with_index(a, i - 1, i, n); */

/*@ requires (c >= index + 1 && c <= offset) && (result >= 0) && (result == paircount_prefix(arr, index, offset) + odd_with_index(arr, index, index + 1, c)) && (\forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int *arr_len, int c, int i, int index, int j, int k, int l, int t) {
    /*@ assert (offset == arr_len); */
    /*@ assert (index <= offset); */
    /*@ assert (index <= c); */
    /*@ assert (index <= c); */
    /*@ assert (index <= c || result <= arr_len * arr_len); */
    /*@ assert (index <= c || index <= arr_len); */
    /*@ assert (index <= arr_len); */
    /*@ assert (index <= arr_len || result <= arr_len * arr_len); */
    /*@ assert (index < offset); */
    /*@ assert (index < offset ==> index < c); */
    /*@ assert (index < offset ==> index < c || c == index + 1); */
    /*@ assert (index < offset ==> index < arr_len); */
    /*@ assert (index < offset ==> index + 1 <= offset); */
    /*@ assert (index < offset ==> index + 1 <= c); */
    /*@ assert (index < offset ==> c >= index + 1); */
    /*@ assert (index < offset ==> c > index); */
    /*@ assert (index < offset ==> c == index + 1 || c > index + 1); */
    /*@ assert (index < offset ==> c <= offset); */
    /*@ assert (index < offset ==> c <= arr_len); */
    /*@ assert (index < c); */
    /*@ assert (index < c); */
    /*@ assert (index < c || result <= arr_len * arr_len); */
    /*@ assert (index < c || index <= c); */
    /*@ assert (index < c || index <= arr_len); */
    /*@ assert (index < c || c == index + 1); */
    /*@ assert (index < c ==> index < arr_len); */
    /*@ assert (index < arr_len); */
    /*@ assert (index + 1 <= c); */
    /*@ assert (index + 1 <= c || c == index + 1); */
    /*@ assert (c == index + 1 || c >= index + 1); */
    /*@ assert (c == index + 1 || c > index + 1); */
    /*@ assert (c <= offset); */
    /*@ assert (c <= arr_len); */
    /*@ assert (\forall integer t; index <= t < c ==> t < offset); */
    /*@ assert (\forall integer t; index <= t < c ==> c <= offset); */
    /*@ assert (\forall integer t; index <= t < c ==> 0 <= result); */
    /*@ assert (\forall integer t; index <= t < c ==> ((arr[index] ^ arr[t]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer t; index < t < c ==> t < arr_len); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> t < offset); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> t < arr_len); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> result >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> c <= offset); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> 0 <= result); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> (arr[index] ^ arr[t]) % 2 == 1 ==> result >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> ((arr[index] ^ arr[t]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; index <= k < c ==> k < offset); */
    /*@ assert (\forall integer k; index <= k < c ==> k < arr_len); */
    /*@ assert (\forall integer k; index <= k < c ==> index < offset); */
    /*@ assert (\forall integer k; index <= k < c ==> c <= arr_len); */
    /*@ assert (\forall integer k; index <= k < c ==> (arr[index] ^ arr[k]) % 2 == 1 ==> result >= 0); */
    /*@ assert (\forall integer k; index <= k < c ==> ((arr[index] ^ arr[k]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> result >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < offset); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < arr_len); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> c <= offset); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> 0 <= result); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> ((arr[index] ^ arr[k]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < offset ==> ((arr[k] ^ arr[l]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer j; k < j < offset ==> ((arr[k] ^ arr[j]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= result); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> 0 <= result); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0); */
    /*@ assert (1 <= c - index); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= c); */
}

/*@ requires (offset == arr_len) && (index <= offset) && (index <= c) && (index <= c) && (index <= c || result <= arr_len * arr_len) && (index <= c || index <= arr_len) && (index <= arr_len) && (index <= arr_len || result <= arr_len * arr_len) && (index < offset) && (index < offset ==> index < c) && (index < offset ==> index < c || c == index + 1) && (index < offset ==> index < arr_len) && (index < offset ==> index + 1 <= offset) && (index < offset ==> index + 1 <= c) && (index < offset ==> c >= index + 1) && (index < offset ==> c > index) && (index < offset ==> c == index + 1 || c > index + 1) && (index < offset ==> c <= offset) && (index < offset ==> c <= arr_len) && (index < c) && (index < c) && (index < c || result <= arr_len * arr_len) && (index < c || index <= c) && (index < c || index <= arr_len) && (index < c || c == index + 1) && (index < c ==> index < arr_len) && (index < arr_len) && (index + 1 <= c) && (index + 1 <= c || c == index + 1) && (c == index + 1 || c >= index + 1) && (c == index + 1 || c > index + 1) && (c <= offset) && (c <= arr_len) && (\forall integer t; index <= t < c ==> t < offset) && (\forall integer t; index <= t < c ==> c <= offset) && (\forall integer t; index <= t < c ==> 0 <= result) && (\forall integer t; index <= t < c ==> ((arr[index] ^ arr[t]) % 2 == 1) ==> result >= 0) && (\forall integer t; index < t < c ==> t < arr_len) && (\forall integer t; index + 1 <= t < c ==> t < offset) && (\forall integer t; index + 1 <= t < c ==> t < arr_len) && (\forall integer t; index + 1 <= t < c ==> result >= 0) && (\forall integer t; index + 1 <= t < c ==> c <= offset) && (\forall integer t; index + 1 <= t < c ==> 0 <= result) && (\forall integer t; index + 1 <= t < c ==> (arr[index] ^ arr[t]) % 2 == 1 ==> result >= 0) && (\forall integer t; index + 1 <= t < c ==> ((arr[index] ^ arr[t]) % 2 == 1) ==> result >= 0) && (\forall integer k; index <= k < c ==> k < offset) && (\forall integer k; index <= k < c ==> k < arr_len) && (\forall integer k; index <= k < c ==> index < offset) && (\forall integer k; index <= k < c ==> c <= arr_len) && (\forall integer k; index <= k < c ==> (arr[index] ^ arr[k]) % 2 == 1 ==> result >= 0) && (\forall integer k; index <= k < c ==> ((arr[index] ^ arr[k]) % 2 == 1) ==> result >= 0) && (\forall integer k; index + 1 <= k < c ==> result >= 0) && (\forall integer k; index + 1 <= k < c ==> k < offset) && (\forall integer k; index + 1 <= k < c ==> k < arr_len) && (\forall integer k; index + 1 <= k < c ==> c <= offset) && (\forall integer k; index + 1 <= k < c ==> 0 <= result) && (\forall integer k; index + 1 <= k < c ==> ((arr[index] ^ arr[k]) % 2 == 1) ==> result >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < offset ==> ((arr[k] ^ arr[l]) % 2 == 1) ==> result >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer j; k < j < offset ==> ((arr[k] ^ arr[j]) % 2 == 1) ==> result >= 0) && (\forall integer k; 0 <= k < index ==> 0 <= result) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0) && (\forall integer i; 0 <= i < index ==> 0 <= result) && (\forall integer i, j; 0 <= i < index && i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0) && (1 <= c - index) && (0 <= result) && (0 <= index) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int *arr_len, int c, int i, int index, int j, int k, int l, int t) {
    /*@ assert (c >= index + 1 && c <= offset); */
    /*@ assert (result >= 0); */
    /*@ assert (result == paircount_prefix(arr, index, offset) + odd_with_index(arr, index, index + 1, c)); */
    /*@ assert (\forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre)); */
}
