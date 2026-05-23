#include <limits.h>

/*@ logic integer prod{L}(int *a, integer l, integer u) =
  (l >= u) ? 1 : ((integer)a[l] * prod(a, l + 1, u)); */
/*@ logic integer suffixsum(int *a, integer i, integer n) =
  (i >= n) ? 0 : prod(a, i, n) + suffixsum(a, i + 1, n); */
/*@ logic integer contrib(int *a, integer i, integer j) =
  (j <= i) ? 0 : contrib(a, i, j - 1) + prod(a, i, j - 1); */
/*@ logic integer row_contrib_sum(int *a, integer i, integer n) =
  (i >= n) ? 0 : contrib(a, i, n) + row_contrib_sum(a, i + 1, n); */

/*@ requires (0 <= i <= n) && (0 <= sum) && (\forall integer k; 0 <= k < i ==> 0 <= arr[k] <= 100);
    assigns \nothing;
*/
void check_A_implies_B(int *arr, int i, int k, int n, int p, int t) {
    /*@ assert (sum >= 0 || sum <= 0); */
    /*@ assert (sum == sum); */
    /*@ assert (sum == sum + 0); */
    /*@ assert (sum == 0 || sum != 0); */
    /*@ assert (i < n ==> sum == sum); */
    /*@ assert (i < n ==> sum == sum + 0); */
    /*@ assert (i < n ==> i + 1 > 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] == arr[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] != 0 || arr[k] == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> arr[k] != 0 ==> sum >= 0 || sum <= 0); */
    /*@ assert (\exists integer t; t == sum); */
    /*@ assert (\exists integer t; t == sum + i); */
    /*@ assert (\exists integer t; t == i); */
    /*@ assert (\exists integer p; p == sum); */
    /*@ assert (\exists integer p; p == sum + i); */
    /*@ assert (\exists integer p; p == i); */
    /*@ assert (0 <= sum || sum <= 0); */
    /*@ assert (0 <= i); */
}

/*@ requires (sum >= 0 || sum <= 0) && (sum == sum) && (sum == sum + 0) && (sum == 0 || sum != 0) && (i < n ==> sum == sum) && (i < n ==> sum == sum + 0) && (i < n ==> i + 1 > 0) && (\forall integer k; 0 <= k < i ==> arr[k] == arr[k]) && (\forall integer k; 0 <= k < i ==> arr[k] != 0 || arr[k] == 0) && (\forall integer k; 0 <= k < i ==> arr[k] != 0 ==> sum >= 0 || sum <= 0) && (\exists integer t; t == sum) && (\exists integer t; t == sum + i) && (\exists integer t; t == i) && (\exists integer p; p == sum) && (\exists integer p; p == sum + i) && (\exists integer p; p == i) && (0 <= sum || sum <= 0) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *arr, int i, int k, int n, int p, int t) {
    /*@ assert (0 <= i <= n); */
    /*@ assert (0 <= sum); */
    /*@ assert (\forall integer k; 0 <= k < i ==> 0 <= arr[k] <= 100); */
}
