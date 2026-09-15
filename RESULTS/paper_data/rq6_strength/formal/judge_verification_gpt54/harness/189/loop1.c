#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */
/*@ logic integer count_min(int* a, integer lo, integer hi, integer m) =
    lo >= hi ? 0
             : count_min(a, lo, hi - 1, m) + (a[hi - 1] == m ? 1 : 0); */

/*@ requires (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (n == \at(n,Pre)) && (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)) && (count >= 1) && (\forall integer k; 0 <= k < i ==> min <= arr[k]) && (\exists integer k; 0 <= k < i && arr[k] == min);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (count > 0 ==> count <= i + 1); */
    /*@ assert (count > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min); */
    /*@ assert (n > 0 ==> min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (n > 0 ==> i <= n); */
    /*@ assert (n > 0 ==> count > 0); */
    /*@ assert (n > 0 ==> count <= n); */
    /*@ assert (n > 0 ==> count <= i + 1); */
    /*@ assert (n > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)); */
    /*@ assert (min == arr[0] || min == arr[i-1] || (\exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (min == arr[0] || min <= arr[i-1]); */
    /*@ assert (min == arr[0] || \exists integer k; 0 <= k < i && min == arr[k]); */
    /*@ assert (min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (min <= arr[i-1]); */
    /*@ assert (min <= arr[i-1] || min == arr[0]); */
    /*@ assert (min <= arr[i-1] || min <= arr[0]); */
    /*@ assert (min <= arr[i-1] || i == 1); */
    /*@ assert (min <= arr[i-1] || count == 1); */
    /*@ assert (min <= arr[i-1] || count <= i + 1); */
    /*@ assert (min <= arr[i-1] || 0 <= count); */
    /*@ assert (min <= arr[0]); */
    /*@ assert (min <= arr[0] || min <= arr[i-1]); */
    /*@ assert (min <= arr[0] || count <= i + 1); */
    /*@ assert (min <= arr[0] || 0 <= count); */
    /*@ assert (min <= arr[0] && min <= arr[i-1]); */
    /*@ assert (i == 1 ==> count == 1); */
    /*@ assert (i <= n || min <= arr[i-1]); */
    /*@ assert (i <= n || min <= arr[0]); */
    /*@ assert (i <= n || count <= i + 1); */
    /*@ assert (i <= n || 0 <= count); */
    /*@ assert (count >= 1 ==> min <= arr[i-1]); */
    /*@ assert (count >= 1 ==> count <= i); */
    /*@ assert (count >= 1 ==> \forall integer k; 0 <= k < i ==> min <= arr[k]); */
    /*@ assert (count >= 1 ==> \exists integer k; 0 <= k < i && arr[k] == min); */
    /*@ assert (count >= 1 ==> (min == arr[0] || \exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (count >= 1 ==> (\forall integer k; 0 <= k < i ==> min <= arr[k])); */
    /*@ assert (count >= 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)); */
    /*@ assert (count >= 1 ==> (\exists integer k; 0 <= k < i && arr[k] == min)); */
    /*@ assert (count >= 1 && count <= i); */
    /*@ assert (count > 1 ==> min <= arr[i-1]); */
    /*@ assert (count > 1 ==> min < arr[0] || min == arr[0]); */
    /*@ assert (count > 1 ==> count <= i); */
    /*@ assert (count > 1 ==> \exists integer k; 1 <= k < i && arr[k] == min); */
    /*@ assert (count > 1 ==> \exists integer k; 0 <= k < i && arr[k] == min); */
    /*@ assert (count > 1 ==> (\exists integer k; 0 <= k < i && arr[k] == min)); */
    /*@ assert (count > 0 ==> min <= arr[i-1]); */
    /*@ assert (count > 0 ==> count <= i); */
    /*@ assert (count > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)); */
    /*@ assert (count > 0 ==> (\exists integer k; 0 <= k < i && arr[k] == min)); */
    /*@ assert (count == 1 || count >= 1); */
    /*@ assert (count == 1 || count > 1); */
    /*@ assert (count == 1 ==> min == arr[0] || min == arr[i-1] || (\exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (count == 1 ==> min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])); */
    /*@ assert (count == 1 ==> min <= arr[i-1]); */
    /*@ assert (count == 1 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min); */
    /*@ assert (count == 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)); */
    /*@ assert (count == 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] != min || arr[k] == min)); */
    /*@ assert (count <= i); */
    /*@ assert (count <= i + 1); */
    /*@ assert (count <= i + 1 || 0 <= count); */
    /*@ assert (count <= i + 1 ==> count >= 1); */
    /*@ assert (count <= i + 1 && count >= 1); */
    /*@ assert (count < i + 1); */
    /*@ assert (\forall integer k; 0 <= k < i ==> min <= arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> min <= arr[k] || arr[k] == min); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] >= min); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (arr[k] == min ==> count >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < i && arr[k] == min ==> count >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i && arr[k] == min ==> count > 0); */
    /*@ assert (\forall integer k; 0 <= k < i && arr[k] < min ==> \false); */
    /*@ assert (\exists integer k; 0 <= k < i ==> min == arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && min == arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && arr[k] == min); */
    /*@ assert (\exists integer k; 0 <= k < i && arr[k] == min ==> count >= 1); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= count); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= count); */
    /*@ assert (0 < n ==> min <= arr[i-1] || i == 1); */
    /*@ assert (0 < n ==> min <= arr[0]); */
    /*@ assert (0 < n ==> count >= 1 && count <= i); */
    /*@ assert (0 < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= min); */
    /*@ assert (0 < n ==> 1 <= i <= n); */
    /*@ assert (0 < n ==> 1 <= count <= i); */
    /*@ assert (0 < n ==> 1 <= count <= i + 1); */
    /*@ assert (0 < n ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)); */
    /*@ assert (0 < n ==> (\exists integer k; 0 <= k < i && arr[k] == min)); */
    /*@ assert (0 < i); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert (0 < count); */
    /*@ assert ((\forall integer k; 0 <= k < i ==> min <= arr[k])); */
    /*@ assert ((\forall integer k; 0 <= k < i && arr[k] == min ==> count >= 1)); */
    /*@ assert ((\exists integer k; 0 <= k < i && arr[k] == min)); */
}

