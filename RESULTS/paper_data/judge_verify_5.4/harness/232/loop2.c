#include <limits.h>

/*@ requires (index + 1 <= c <= total) && (0 <= index <= total - 1) && (count >= 0) && (total == \at(pairs_len,Pre)) && (array == \at(array,Pre)) && (pairs_len == \at(pairs_len,Pre)) && (pairs == \at(pairs,Pre)) && (\forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int array, int c, int c1, int count, int i, int index, int k, int *pairs, int pairs_len, int t, int *total) {
    /*@ assert (total == pairs_len); */
    /*@ assert (index <= total); */
    /*@ assert (index <= total - 1); */
    /*@ assert (index <= c); */
    /*@ assert (index < total); */
    /*@ assert (index < total ==> pairs_len == total); */
    /*@ assert (index < total ==> count >= 0); */
    /*@ assert (index < total ==> c <= total); */
    /*@ assert (index < c); */
    /*@ assert (index + 1 <= c); */
    /*@ assert (c == index + 1 || c > index); */
    /*@ assert (c <= total); */
    /*@ assert (c <= total ==> index + 1 <= c); */
    /*@ assert (c <= pairs_len); */
    /*@ assert (c - index <= total - index); */
    /*@ assert (c - index <= total - index || count <= total * total); */
    /*@ assert (c - index <= total - index || 0 <= c - index); */
    /*@ assert (\forall integer t; index <= t < total ==> t < total); */
    /*@ assert (\forall integer t; index <= t < total ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index <= t < c ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> t < total); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[index]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] || count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] ==> count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> t < total); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[t] || count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[index]); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[index] != pairs[t] || count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> pairs[index] != pairs[t] ==> count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < c ==> 0 <= t); */
    /*@ assert (\forall integer t; 0 <= t < index ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; 0 <= t < index ==> pairs[t] != pairs[index] || count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> 0 <= t < total); */
    /*@ assert (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] ==> count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> pairs[index] == pairs[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> pairs[index] != pairs[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> pairs[index] != pairs[k] ==> count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < total); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[index] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[c] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[c] ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c1; k + 1 <= c1 < total ==> pairs[k] != pairs[c1] ==> count >= 0); */
    /*@ assert (1 <= c - index); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - index); */
    /*@ assert (0 <= c - index || count <= total * total); */
    /*@ assert (0 <= c - (index + 1)); */
    /*@ assert (0 < c - index); */
}

/*@ requires (total == pairs_len) && (index <= total) && (index <= total - 1) && (index <= c) && (index < total) && (index < total ==> pairs_len == total) && (index < total ==> count >= 0) && (index < total ==> c <= total) && (index < c) && (index + 1 <= c) && (c == index + 1 || c > index) && (c <= total) && (c <= total ==> index + 1 <= c) && (c <= pairs_len) && (c - index <= total - index) && (c - index <= total - index || count <= total * total) && (c - index <= total - index || 0 <= c - index) && (\forall integer t; index <= t < total ==> t < total) && (\forall integer t; index <= t < total ==> pairs[t] == pairs[t]) && (\forall integer t; index <= t < c ==> pairs[t] == pairs[t]) && (\forall integer t; index + 1 <= t < total ==> t < total) && (\forall integer t; index + 1 <= t < total ==> pairs[t] == pairs[t]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[index]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] || count >= 0) && (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] ==> count >= 0) && (\forall integer t; index + 1 <= t < c ==> t < total) && (\forall integer t; index + 1 <= t < c ==> pairs[t] == pairs[t]) && (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]) && (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[t] || count >= 0) && (\forall integer t; index + 1 <= t < c ==> pairs[index] == pairs[index]) && (\forall integer t; index + 1 <= t < c ==> pairs[index] != pairs[t] || count >= 0) && (\forall integer t; index + 1 <= t < c ==> pairs[index] != pairs[t] ==> count >= 0) && (\forall integer t; index + 1 <= t < c ==> count >= 0) && (\forall integer t; index + 1 <= t < c ==> 0 <= t) && (\forall integer t; 0 <= t < index ==> pairs[t] == pairs[t]) && (\forall integer t; 0 <= t < index ==> pairs[t] != pairs[index] || count >= 0) && (\forall integer t; 0 <= t < index ==> count >= 0) && (\forall integer t; 0 <= t < index ==> 0 <= t < total) && (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]) && (\forall integer k; index + 1 <= k < total ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]) && (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] || count >= 0) && (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] ==> count >= 0) && (\forall integer k; index + 1 <= k < c ==> pairs[k] == pairs[k]) && (\forall integer k; index + 1 <= k < c ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]) && (\forall integer k; index + 1 <= k < c ==> pairs[index] == pairs[k] || count >= 0) && (\forall integer k; index + 1 <= k < c ==> pairs[index] != pairs[k] || count >= 0) && (\forall integer k; index + 1 <= k < c ==> pairs[index] != pairs[k] ==> count >= 0) && (\forall integer k; index + 1 <= k < c ==> k < total) && (\forall integer k; index + 1 <= k < c ==> count >= 0) && (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]) && (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[index] || count >= 0) && (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[c] || count >= 0) && (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[c] ==> count >= 0) && (\forall integer k; 0 <= k < index ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c1; k + 1 <= c1 < total ==> pairs[k] != pairs[c1] ==> count >= 0) && (1 <= c - index) && (0 <= index) && (0 <= count) && (0 <= c) && (0 <= c - index) && (0 <= c - index || count <= total * total) && (0 <= c - (index + 1)) && (0 < c - index);
    assigns \nothing;
*/
void check_B_implies_A(int array, int c, int c1, int count, int i, int index, int k, int *pairs, int pairs_len, int t, int *total) {
    /*@ assert (index + 1 <= c <= total); */
    /*@ assert (0 <= index <= total - 1); */
    /*@ assert (count >= 0); */
    /*@ assert (total == \at(pairs_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (pairs_len == \at(pairs_len,Pre)); */
    /*@ assert (pairs == \at(pairs,Pre)); */
    /*@ assert (\forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre)); */
}
