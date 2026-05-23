#include <limits.h>

/*@ logic integer mismatch_suffix(int* pairs, integer i, integer lo, integer hi) =
      lo >= hi ? 0 :
      mismatch_suffix(pairs, i, lo, hi - 1) + ((pairs[i] != pairs[hi - 1]) ? 1 : 0); */
/*@ logic integer prefix_mismatch(int* pairs, integer n, integer idx) =
      idx <= 0 ? 0 :
      prefix_mismatch(pairs, n, idx - 1) + mismatch_suffix(pairs, idx - 1, idx, n); */

/*@ requires (0 <= index <= total) && (total == \at(pairs_len,Pre)) && (array == \at(array,Pre)) && (pairs_len == \at(pairs_len,Pre)) && (pairs == \at(pairs,Pre)) && (count >= 0) && (\forall integer p; 0 <= p < index ==> 0 <= pairs[p] <= 100) && (\forall integer p; 0 <= p < index ==> \forall integer q; p + 1 <= q < total ==> ((pairs[p] == pairs[q]) || (pairs[p] != pairs[q]))) && (count == prefix_mismatch(pairs, total, index)) && (\valid_read(pairs + (0 .. total - 1)));
    assigns \nothing;
*/
void check_A_implies_B(int array, int count, int i, int index, int j, int k, int m, int n, int p, int *pairs, int pairs_len, int q, int *total) {
    /*@ assert (\forall integer m; index + 1 <= m < total ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m, n; 0 <= m < index && m < n < total ==> count >= 0); */
    /*@ assert (total == pairs_len); */
    /*@ assert (index <= total || count <= index * total); */
    /*@ assert (\forall integer m; index <= m < total ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; index <= m < total ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] == pairs[m]); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] != array || pairs[m] == array); */
    /*@ assert (\forall integer m; 0 <= m < index ==> pairs[m] != array || count >= 0); */
    /*@ assert (\forall integer m; 0 <= m < index ==> \forall integer n; m < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && m < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] == pairs[m] || pairs[n] == pairs[n]); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer m, n; 0 <= m < index && index < n < total ==> pairs[m] != pairs[n] || count >= 0); */
    /*@ assert (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index <= k < total ==> pairs[k] == array || pairs[k] != array); */
    /*@ assert (\forall integer i; index <= i < total ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; index <= i < total ==> pairs[i] != array || pairs[i] == array); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] != array || pairs[i] == array); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] != array || count >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] == pairs[i] || pairs[j] == pairs[j]); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || pairs[i] == pairs[j]); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
}

/*@ requires (\forall integer m; index + 1 <= m < total ==> pairs[m] != array || pairs[m] == array) && (\forall integer m, n; 0 <= m < index && m < n < total ==> count >= 0) && (total == pairs_len) && (index <= total || count <= index * total) && (\forall integer m; index <= m < total ==> pairs[m] == pairs[m]) && (\forall integer m; index <= m < total ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; 0 <= m < index ==> pairs[m] == pairs[m]) && (\forall integer m; 0 <= m < index ==> pairs[m] != array || pairs[m] == array) && (\forall integer m; 0 <= m < index ==> pairs[m] != array || count >= 0) && (\forall integer m; 0 <= m < index ==> \forall integer n; m < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && m < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] == pairs[m] || pairs[n] == pairs[n]) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || pairs[m] == pairs[n]) && (\forall integer m, n; 0 <= m < index && index <= n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer m, n; 0 <= m < index && index < n < total ==> pairs[m] != pairs[n] || count >= 0) && (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]) && (\forall integer k; index <= k < total ==> pairs[k] == array || pairs[k] != array) && (\forall integer i; index <= i < total ==> pairs[i] == pairs[i]) && (\forall integer i; index <= i < total ==> pairs[i] != array || pairs[i] == array) && (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]) && (\forall integer i; 0 <= i < index ==> pairs[i] != array || pairs[i] == array) && (\forall integer i; 0 <= i < index ==> pairs[i] != array || count >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] == pairs[i] || pairs[j] == pairs[j]) && (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || pairs[i] == pairs[j]) && (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0) && (0 <= index) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int array, int count, int i, int index, int j, int k, int m, int n, int p, int *pairs, int pairs_len, int q, int *total) {
    /*@ assert (0 <= index <= total); */
    /*@ assert (total == \at(pairs_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (pairs_len == \at(pairs_len,Pre)); */
    /*@ assert (pairs == \at(pairs,Pre)); */
    /*@ assert (count >= 0); */
    /*@ assert (\forall integer p; 0 <= p < index ==> 0 <= pairs[p] <= 100); */
    /*@ assert (\forall integer p; 0 <= p < index ==> \forall integer q; p + 1 <= q < total ==> ((pairs[p] == pairs[q]) || (pairs[p] != pairs[q]))); */
    /*@ assert (count == prefix_mismatch(pairs, total, index)); */
    /*@ assert (\valid_read(pairs + (0 .. total - 1))); */
}
