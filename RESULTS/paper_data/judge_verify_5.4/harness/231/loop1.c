#include <limits.h>

/*@ logic integer count_diff_pairs(int* p, integer n) =
    n <= 1 ? 0 : count_diff_pairs(p, n - 1) + (p[n - 2] != p[n - 1] ? 1 : 0); */

/*@ requires (0 <= index <= total - 1) && (total == \at(p_len,Pre)) && (p_len == \at(p_len,Pre)) && (p == \at(p,Pre)) && (array == \at(array,Pre)) && (count >= 0) && (count == count_diff_pairs(p, index + 1));
    assigns \nothing;
*/
void check_A_implies_B(int array, int c, int c0, int count, int index, int k, int l, int m, int *p, int p_len, int total) {
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] == p[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] == p[index] || p[index] != p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] != p[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> (p[index] == p[k] || p[index] != p[k])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] != p[m] ==> count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] == p[l] || p[k] != p[l])); */
    /*@ assert (total == p_len); */
    /*@ assert (index < total ==> index < p_len); */
    /*@ assert (index < total ==> index + 1 <= total); */
    /*@ assert (index < p_len ==> index < total); */
    /*@ assert (count == 0 || count > 0); */
    /*@ assert (\forall integer k; index <= k < total ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; index <= k < total ==> k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> 0 <= k < total); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> 0 <= k < p_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> k < p_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k < m < total ==> p[k] != p[m] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k < m < total ==> (p[k] == p[m] || p[k] != p[m])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] == p[k] || p[k] != p[m]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] != p[m] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] == p[m] || p[k] != p[m])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] == p[k] || p[k] != p[m])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] != p[m] || count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[l] || p[k] != p[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[k] || p[k] != p[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] != p[l] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] != p[l] || count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] == p[k] || p[k] != p[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] != p[c] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> c < p_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> 0 <= c < p_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> (p[k] == p[k] || p[k] != p[c])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> (p[k] != p[c] || count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= k < p_len); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> p[index] == p[index] || p[index] != p[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> p[index] != p[c] || count >= 0); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> index < c); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> c < p_len); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> 0 <= c); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> 0 <= c < total); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> 0 <= c < p_len); */
    /*@ assert (\forall integer c0; index + 1 <= c0 < total ==> p[index] == p[index] || p[index] != p[c0]); */
    /*@ assert (\forall integer c0; index + 1 <= c0 < total ==> p[index] != p[c0] || count >= 0); */
    /*@ assert (\forall integer c0; index + 1 <= c0 < total ==> index < c0); */
    /*@ assert (\forall integer c0; index + 1 <= c0 < total ==> 0 <= c0 < p_len); */
    /*@ assert (\exists integer k; 0 <= k < index ==> p[k] == p[k]); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
}

/*@ requires (\forall integer k; index + 1 <= k < total ==> p[index] == p[index]) && (\forall integer k; index + 1 <= k < total ==> p[index] == p[index] || p[index] != p[k]) && (\forall integer k; index + 1 <= k < total ==> p[index] != p[k] || count >= 0) && (\forall integer k; index + 1 <= k < total ==> (p[index] == p[k] || p[index] != p[k])) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] != p[m] ==> count >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] == p[l] || p[k] != p[l])) && (total == p_len) && (index < total ==> index < p_len) && (index < total ==> index + 1 <= total) && (index < p_len ==> index < total) && (count == 0 || count > 0) && (\forall integer k; index <= k < total ==> p[k] == p[k]) && (\forall integer k; index <= k < total ==> k < p_len) && (\forall integer k; index + 1 <= k < total ==> p[k] == p[k]) && (\forall integer k; index + 1 <= k < total ==> k < p_len) && (\forall integer k; index + 1 <= k < total ==> 0 <= k < total) && (\forall integer k; index + 1 <= k < total ==> 0 <= k < p_len) && (\forall integer k; 0 <= k < index ==> p[k] == p[k]) && (\forall integer k; 0 <= k < index ==> k < p_len) && (\forall integer k; 0 <= k < index ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer m; k < m < total ==> p[k] != p[m] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer m; k < m < total ==> (p[k] == p[m] || p[k] != p[m])) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] == p[k] || p[k] != p[m]) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] != p[m] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] == p[m] || p[k] != p[m])) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] == p[k] || p[k] != p[m])) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> (p[k] != p[m] || count >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[l] || p[k] != p[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[k] || p[k] != p[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] != p[l] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] != p[l] || count >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] == p[k] || p[k] != p[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] != p[c] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> c < p_len) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> 0 <= c < p_len) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> (p[k] == p[k] || p[k] != p[c])) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> (p[k] != p[c] || count >= 0)) && (\forall integer k; 0 <= k < index ==> 0 <= k < p_len) && (\forall integer c; index + 1 <= c < total ==> p[index] == p[index] || p[index] != p[c]) && (\forall integer c; index + 1 <= c < total ==> p[index] != p[c] || count >= 0) && (\forall integer c; index + 1 <= c < total ==> index < c) && (\forall integer c; index + 1 <= c < total ==> c < p_len) && (\forall integer c; index + 1 <= c < total ==> 0 <= c) && (\forall integer c; index + 1 <= c < total ==> 0 <= c < total) && (\forall integer c; index + 1 <= c < total ==> 0 <= c < p_len) && (\forall integer c0; index + 1 <= c0 < total ==> p[index] == p[index] || p[index] != p[c0]) && (\forall integer c0; index + 1 <= c0 < total ==> p[index] != p[c0] || count >= 0) && (\forall integer c0; index + 1 <= c0 < total ==> index < c0) && (\forall integer c0; index + 1 <= c0 < total ==> 0 <= c0 < p_len) && (\exists integer k; 0 <= k < index ==> p[k] == p[k]) && (0 <= index) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int array, int c, int c0, int count, int index, int k, int l, int m, int *p, int p_len, int total) {
    /*@ assert (0 <= index <= total - 1); */
    /*@ assert (total == \at(p_len,Pre)); */
    /*@ assert (p_len == \at(p_len,Pre)); */
    /*@ assert (p == \at(p,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (count >= 0); */
    /*@ assert (count == count_diff_pairs(p, index + 1)); */
}
