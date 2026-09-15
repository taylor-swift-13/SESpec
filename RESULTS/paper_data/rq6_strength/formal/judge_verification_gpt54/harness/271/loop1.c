#include <limits.h>

/*@ logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1)); */

/*@ requires (0 <= i) && (0 <= count <= i) && (count == odd_count(arr, 0, i)) && (count == 0 ==> result == 0) && (count > 0 ==> result == 0 || result % 2 != 0) && (count % 2 != 0 ==> result == last_odd(arr, 0, i)) && (arrSize == \at(arrSize,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arrSize, int arr_len, int count, int i, int j, int k) {
    /*@ assert (result == 0 || result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (result == 0 || result % 2 != 0); */
    /*@ assert (result == 0 || result != 0); */
    /*@ assert (result == 0 || count >= 1); */
    /*@ assert (result == 0 || arrSize > 0); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < i ==> arr[k] == result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result); */
    /*@ assert (result == 0 || (result % 2 != 0)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result)); */
    /*@ assert (result == 0 || (\exists integer j; 0 <= j < i && arr[j] == result && arr[j] % 2 != 0)); */
    /*@ assert (result != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (result != 0 ==> result % 2 != 0); */
    /*@ assert (result != 0 ==> arr[i-1] == result || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0); */
    /*@ assert (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result); */
    /*@ assert (result != 0 ==> (result % 2 != 0)); */
    /*@ assert (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)); */
    /*@ assert (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result)); */
    /*@ assert (count > 0 ==> result == 0 || result % 2 != 0); */
    /*@ assert (count > 0 ==> result == 0 || result != 0); */
    /*@ assert (count > 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (count > 0 ==> result != 0); */
    /*@ assert (count > 0 ==> result != 0 || result == arr[i-1]); */
    /*@ assert (count > 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (count == i || count <= i); */
    /*@ assert (count == i || count < i); */
    /*@ assert (count == 0 || result != 0); */
    /*@ assert (count == 0 || count >= 1); */
    /*@ assert (count == 0 || count > 0); */
    /*@ assert (count == 0 || count % 2 == 1 || count % 2 == 0); */
    /*@ assert (count == 0 ==> result == 0); */
    /*@ assert (count <= i); */
    /*@ assert (count <= i + 1); */
    /*@ assert (count <= i + 1 || i <= arrSize); */
    /*@ assert (count <= i + 1 || count <= arrSize); */
    /*@ assert (count < i + 1); */
    /*@ assert (count % 2 == i % 2 || count % 2 != i % 2); */
    /*@ assert (count % 2 == 0 || count % 2 == 1); */
    /*@ assert (count % 2 == 0 || count % 2 != 0); */
    /*@ assert (count % 2 == 0 ==> result == 0 || result % 2 != 0); */
    /*@ assert (count % 2 == 0 ==> result == 0 || result != 0); */
    /*@ assert (count % 2 == 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (count % 2 == 0 ==> (result == 0 || result % 2 != 0)); */
    /*@ assert (count % 2 == 0 ==> (result == 0 || result != 0)); */
    /*@ assert (count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])); */
    /*@ assert (count % 2 <= 1); */
    /*@ assert (count % 2 != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (count % 2 != 0 ==> result == arr[i-1] || (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (count % 2 != 0 ==> result != 0); */
    /*@ assert (count % 2 != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (count % 2 != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (count != 0 ==> result == 0 || result != 0); */
    /*@ assert (count != 0 ==> result != 0); */
    /*@ assert (count != 0 ==> result != 0 || result == arr[i-1]); */
    /*@ assert (count != 0 ==> result != 0 || \exists integer k; 0 <= k < i && arr[k] == result); */
    /*@ assert (count != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] % 2 == 0 || arr[k] % 2 != 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> count >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> \exists integer j; 0 <= j <= k && arr[j] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> count >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> (count >= 1)); */
    /*@ assert (\exists integer k; 0 <= k < i ==> arr[k] == result); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= count); */
    /*@ assert (0 <= count % 2); */
    /*@ assert ((result != 0) ==> (\exists integer k; 0 <= k < i && arr[k] == result)); */
    /*@ assert ((count % 2 == 0) ==> (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result))); */
    /*@ assert ((count % 2 != 0) ==> result != 0); */
    /*@ assert ((count % 2 != 0) ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)); */
    /*@ assert ((count % 2 != 0) ==> (result != 0)); */
    /*@ assert ((count % 2 != 0) ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0))); */
}

