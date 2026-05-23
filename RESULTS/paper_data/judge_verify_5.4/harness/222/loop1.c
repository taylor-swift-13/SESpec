#include <limits.h>

/*@ logic integer odd_with_index(int* a, integer idx, integer lo, integer hi) =
    hi <= lo ? 0 :
    odd_with_index(a, idx, lo, hi - 1) +
      ((((a[idx] ^ a[hi - 1]) % 2) == 1) ? 1 : 0); */
/*@ logic integer paircount_prefix(int* a, integer i, integer n) =
    i <= 0 ? 0 :
    paircount_prefix(a, i - 1, n) +
      odd_with_index(a, i - 1, i, n); */

/*@ requires (0 <= index <= offset) && (result >= 0) && (result == paircount_prefix(arr, index, offset)) && (\forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre)) && (\forall integer k; 0 <= k < offset ==> 0 <= arr[k] <= 100) && (index <= offset) && (offset == \at(arr_len,Pre)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int *arr_len, int i, int index, int j, int k, int l, int n, int p, int q) {
    /*@ assert (\forall integer p; 0 <= p < index ==> result >= 0); */
    /*@ assert (\forall integer p; 0 <= p < index ==> p < offset); */
    /*@ assert (\forall integer p; 0 <= p < index ==> p < arr_len); */
    /*@ assert (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> q < arr_len); */
    /*@ assert (\forall integer k; index <= k < offset ==> k < arr_len); */
    /*@ assert (\forall integer i; 0 <= i < index ==> i < arr_len); */
    /*@ assert (result <= arr_len * arr_len || index <= arr_len); */
    /*@ assert (offset == arr_len); */
    /*@ assert (index <= offset || result <= arr_len * arr_len); */
    /*@ assert (index < offset ==> index < arr_len); */
    /*@ assert (index < offset ==> index + 1 <= offset); */
    /*@ assert (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> (arr[p] ^ arr[q]) % 2 == 1 ==> result >= 0); */
    /*@ assert (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> ((arr[p] ^ arr[q]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer p; 0 <= p < index ==> \exists integer q; p < q < offset ==> q < offset); */
    /*@ assert (\forall integer p; 0 <= p < index ==> 0 <= p < arr_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < offset ==> ((arr[k] ^ arr[l]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \exists integer l; k < l < offset ==> l < offset); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= result); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= k < arr_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= arr_len); */
    /*@ assert (\forall integer i; 0 <= i < index ==> result >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> i < offset); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> j < offset); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> j < arr_len); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> 0 <= result); */
    /*@ assert (\forall integer i; 0 <= i < index ==> 0 <= result); */
    /*@ assert (\forall integer i; 0 <= i < index ==> 0 <= i < arr_len); */
    /*@ assert (\forall integer i; 0 <= i < index ==> 0 <= arr_len); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
}

/*@ requires (\forall integer p; 0 <= p < index ==> result >= 0) && (\forall integer p; 0 <= p < index ==> p < offset) && (\forall integer p; 0 <= p < index ==> p < arr_len) && (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> q < arr_len) && (\forall integer k; index <= k < offset ==> k < arr_len) && (\forall integer i; 0 <= i < index ==> i < arr_len) && (result <= arr_len * arr_len || index <= arr_len) && (offset == arr_len) && (index <= offset || result <= arr_len * arr_len) && (index < offset ==> index < arr_len) && (index < offset ==> index + 1 <= offset) && (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> (arr[p] ^ arr[q]) % 2 == 1 ==> result >= 0) && (\forall integer p; 0 <= p < index ==> \forall integer q; p < q < offset ==> ((arr[p] ^ arr[q]) % 2 == 1) ==> result >= 0) && (\forall integer p; 0 <= p < index ==> \exists integer q; p < q < offset ==> q < offset) && (\forall integer p; 0 <= p < index ==> 0 <= p < arr_len) && (\forall integer k; 0 <= k < index ==> result >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < offset ==> ((arr[k] ^ arr[l]) % 2 == 1) ==> result >= 0) && (\forall integer k; 0 <= k < index ==> \exists integer l; k < l < offset ==> l < offset) && (\forall integer k; 0 <= k < index ==> 0 <= result) && (\forall integer k; 0 <= k < index ==> 0 <= k < arr_len) && (\forall integer k; 0 <= k < index ==> 0 <= arr_len) && (\forall integer i; 0 <= i < index ==> result >= 0) && (\forall integer i; 0 <= i < index ==> i < offset) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0) && (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> j < offset) && (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> j < arr_len) && (\forall integer i; 0 <= i < index ==> \exists integer j; i < j < offset ==> 0 <= result) && (\forall integer i; 0 <= i < index ==> 0 <= result) && (\forall integer i; 0 <= i < index ==> 0 <= i < arr_len) && (\forall integer i; 0 <= i < index ==> 0 <= arr_len) && (\forall integer i, j; 0 <= i < index && i < j < offset ==> ((arr[i] ^ arr[j]) % 2 == 1) ==> result >= 0) && (0 <= result) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int *arr_len, int i, int index, int j, int k, int l, int n, int p, int q) {
    /*@ assert (0 <= index <= offset); */
    /*@ assert (result >= 0); */
    /*@ assert (result == paircount_prefix(arr, index, offset)); */
    /*@ assert (\forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre)); */
    /*@ assert (\forall integer k; 0 <= k < offset ==> 0 <= arr[k] <= 100); */
    /*@ assert (index <= offset); */
    /*@ assert (offset == \at(arr_len,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
}
