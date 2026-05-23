#include <limits.h>

/*@ logic integer count_diff_pairs(int* p, integer n) =
    n <= 1 ? 0 : count_diff_pairs(p, n - 1) + (p[n - 2] != p[n - 1] ? 1 : 0); */

/*@ requires (0 <= index <= total - 1) && (count >= 0);
    assigns \nothing;
*/
void check_A_implies_B(int c, int c0, int count, int index, int k, int l, int m, int *p, int p_len, int total) {
    /*@ assert (total == p_len); */
    /*@ assert (index <= total); */
    /*@ assert (index <= total || index + 1 <= total); */
    /*@ assert (index <= total - 1); */
    /*@ assert (index <= p_len); */
    /*@ assert (index <= p_len); */
    /*@ assert (index <= p_len || index <= total); */
    /*@ assert (index <= p_len || index < p_len); */
    /*@ assert (index <= p_len || index + 1 <= total); */
    /*@ assert (index <= p_len - 1); */
    /*@ assert (index <= c); */
    /*@ assert (index < total); */
    /*@ assert (index < total ==> index + 1 <= total); */
    /*@ assert (index < total ==> c >= index + 1); */
    /*@ assert (index < total ==> c <= total); */
    /*@ assert (index < total - 1); */
    /*@ assert (index < p_len); */
    /*@ assert (index < p_len); */
    /*@ assert (index < p_len || index <= total); */
    /*@ assert (index < p_len || index + 1 <= total); */
    /*@ assert (index < c); */
    /*@ assert (index < c || c == total); */
    /*@ assert (index + 1 <= total); */
    /*@ assert (index + 1 <= c); */
    /*@ assert (index + 1 <= c || c == total); */
    /*@ assert (index + 1 < total); */
    /*@ assert (c == index + 1 || c <= total); */
    /*@ assert (c <= total); */
    /*@ assert (c <= p_len); */
    /*@ assert (\forall integer m; index <= m < total ==> m < p_len); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> p[m] == p[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> p[index] == p[index] || p[index] != p[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> p[index] != p[m] || count >= 0); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> m < p_len); */
    /*@ assert (\forall integer m; index + 1 <= m < total ==> 0 <= m < p_len); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> p[m] == p[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> p[index] == p[index]); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> p[index] == p[index] || p[index] != p[m]); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> p[index] != p[m] || count >= 0); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> p[index] != p[m] ==> count >= 0); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> m < total); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> m < p_len); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> 0 <= m < p_len); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> (p[index] == p[m] || p[index] != p[m])); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> (p[index] == p[index] || p[index] != p[m])); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> (p[index] != p[m] || count >= 0)); */
    /*@ assert (\forall integer m; index + 1 <= m < c ==> (p[index] != p[m] ==> count >= 0)); */
    /*@ assert (\forall integer m; 0 <= m < index ==> p[m] == p[m]); */
    /*@ assert (\forall integer l; index + 1 <= l < total ==> p[index] == p[index] || p[index] != p[l]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] == p[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] == p[index] || p[index] != p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> p[index] != p[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> 0 <= k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> p[index] == p[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> p[index] == p[index] || p[index] != p[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> p[index] != p[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < total); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> 0 <= k < total); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> 0 <= k < p_len); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> (p[index] == p[index] || p[index] != p[k])); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> (p[index] != p[k] || count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> k < total); */
    /*@ assert (\forall integer k; 0 <= k < index ==> k < p_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k+1 <= m < total ==> p[k] != p[m] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] == p[k] || p[k] != p[m]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] != p[m] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k+1 <= l < total ==> p[k] != p[l] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k+1 <= l < total ==> p[k] != p[l] ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < total ==> p[k] != p[l] ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[l] || p[k] != p[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] != p[l] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] != p[l] || count >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] == p[k] || p[k] != p[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] != p[c] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= k < p_len); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> p[index] == p[index] || p[index] != p[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> p[index] != p[c] || count >= 0); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> index < c); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> c < p_len); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> 0 <= c < p_len); */
    /*@ assert (\forall integer c0; index + 1 <= c0 < total ==> p[index] == p[index] || p[index] != p[c0]); */
    /*@ assert (1 <= c - index); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - index); */
}

