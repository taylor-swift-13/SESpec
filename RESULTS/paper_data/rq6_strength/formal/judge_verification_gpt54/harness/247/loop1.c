#include <limits.h>

/*@ logic integer count_gt(int* a, integer x, integer lo, integer hi) =
      lo >= hi ? 0 :
      count_gt(a, x, lo, hi - 1) + (a[hi - 1] > x ? 1 : 0); */
/*@ logic integer invcount_upto(int* a, integer i, integer n) =
      i >= n ? 0 :
      count_gt(a, a[i], i + 1, n) + invcount_upto(a, i + 1, n); */

/*@ requires (0 <= index && index <= num) && (0 <= ret) && (\forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre)) && (\forall integer k; 0 <= k < index ==> 0 <= indices[k] <= 100) && (\forall integer i, j; 0 <= i < j < index ==> indices[i] <= indices[j] || indices[i] > indices[j]);
    assigns \nothing;
*/
void check_A_implies_B(int c, int i, int index, int *indices, int indices_len, int j, int k, int l, int *num, int ret) {
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> (indices[k] > indices[c] ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= indices[k] || indices[k] >= indices[k]); */
    /*@ assert (ret == 0 || ret >= 0); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret <= num * (num - 1) / 2 || index <= ret); */
    /*@ assert (ret <= num * (num - 1) / 2 || index <= num); */
    /*@ assert (ret <= index * num || index <= ret); */
    /*@ assert (ret <= index * num || index <= num); */
    /*@ assert (ret <= index * (num - 1) || index <= ret); */
    /*@ assert (index <= num || ret >= 0); */
    /*@ assert (index <= num || ret <= num * (num - 1) / 2); */
    /*@ assert (index <= num || ret <= index * num); */
    /*@ assert (index <= num || ret <= index * (num - 1)); */
    /*@ assert (index <= num || index <= ret); */
    /*@ assert (index <= num ==> ret >= 0); */
    /*@ assert (\forall integer k; index <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index <= k < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] == indices[index]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] >= indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] > indices[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> indices[index] != indices[k] || indices[index] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> indices[k] <= indices[k] || indices[k] >= indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] != indices[l] || indices[k] == indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] > indices[l] ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] >= indices[l])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] > indices[l])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] < indices[l] || indices[k] >= indices[l])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] >= indices[c] || indices[k] < indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] != indices[c] || indices[k] == indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] > indices[c] ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] == indices[k] || indices[k] > indices[c])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || indices[k] > indices[c])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] != indices[c] || indices[k] == indices[c])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] == indices[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] <= indices[k] || indices[k] >= indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] != indices[c] || indices[k] == indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] != indices[c] || indices[k] == indices[c]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= ret); */
    /*@ assert (\forall integer c; index <= c < num ==> indices[c] == indices[c]); */
    /*@ assert (\forall integer c; index <= c < num ==> c < num); */
    /*@ assert (\forall integer c; index < c < num ==> indices[c] == indices[c]); */
    /*@ assert (\forall integer c; index < c < num ==> c < num); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[index] == indices[index]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] > indices[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> indices[c] == indices[c]); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> c >= index + 1); */
    /*@ assert (\forall integer c; index + 1 <= c < num ==> c < num); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= index); */
}

/*@ requires (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> (indices[k] > indices[c] ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> 0 <= indices[k] || indices[k] >= indices[k]) && (ret == 0 || ret >= 0) && (ret == 0 || ret > 0) && (ret <= num * (num - 1) / 2 || index <= ret) && (ret <= num * (num - 1) / 2 || index <= num) && (ret <= index * num || index <= ret) && (ret <= index * num || index <= num) && (ret <= index * (num - 1) || index <= ret) && (index <= num || ret >= 0) && (index <= num || ret <= num * (num - 1) / 2) && (index <= num || ret <= index * num) && (index <= num || ret <= index * (num - 1)) && (index <= num || index <= ret) && (index <= num ==> ret >= 0) && (\forall integer k; index <= k < num ==> k < num) && (\forall integer k; index <= k < num ==> indices[k] == indices[k]) && (\forall integer k; index + 1 <= k < num ==> k < num) && (\forall integer k; index + 1 <= k < num ==> indices[k] == indices[k]) && (\forall integer k; index + 1 <= k < num ==> indices[index] == indices[index]) && (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] >= indices[k]) && (\forall integer k; index + 1 <= k < num ==> indices[index] <= indices[k] || indices[index] > indices[k]) && (\forall integer k; index + 1 <= k < num ==> indices[index] != indices[k] || indices[index] == indices[k]) && (\forall integer k; 0 <= k < index ==> ret >= 0) && (\forall integer k; 0 <= k < index ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> indices[k] <= indices[k] || indices[k] >= indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> indices[k] != indices[l] || indices[k] == indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] > indices[l] ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] >= indices[l])) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] <= indices[l] || indices[k] > indices[l])) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (indices[k] < indices[l] || indices[k] >= indices[l])) && (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> indices[k] <= indices[l] || indices[k] > indices[l]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] >= indices[c] || indices[k] < indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> indices[k] != indices[c] || indices[k] == indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] > indices[c] ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] == indices[k] || indices[k] > indices[c])) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] <= indices[c] || indices[k] > indices[c])) && (\forall integer k; 0 <= k < index ==> \forall integer c; k < c < num ==> (indices[k] != indices[c] || indices[k] == indices[c])) && (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] == indices[k]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] <= indices[k] || indices[k] >= indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index <= c < num ==> indices[k] != indices[c] || indices[k] == indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] <= indices[c] || indices[k] > indices[c]) && (\forall integer k; 0 <= k < index ==> \forall integer c; index + 1 <= c < num ==> indices[k] != indices[c] || indices[k] == indices[c]) && (\forall integer k; 0 <= k < index ==> 0 <= ret) && (\forall integer c; index <= c < num ==> indices[c] == indices[c]) && (\forall integer c; index <= c < num ==> c < num) && (\forall integer c; index < c < num ==> indices[c] == indices[c]) && (\forall integer c; index < c < num ==> c < num) && (\forall integer c; index + 1 <= c < num ==> indices[index] == indices[index]) && (\forall integer c; index + 1 <= c < num ==> indices[index] <= indices[c] || indices[index] > indices[c]) && (\forall integer c; index + 1 <= c < num ==> indices[c] == indices[c]) && (\forall integer c; index + 1 <= c < num ==> c >= index + 1) && (\forall integer c; index + 1 <= c < num ==> c < num) && (0 <= ret) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int c, int i, int index, int *indices, int indices_len, int j, int k, int l, int *num, int ret) {
    /*@ assert (0 <= index && index <= num); */
    /*@ assert (0 <= ret); */
    /*@ assert (\forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> 0 <= indices[k] <= 100); */
    /*@ assert (\forall integer i, j; 0 <= i < j < index ==> indices[i] <= indices[j] || indices[i] > indices[j]); */
}