/*@ requires (count > 0 ==> count <= i + 1) && (count > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min) && (n > 0 ==> min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])) && (n > 0 ==> i <= n) && (n > 0 ==> count > 0) && (n > 0 ==> count <= n) && (n > 0 ==> count <= i + 1) && (n > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)) && (min == arr[0] || min == arr[i-1] || (\exists integer k; 0 <= k < i && min == arr[k])) && (min == arr[0] || min <= arr[i-1]) && (min == arr[0] || \exists integer k; 0 <= k < i && min == arr[k]) && (min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])) && (min <= arr[i-1]) && (min <= arr[i-1] || min == arr[0]) && (min <= arr[i-1] || min <= arr[0]) && (min <= arr[i-1] || i == 1) && (min <= arr[i-1] || count == 1) && (min <= arr[i-1] || count <= i + 1) && (min <= arr[i-1] || 0 <= count) && (min <= arr[0]) && (min <= arr[0] || min <= arr[i-1]) && (min <= arr[0] || count <= i + 1) && (min <= arr[0] || 0 <= count) && (min <= arr[0] && min <= arr[i-1]) && (i == 1 ==> count == 1) && (i <= n || min <= arr[i-1]) && (i <= n || min <= arr[0]) && (i <= n || count <= i + 1) && (i <= n || 0 <= count) && (count >= 1 ==> min <= arr[i-1]) && (count >= 1 ==> count <= i) && (count >= 1 ==> \forall integer k; 0 <= k < i ==> min <= arr[k]) && (count >= 1 ==> \exists integer k; 0 <= k < i && arr[k] == min) && (count >= 1 ==> (min == arr[0] || \exists integer k; 0 <= k < i && min == arr[k])) && (count >= 1 ==> (\forall integer k; 0 <= k < i ==> min <= arr[k])) && (count >= 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)) && (count >= 1 ==> (\exists integer k; 0 <= k < i && arr[k] == min)) && (count >= 1 && count <= i) && (count > 1 ==> min <= arr[i-1]) && (count > 1 ==> min < arr[0] || min == arr[0]) && (count > 1 ==> count <= i) && (count > 1 ==> \exists integer k; 1 <= k < i && arr[k] == min) && (count > 1 ==> \exists integer k; 0 <= k < i && arr[k] == min) && (count > 1 ==> (\exists integer k; 0 <= k < i && arr[k] == min)) && (count > 0 ==> min <= arr[i-1]) && (count > 0 ==> count <= i) && (count > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)) && (count > 0 ==> (\exists integer k; 0 <= k < i && arr[k] == min)) && (count == 1 || count >= 1) && (count == 1 || count > 1) && (count == 1 ==> min == arr[0] || min == arr[i-1] || (\exists integer k; 0 <= k < i && min == arr[k])) && (count == 1 ==> min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k])) && (count == 1 ==> min <= arr[i-1]) && (count == 1 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min) && (count == 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)) && (count == 1 ==> (\forall integer k; 0 <= k < i ==> arr[k] != min || arr[k] == min)) && (count <= i) && (count <= i + 1) && (count <= i + 1 || 0 <= count) && (count <= i + 1 ==> count >= 1) && (count <= i + 1 && count >= 1) && (count < i + 1) && (\forall integer k; 0 <= k < i ==> min <= arr[k]) && (\forall integer k; 0 <= k < i ==> min <= arr[k] || arr[k] == min) && (\forall integer k; 0 <= k < i ==> arr[k] >= min) && (\forall integer k; 0 <= k < i ==> (arr[k] == min ==> count >= 1)) && (\forall integer k; 0 <= k < i && arr[k] == min ==> count >= 1) && (\forall integer k; 0 <= k < i && arr[k] == min ==> count > 0) && (\forall integer k; 0 <= k < i && arr[k] < min ==> \false) && (\exists integer k; 0 <= k < i ==> min == arr[k]) && (\exists integer k; 0 <= k < i && min == arr[k]) && (\exists integer k; 0 <= k < i && arr[k] == min) && (\exists integer k; 0 <= k < i && arr[k] == min ==> count >= 1) && (1 <= i) && (1 <= count) && (0 <= i) && (0 <= count) && (0 < n ==> min <= arr[i-1] || i == 1) && (0 < n ==> min <= arr[0]) && (0 < n ==> count >= 1 && count <= i) && (0 < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= min) && (0 < n ==> 1 <= i <= n) && (0 < n ==> 1 <= count <= i) && (0 < n ==> 1 <= count <= i + 1) && (0 < n ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min)) && (0 < n ==> (\exists integer k; 0 <= k < i && arr[k] == min)) && (0 < i) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && (0 < count) && ((\forall integer k; 0 <= k < i ==> min <= arr[k])) && ((\forall integer k; 0 <= k < i && arr[k] == min ==> count >= 1)) && ((\exists integer k; 0 <= k < i && arr[k] == min));
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (arr_len == \at(arr_len,Pre)); */
    /*@ assert (arr == \at(arr,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre)); */
    /*@ assert (count >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i ==> min <= arr[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && arr[k] == min); */
}
