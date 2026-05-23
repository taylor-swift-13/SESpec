#include <limits.h>

/*@ requires (0 <= index <= \at(pairs_len,Pre) - 1) && (0 <= count) && (total == \at(pairs_len,Pre)) && (array == \at(array,Pre)) && (pairs_len == \at(pairs_len,Pre)) && (pairs == \at(pairs,Pre)) && (\forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int array, int c, int c1, int count, int i, int index, int j, int k, int *pairs, int pairs_len, int t, int *total) {
    /*@ assert (index < total ==> total == pairs_len); */
    /*@ assert (\forall integer t; index <= t < total ==> 0 <= t < total); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> t > index); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[index]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] ==> count >= 0); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> t < total); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] == pairs[c] || pairs[k] != pairs[c]); */
    /*@ assert (\forall integer i; index <= i < total ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; index <= i < total ==> i < total); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] == pairs[i] || pairs[j] == pairs[j]); */
    /*@ assert (total == pairs_len); */
    /*@ assert (index <= total || count <= total * (total - 1) / 2); */
    /*@ assert (index <= total - 1 ==> count >= 0); */
    /*@ assert (index < total ==> count >= 0); */
    /*@ assert (count <= total * total || index <= total); */
    /*@ assert (\forall integer t; index <= t < total ==> t < total); */
    /*@ assert (\forall integer t; index <= t < total ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> t < total); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] || count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> pairs[t] == pairs[t]); */
    /*@ assert (\forall integer t; 0 <= t < index ==> pairs[t] != pairs[index] || count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> pairs[index] != pairs[t] || count >= 0); */
    /*@ assert (\forall integer t; 0 <= t < index ==> 0 <= t < total); */
    /*@ assert (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index <= k < total ==> k < total); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] || count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] ==> count >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> k > index); */
    /*@ assert (\forall integer k; index + 1 <= k < total ==> k < total); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[index] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[index] != pairs[k] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] == pairs[k] || pairs[k] != pairs[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c1; k + 1 <= c1 < total ==> pairs[k] != pairs[c1] || count >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= k < total); */
    /*@ assert (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0); */
    /*@ assert (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0); */
    /*@ assert (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> (pairs[k] != pairs[c] ==> count >= 0)); */
    /*@ assert (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0); */
    /*@ assert (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> (pairs[k] != pairs[c] || count >= 0)); */
    /*@ assert (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> (pairs[k] != pairs[c] ==> count >= 0)); */
    /*@ assert (\forall integer k, c1; 0 <= k < index && k + 1 <= c1 < total ==> (pairs[k] != pairs[c1] ==> count >= 0)); */
    /*@ assert (\forall integer j; index + 1 <= j < total ==> j > index); */
    /*@ assert (\forall integer i; index + 1 <= i < total ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] != pairs[index] || count >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> 0 <= i < total); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> (pairs[i] != pairs[j] || count >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> (pairs[i] != pairs[j] ==> count >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] == pairs[j] || pairs[i] != pairs[j]); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] ==> count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] == pairs[i] || pairs[i] != pairs[j]); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] != pairs[j] ==> count >= 0); */
    /*@ assert (\forall integer c; index + 1 <= c <= total ==> c - index >= 1); */
    /*@ assert (\forall integer c; index + 1 <= c < total ==> c > index); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= count); */
}

