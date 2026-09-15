#include <limits.h>

/*@ logic integer count_gt(int* a, integer x, integer lo, integer hi) =
      lo >= hi ? 0 :
      count_gt(a, x, lo, hi - 1) + (a[hi - 1] > x ? 1 : 0); */
/*@ logic integer invcount_upto(int* a, integer i, integer n) =
      i >= n ? 0 :
      count_gt(a, a[i], i + 1, n) + invcount_upto(a, i + 1, n); */

/*@ requires (0 <= index && index < num) && (index + 1 <= c && c <= num) && (ret >= 0) && (\forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre)) && (\forall integer k; 0 <= k < indices_len ==> 0 <= indices[k] <= 100);
    assigns \nothing;
*/
void check_A_implies_B(int c, int index, int *indices, int indices_len, int k, int l, int num, int ret) {
    /*@ assert (index <= num); */
    /*@ assert (index <= c); */
    /*@ assert (index < num); */
    /*@ assert (index < num ==> c >= index + 1); */
    /*@ assert (index < c); */
    /*@ assert (index + 1 <= c); */
    /*@ assert (c == num || c < num); */
    /*@ assert (c == index + 1 || c > index + 1); */
    /*@ assert (c == index + 1 || c <= num); */
    /*@ assert (c <= num); */
    /*@ assert (c <= num ==> 0 <= ret); */
    /*@ assert (c <= num + 1); */
    /*@ assert (c < num || c == num); */
    /*@ assert (c < num + 1); */
    /*@ assert (\forall integer k; index <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index <= k < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[k] <= indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] == indices[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] > indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> c <= num); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> k < num); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> indices[index] == indices[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> indices[index] <= indices[k] || indices[index] >= indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> indices[index] <= indices[k] || indices[index] > indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> indices[index] != indices[k] || indices[index] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> (indices[index] > indices[k] ==> ret >= 0)); */
    /*@ assert (\forall integer k; index + 1 <= k < c ==> (indices[index] <= indices[k] || indices[index] > indices[k])); */
    /*@ assert (\forall integer k; c <= k < num ==> k < num); */
    /*@ assert (\forall integer k; c <= k < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> k < num); */
    /*@ assert (\forall integer k; 0 <= k < index ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> indices[k] <= indices[k] || indices[k] >= indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] != indices[l] || indices[k] == indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] > indices[l] ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] > indices[l])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] != indices[l] || indices[k] == indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= ret); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= indices[k] || indices[k] < indices[k] + 1); */
    /*@ assert (\forall integer k; 0 <= k < c ==> k < num); */
    /*@ assert (\forall integer k; 0 <= k < c ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> ret >= 0); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[index] == indices[index]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] >= indices[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] > indices[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[c] == indices[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> c >= index + 1); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> c <= num); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> c < num); */
    /*@ assert (1 <= c - index); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= c); */
}

/*@ requires (index <= num) && (index <= c) && (index < num) && (index < num ==> c >= index + 1) && (index < c) && (index + 1 <= c) && (c == num || c < num) && (c == index + 1 || c > index + 1) && (c == index + 1 || c <= num) && (c <= num) && (c <= num ==> 0 <= ret) && (c <= num + 1) && (c < num || c == num) && (c < num + 1) && (\forall integer k; index <= k < num ==> k < num) && (\forall integer k; index <= k < num ==> indices[k] == indices[k]) && (\forall integer k; index + 1 <= k < num ==> ret >= 0) && (\forall integer k; index + 1 <= k < num ==> k < num) && (\forall integer k; index + 1 <= k < num ==> indices[k] == indices[k]) && (\forall integer k; index + 1 <= k < num ==> indices[k] <= indices[k]) && (\forall integer k; index + 1 <= k < num ==> indices[index] == indices[index]) && (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] > indices[k]) && (\forall integer k; index + 1 <= k < num ==> c <= num) && (\forall integer k; index + 1 <= k < c ==> ret >= 0) && (\forall integer k; index + 1 <= k < c ==> k < num) && (\forall integer k; index + 1 <= k < c ==> indices[k] == indices[k]) && (\forall integer k; index + 1 <= k < c ==> indices[index] == indices[index]) && (\forall integer k; index + 1 <= k < c ==> indices[index] <= indices[k] || indices[index] >= indices[k]) && (\forall integer k; index + 1 <= k < c ==> indices[index] <= indices[k] || indices[index] > indices[k]) && (\forall integer k; index + 1 <= k < c ==> indices[index] != indices[k] || indices[index] == indices[k]) && (\forall integer k; index + 1 <= k < c ==> (indices[index] > indices[k] ==> ret >= 0)) && (\forall integer k; index + 1 <= k < c ==> (indices[index] <= indices[k] || indices[index] > indices[k])) && (\forall integer k; c <= k < num ==> k < num) && (\forall integer k; c <= k < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> ret >= 0) && (\forall integer k; 0 <= k < index ==> k < num) && (\forall integer k; 0 <= k < index ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> indices[k] <= indices[k] || indices[k] >= indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] != indices[l] || indices[k] == indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] > indices[l] ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] > indices[l])) && (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] != indices[l] || indices[k] == indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> ret >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]) && (\forall integer k; 0 <= k < index ==> 0 <= ret) && (\forall integer k; 0 <= k < index ==> 0 <= indices[k] || indices[k] < indices[k] + 1) && (\forall integer k; 0 <= k < c ==> k < num) && (\forall integer k; 0 <= k < c ==> indices[k] == indices[k]) && (\forall integer c; index + 1 <= c < num ==> ret >= 0) && (\forall integer c; index + 1 <= c < num ==> indices[index] == indices[index]) && (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] >= indices[c]) && (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] > indices[c]) && (\forall integer c; index + 1 <= c < num ==> indices[c] == indices[c]) && (\forall integer c; index + 1 <= c < num ==> c >= index + 1) && (\forall integer c; index + 1 <= c < num ==> c <= num) && (\forall integer c; index + 1 <= c < num ==> c < num) && (1 <= c - index) && (0 <= ret) && (0 <= index) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int index, int *indices, int indices_len, int k, int l, int num, int ret) {
    /*@ assert (0 <= index && index < num); */
    /*@ assert (index + 1 <= c && c <= num); */
    /*@ assert (ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre)); */
    /*@ assert (\forall integer k; 0 <= k < indices_len ==> 0 <= indices[k] <= 100); */
}
