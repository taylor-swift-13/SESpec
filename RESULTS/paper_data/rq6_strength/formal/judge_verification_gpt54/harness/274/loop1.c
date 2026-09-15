#include <limits.h>

/*@ logic integer sum_even_even(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(arr, lo, hi - 1)
               + ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0); */

/*@ requires (0 <= i <= n) && (count == sum_even_even(arr, 0, i)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (count >= 0 ==> count <= i * 2147483647); */
    /*@ assert (count == 0 || count > 0 || count < 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < arr_len ==> arr[k] == arr[k])); */
    /*@ assert (i <= n || 0 <= count); */
    /*@ assert (i <= n ==> count <= count + i); */
    /*@ assert (i % 2 == 0 || i % 2 == 1); */
    /*@ assert (count >= 0 || count <= 0); */
    /*@ assert (count >= 0 || count < 0); */
    /*@ assert (count >= 0 || \true); */
    /*@ assert (count >= 0 || \exists integer k; 0 <= k < i && arr[k] < 0); */
    /*@ assert (count >= 0 ==> count + i >= 0); */
    /*@ assert (count == count); */
    /*@ assert (count == count + 0); */
    /*@ assert (count == 0 || count < 0 || count > 0); */
    /*@ assert (count == 0 || count % 2 == 0); */
    /*@ assert (count == 0 || count % 2 == 0 || count % 2 == 1); */
    /*@ assert (count == 0 || count != 0); */
    /*@ assert (count == 0 || \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0); */
    /*@ assert (count <= i * 2147483647); */
    /*@ assert (count <= count + i); */
    /*@ assert (count % 2 == 0); */
    /*@ assert (count % 2 == 0 || count % 2 == 1); */
    /*@ assert (count % 2 == 0 || count % 2 != 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] >= 0 || arr[k] < 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] == arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count + 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> arr[k] == arr[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> \true)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> count >= arr[k] || count < arr[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] == arr[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] % 2 == 0 || arr[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> \true)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] == arr[k]))); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0))); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] == arr[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] % 2 == 0 || arr[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k % 2 != 0 ==> \true)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] == arr[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i && k % 2 == 0 ==> arr[k] == arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < i && k % 2 == 0 ==> (arr[k] % 2 != 0 ==> \true)); */
    /*@ assert (\exists integer k; 0 <= k < i && k % 2 == 0 ==> count >= 0); */
    /*@ assert (\exists integer k; 0 <= k < i && k % 2 == 0 ==> \true); */
    /*@ assert (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= 0); */
    /*@ assert (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> \true); */
    /*@ assert (\exists integer k; 0 <= k < i && arr[k] % 2 == 0 ==> count % 2 == 0); */
    /*@ assert (0 <= i); */
    /*@ assert (-i * 2147483648 <= count); */
}

/*@ requires (count >= 0 ==> count <= i * 2147483647) && (count == 0 || count > 0 || count < 0) && (\forall integer k; 0 <= k < i ==> (k < arr_len ==> arr[k] == arr[k])) && (i <= n || 0 <= count) && (i <= n ==> count <= count + i) && (i % 2 == 0 || i % 2 == 1) && (count >= 0 || count <= 0) && (count >= 0 || count < 0) && (count >= 0 || \true) && (count >= 0 || \exists integer k; 0 <= k < i && arr[k] < 0) && (count >= 0 ==> count + i >= 0) && (count == count) && (count == count + 0) && (count == 0 || count < 0 || count > 0) && (count == 0 || count % 2 == 0) && (count == 0 || count % 2 == 0 || count % 2 == 1) && (count == 0 || count != 0) && (count == 0 || \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0) && (count <= i * 2147483647) && (count <= count + i) && (count % 2 == 0) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == 0 || count % 2 != 0) && (\forall integer k; 0 <= k < i ==> arr[k] >= 0 || arr[k] < 0) && (\forall integer k; 0 <= k < i ==> arr[k] == arr[k]) && (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count)) && (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count + 0)) && (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> arr[k] == arr[k])) && (\forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> \true)) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> count >= arr[k] || count < arr[k])) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] == arr[k])) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] % 2 == 0 || arr[k] % 2 != 0)) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> \true)) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] == arr[k]))) && (\forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0))) && (\forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] == arr[k])) && (\forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] % 2 == 0 || arr[k] % 2 != 0)) && (\forall integer k; 0 <= k < i ==> (k % 2 != 0 ==> \true)) && (\forall integer k; 0 <= k < i ==> (arr[k] == arr[k])) && (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0)) && (\forall integer k; 0 <= k < i && k % 2 == 0 ==> arr[k] == arr[k]) && (\forall integer k; 0 <= k < i && k % 2 == 0 ==> (arr[k] % 2 != 0 ==> \true)) && (\exists integer k; 0 <= k < i && k % 2 == 0 ==> count >= 0) && (\exists integer k; 0 <= k < i && k % 2 == 0 ==> \true) && (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= arr[k]) && (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= 0) && (\exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> \true) && (\exists integer k; 0 <= k < i && arr[k] % 2 == 0 ==> count % 2 == 0) && (0 <= i) && (-i * 2147483648 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (0 <= i <= n); */
    /*@ assert (count == sum_even_even(arr, 0, i)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre)); */
}