/*@ requires (index < total ==> total == pairs_len) && (\forall integer t; index <= t < total ==> 0 <= t < total) && (\forall integer t; index + 1 <= t < total ==> t > index) && (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[t] || pairs[index] != pairs[t]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] == pairs[index]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] ==> count >= 0) && (\forall integer t; index + 1 <= t < total ==> count >= 0) && (\forall integer t; 0 <= t < index ==> t < total) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] == pairs[c] || pairs[k] != pairs[c]) && (\forall integer i; index <= i < total ==> pairs[i] == pairs[i]) && (\forall integer i; index <= i < total ==> i < total) && (\forall integer i, j; 0 <= i < index && index <= j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] == pairs[i] || pairs[j] == pairs[j]) && (total == pairs_len) && (index <= total || count <= total * (total - 1) / 2) && (index <= total - 1 ==> count >= 0) && (index < total ==> count >= 0) && (count <= total * total || index <= total) && (\forall integer t; index <= t < total ==> t < total) && (\forall integer t; index <= t < total ==> pairs[t] == pairs[t]) && (\forall integer t; index + 1 <= t < total ==> t < total) && (\forall integer t; index + 1 <= t < total ==> pairs[t] == pairs[t]) && (\forall integer t; index + 1 <= t < total ==> pairs[index] != pairs[t] || count >= 0) && (\forall integer t; 0 <= t < index ==> pairs[t] == pairs[t]) && (\forall integer t; 0 <= t < index ==> pairs[t] != pairs[index] || count >= 0) && (\forall integer t; 0 <= t < index ==> pairs[index] != pairs[t] || count >= 0) && (\forall integer t; 0 <= t < index ==> 0 <= t < total) && (\forall integer k; index <= k < total ==> pairs[k] == pairs[k]) && (\forall integer k; index <= k < total ==> k < total) && (\forall integer k; index + 1 <= k < total ==> pairs[k] == pairs[k]) && (\forall integer k; index + 1 <= k < total ==> pairs[index] == pairs[k] || pairs[index] != pairs[k]) && (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] || count >= 0) && (\forall integer k; index + 1 <= k < total ==> pairs[index] != pairs[k] ==> count >= 0) && (\forall integer k; index + 1 <= k < total ==> k > index) && (\forall integer k; index + 1 <= k < total ==> k < total) && (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]) && (\forall integer k; 0 <= k < index ==> pairs[k] != pairs[index] || count >= 0) && (\forall integer k; 0 <= k < index ==> pairs[index] != pairs[k] || count >= 0) && (\forall integer k; 0 <= k < index ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] == pairs[k] || pairs[k] != pairs[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c; k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c1; k + 1 <= c1 < total ==> pairs[k] != pairs[c1] || count >= 0) && (\forall integer k; 0 <= k < index ==> 0 <= k < total) && (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0) && (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> pairs[k] != pairs[c] ==> count >= 0) && (\forall integer k, c; 0 <= k < index && k + 1 <= c < total ==> (pairs[k] != pairs[c] ==> count >= 0)) && (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> pairs[k] != pairs[c] || count >= 0) && (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> (pairs[k] != pairs[c] || count >= 0)) && (\forall integer k, c; 0 <= k < index && index + 1 <= c < total ==> (pairs[k] != pairs[c] ==> count >= 0)) && (\forall integer k, c1; 0 <= k < index && k + 1 <= c1 < total ==> (pairs[k] != pairs[c1] ==> count >= 0)) && (\forall integer j; index + 1 <= j < total ==> j > index) && (\forall integer i; index + 1 <= i < total ==> pairs[i] == pairs[i]) && (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]) && (\forall integer i; 0 <= i < index ==> pairs[i] != pairs[index] || count >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; i + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i; 0 <= i < index ==> 0 <= i < total) && (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> (pairs[i] != pairs[j] || count >= 0)) && (\forall integer i, j; 0 <= i < index && index + 1 <= j < total ==> (pairs[i] != pairs[j] ==> count >= 0)) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] == pairs[j] || pairs[i] != pairs[j]) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && i < j < total ==> pairs[i] != pairs[j] ==> count >= 0) && (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] == pairs[i] || pairs[i] != pairs[j]) && (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] != pairs[j] || count >= 0) && (\forall integer i, j; 0 <= i < index && i + 1 <= j < total ==> pairs[i] != pairs[j] ==> count >= 0) && (\forall integer c; index + 1 <= c <= total ==> c - index >= 1) && (\forall integer c; index + 1 <= c < total ==> c > index) && (0 <= index) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int array, int c, int c1, int count, int i, int index, int j, int k, int *pairs, int pairs_len, int t, int *total) {
    /*@ assert (0 <= index <= \at(pairs_len,Pre) - 1); */
    /*@ assert (0 <= count); */
    /*@ assert (total == \at(pairs_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (pairs_len == \at(pairs_len,Pre)); */
    /*@ assert (pairs == \at(pairs,Pre)); */
    /*@ assert (\forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre)); */
}