/*@ requires (result == 0 || result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result) && (result == 0 || result % 2 != 0) && (result == 0 || result != 0) && (result == 0 || count >= 1) && (result == 0 || arrSize > 0) && (result == 0 || \exists integer k; 0 <= k < i ==> arr[k] == result) && (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result) && (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0) && (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result) && (result == 0 || (result % 2 != 0)) && (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result)) && (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)) && (result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])) && (result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result)) && (result == 0 || (\exists integer j; 0 <= j < i && arr[j] == result && arr[j] % 2 != 0)) && (result != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result) && (result != 0 ==> result % 2 != 0) && (result != 0 ==> arr[i-1] == result || \exists integer k; 0 <= k < i && arr[k] == result) && (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result) && (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0) && (result != 0 ==> \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result) && (result != 0 ==> (result % 2 != 0)) && (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)) && (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)) && (result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result)) && (count > 0 ==> result == 0 || result % 2 != 0) && (count > 0 ==> result == 0 || result != 0) && (count > 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result) && (count > 0 ==> result != 0) && (count > 0 ==> result != 0 || result == arr[i-1]) && (count > 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result)) && (count == i || count <= i) && (count == i || count < i) && (count == 0 || result != 0) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 || count % 2 == 1 || count % 2 == 0) && (count == 0 ==> result == 0) && (count <= i) && (count <= i + 1) && (count <= i + 1 || i <= arrSize) && (count <= i + 1 || count <= arrSize) && (count < i + 1) && (count % 2 == i % 2 || count % 2 != i % 2) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == 0 || count % 2 != 0) && (count % 2 == 0 ==> result == 0 || result % 2 != 0) && (count % 2 == 0 ==> result == 0 || result != 0) && (count % 2 == 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result) && (count % 2 == 0 ==> (result == 0 || result % 2 != 0)) && (count % 2 == 0 ==> (result == 0 || result != 0)) && (count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result)) && (count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])) && (count % 2 <= 1) && (count % 2 != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result) && (count % 2 != 0 ==> result == arr[i-1] || (\exists integer k; 0 <= k < i && arr[k] == result)) && (count % 2 != 0 ==> result != 0) && (count % 2 != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result) && (count % 2 != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)) && (count != 0 ==> result == 0 || result != 0) && (count != 0 ==> result != 0) && (count != 0 ==> result != 0 || result == arr[i-1]) && (count != 0 ==> result != 0 || \exists integer k; 0 <= k < i && arr[k] == result) && (count != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result)) && (\forall integer k; 0 <= k < i ==> arr[k] % 2 == 0 || arr[k] % 2 != 0) && (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0)) && (\forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> count >= 1)) && (\forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> \exists integer j; 0 <= j <= k && arr[j] % 2 != 0)) && (\forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> count >= 1) && (\forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> (count >= 1)) && (\exists integer k; 0 <= k < i ==> arr[k] == result) && (0 <= i) && (0 <= count) && (0 <= count % 2) && ((result != 0) ==> (\exists integer k; 0 <= k < i && arr[k] == result)) && ((count % 2 == 0) ==> (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result))) && ((count % 2 != 0) ==> result != 0) && ((count % 2 != 0) ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0)) && ((count % 2 != 0) ==> (result != 0)) && ((count % 2 != 0) ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k])) && ((\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0)));
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arrSize, int arr_len, int count, int i, int j, int k) {
    /*@ assert (0 <= i); */
    /*@ assert (0 <= count <= i); */
    /*@ assert (count == odd_count(arr, 0, i)); */
    /*@ assert (count == 0 ==> result == 0); */
    /*@ assert (count > 0 ==> result == 0 || result % 2 != 0); */
    /*@ assert (count % 2 != 0 ==> result == last_odd(arr, 0, i)); */
    /*@ assert (arrSize == \at(arrSize,Pre)); */
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k], Pre)); */
}
