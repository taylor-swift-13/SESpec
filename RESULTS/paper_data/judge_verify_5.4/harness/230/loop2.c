#include <limits.h>

/*@ logic integer mismatch_suffix(int* pairs, integer i, integer lo, integer hi) =
      lo >= hi ? 0 :
      mismatch_suffix(pairs, i, lo, hi - 1) + ((pairs[i] != pairs[hi - 1]) ? 1 : 0); */
/*@ logic integer prefix_mismatch(int* pairs, integer n, integer idx) =
      idx <= 0 ? 0 :
      prefix_mismatch(pairs, n, idx - 1) + mismatch_suffix(pairs, idx - 1, idx, n); */

/*@ requires (0 <= index < total - 1) && (index + 1 <= k <= total) && (count >= 0) && (count == prefix_mismatch(pairs, total, index) + mismatch_suffix(pairs, index, index + 1, k)) && (\forall integer t; index + 1 <= t < k ==> (pairs[index] == pairs[t] || pairs[index] != pairs[t])) && (\valid_read(pairs + (0 .. total - 1)));
    assigns \nothing;
*/
void check_A_implies_B(int array, int count, int i, int index, int j, int k, int m, int n, int *pairs, int pairs_len, int t, int total) {
    /*@ assert (total == pairs_len); */
    /*@ assert (k <= total); */
    /*@ assert (index <= total); */
    /*@ assert (index <= total - 1); */
    /*@ assert (index <= pairs_len - 1); */
    /*@ assert (index <= k); */
    /*@ assert (index < total); */
    /*@ assert (index < total ==> count >= 0); */
    /*@ assert (index < k); */
    /*@ assert (index < k ==> k <= total); */
    /*@ assert (index + 1 <= total); */
    /*@ assert (index + 1 <= k); */
    /*@ assert (\forall integer m; index <= m < total ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; index <= m < total ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; index < m < total ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; index < m < k ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> pairs[m] == pairs[m] || pairs[m] != pairs[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> pairs[m] == array || pairs[m] != array); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> pairs[m] == array || pairs[m] != array); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> pairs[index] != pairs[m] || pairs[index] == pairs[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> pairs[index] != pairs[m] || count >= 0); */
    /*@ assert (\forall integer m; index + 1 <= m < k ==> count >= 0); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] != array || count >= 0); */
    /*@ assert (\forall integer m; 0 <= m < index ==> \forall integer n; m < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; index + 1 <= m < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && m < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && m < n < k ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] == pairs[m] || pairs[n] == pairs[n]); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index + 1 <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index + 1 <= n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index + 1 <= n < k ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer j; index <= j < total ==> pairs[j] != array || pairs[j] == array); */
    /*@ assert (\forall integer i; index <= i < total ==> pairs[i] == array || pairs[i] != array); */
    /*@ assert (\forall integer i; index <= i < total ==> pairs[i] != array || pairs[i] == array); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (0 <= k); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
}

/*@ requires (total == pairs_len) && (k <= total) && (index <= total) && (index <= total - 1) && (index <= pairs_len - 1) && (index <= k) && (index < total) && (index < total ==> count >= 0) && (index < k) && (index < k ==> k <= total) && (index + 1 <= total) && (index + 1 <= k) && (\forall integer m; index <= m < total ==> pairs[m] == pairs[m]) && (\forall integer m; index <= m < total ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; index < m < total ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; index < m < k ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; index + 1 <= m < total ==> pairs[m] == pairs[m]) && (\forall integer m; index + 1 <= m < total ==> pairs[m] == pairs[m] || pairs[m] != pairs[m]) && (\forall integer m; index + 1 <= m < total ==> pairs[m] == array || pairs[m] != array) && (\forall integer m; index + 1 <= m < total ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; index + 1 <= m < k ==> pairs[m] == pairs[m]) && (\forall integer m; index + 1 <= m < k ==> pairs[m] == array || pairs[m] != array) && (\forall integer m; index + 1 <= m < k ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; index + 1 <= m < k ==> pairs[index] != pairs[m] || pairs[index] == pairs[m]) && (\forall integer m; index + 1 <= m < k ==> pairs[index] != pairs[m] || count >= 0) && (\forall integer m; index + 1 <= m < k ==> count >= 0) && (\forall integer m; 0 <= m < index ==> pairs[m] == pairs[m]) && (\forall integer m; 0 <= m < index ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; 0 <= m < index ==> pairs[m] != array || count >= 0) && (\forall integer m; 0 <= m < index ==> \forall integer n; m < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; index + 1 <= m < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && m < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && m < n < k ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] == pairs[m] || pairs[n] == pairs[n]) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && index + 1 <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]) && (\forall integer m, n; 0 <= m < index && index + 1 <= n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && index + 1 <= n < k ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer k; index + 1 <= k < total ==> count >= 0) && (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]) && (\forall integer j; index <= j < total ==> pairs[j] != array || pairs[j] == array) && (\forall integer i; index <= i < total ==> pairs[i] == array || pairs[i] != array) && (\forall integer i; index <= i < total ==> pairs[i] != array || pairs[i] == array) && (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0) && (0 <= k) && (0 <= index) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int array, int count, int i, int index, int j, int k, int m, int n, int *pairs, int pairs_len, int t, int total) {
    /*@ assert (0 <= index < total - 1); */
    /*@ assert (index + 1 <= k <= total); */
    /*@ assert (count >= 0); */
    /*@ assert (count == prefix_mismatch(pairs, total, index) + mismatch_suffix(pairs, index, index + 1, k)); */
    /*@ assert (\forall integer t; index + 1 <= t < k ==> (pairs[index] == pairs[t] || pairs[index] != pairs[t])); */
    /*@ assert (\valid_read(pairs + (0 .. total - 1))); */
}