/*@ requires (total == p_len) && (index <= total) && (index <= total || index + 1 <= total) && (index <= total - 1) && (index <= p_len) && (index <= p_len) && (index <= p_len || index <= total) && (index <= p_len || index < p_len) && (index <= p_len || index + 1 <= total) && (index <= p_len - 1) && (index <= c) && (index < total) && (index < total ==> index + 1 <= total) && (index < total ==> c >= index + 1) && (index < total ==> c <= total) && (index < total - 1) && (index < p_len) && (index < p_len) && (index < p_len || index <= total) && (index < p_len || index + 1 <= total) && (index < c) && (index < c || c == total) && (index + 1 <= total) && (index + 1 <= c) && (index + 1 <= c || c == total) && (index + 1 < total) && (c == index + 1 || c <= total) && (c <= total) && (c <= p_len) && (\forall integer m; index <= m < total ==> m < p_len) && (\forall integer m; index + 1 <= m < total ==> p[m] == p[m]) && (\forall integer m; index + 1 <= m < total ==> p[index] == p[index] || p[index] != p[m]) && (\forall integer m; index + 1 <= m < total ==> p[index] != p[m] || count >= 0) && (\forall integer m; index + 1 <= m < total ==> m < p_len) && (\forall integer m; index + 1 <= m < total ==> 0 <= m < p_len) && (\forall integer m; index + 1 <= m < c ==> p[m] == p[m]) && (\forall integer m; index + 1 <= m < c ==> p[index] == p[index]) && (\forall integer m; index + 1 <= m < c ==> p[index] == p[index] || p[index] != p[m]) && (\forall integer m; index + 1 <= m < c ==> p[index] != p[m] || count >= 0) && (\forall integer m; index + 1 <= m < c ==> p[index] != p[m] ==> count >= 0) && (\forall integer m; index + 1 <= m < c ==> m < total) && (\forall integer m; index + 1 <= m < c ==> m < p_len) && (\forall integer m; index + 1 <= m < c ==> 0 <= m < p_len) && (\forall integer m; index + 1 <= m < c ==> (p[index] == p[m] || p[index] != p[m])) && (\forall integer m; index + 1 <= m < c ==> (p[index] == p[index] || p[index] != p[m])) && (\forall integer m; index + 1 <= m < c ==> (p[index] != p[m] || count >= 0)) && (\forall integer m; index + 1 <= m < c ==> (p[index] != p[m] ==> count >= 0)) && (\forall integer m; 0 <= m < index ==> p[m] == p[m]) && (\forall integer l; index + 1 <= l < total ==> p[index] == p[index] || p[index] != p[l]) && (\forall integer k; index + 1 <= k < total ==> p[k] == p[k]) && (\forall integer k; index + 1 <= k < total ==> p[index] == p[index]) && (\forall integer k; index + 1 <= k < total ==> p[index] == p[index] || p[index] != p[k]) && (\forall integer k; index + 1 <= k < total ==> p[index] != p[k] || count >= 0) && (\forall integer k; index + 1 <= k < total ==> k < p_len) && (\forall integer k; index + 1 <= k < total ==> 0 <= k < p_len) && (\forall integer k; index + 1 <= k < c ==> p[k] == p[k]) && (\forall integer k; index + 1 <= k < c ==> p[index] == p[index]) && (\forall integer k; index + 1 <= k < c ==> p[index] == p[index] || p[index] != p[k]) && (\forall integer k; index + 1 <= k < c ==> p[index] != p[k] || count >= 0) && (\forall integer k; index + 1 <= k < c ==> k < total) && (\forall integer k; index + 1 <= k < c ==> k < p_len) && (\forall integer k; index + 1 <= k < c ==> 0 <= k < total) && (\forall integer k; index + 1 <= k < c ==> 0 <= k < p_len) && (\forall integer k; index + 1 <= k < c ==> (p[index] == p[index] || p[index] != p[k])) && (\forall integer k; index + 1 <= k < c ==> (p[index] != p[k] || count >= 0)) && (\forall integer k; 0 <= k < index ==> p[k] == p[k]) && (\forall integer k; 0 <= k < index ==> k < total) && (\forall integer k; 0 <= k < index ==> k < p_len) && (\forall integer k; 0 <= k < index ==> \forall integer m; k+1 <= m < total ==> p[k] != p[m] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] == p[k] || p[k] != p[m]) && (\forall integer k; 0 <= k < index ==> \forall integer m; k + 1 <= m < total ==> p[k] != p[m] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k+1 <= l < total ==> p[k] != p[l] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k+1 <= l < total ==> p[k] != p[l] ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < total ==> p[k] != p[l] ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] == p[l] || p[k] != p[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> p[k] != p[l] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k + 1 <= l < total ==> (p[k] != p[l] || count >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] == p[k] || p[k] != p[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> p[k] != p[c] || count >= 0) && (\forall integer k; 0 <= k < index ==> 0 <= k < p_len) && (\forall integer c; index + 1 <= c < total ==> p[index] == p[index] || p[index] != p[c]) && (\forall integer c; index + 1 <= c < total ==> p[index] != p[c] || count >= 0) && (\forall integer c; index + 1 <= c < total ==> index < c) && (\forall integer c; index + 1 <= c < total ==> c < p_len) && (\forall integer c; index + 1 <= c < total ==> 0 <= c < p_len) && (\forall integer c0; index + 1 <= c0 < total ==> p[index] == p[index] || p[index] != p[c0]) && (1 <= c - index) && (0 <= index) && (0 <= count) && (0 <= c) && (0 <= c - index);
    assigns \nothing;
*/
void check_B_implies_A(int c, int c0, int count, int index, int k, int l, int m, int *p, int p_len, int total) {
    /*@ assert (0 <= index <= total - 1); */
    /*@ assert (count >= 0); */
}
