#include <limits.h>

/*@ logic integer count_pairs(int* pairs, integer lo, integer hi, integer p) =
    lo >= hi ? 0 :
    count_pairs(pairs, lo, hi - 1, p) +
    (pairs[lo] + pairs[hi - 1] == p ? 1 : 0); */

/*@ requires (0 <= index <= num) && (0 <= ret);
    assigns \nothing;
*/
void check_A_implies_B(int i, int index, int j, int k, int l, int num, int p, int *pairs, int ret) {
    /*@ assert (j <= num); */
    /*@ assert (index <= num); */
    /*@ assert (index <= j); */
    /*@ assert (index < num); */
    /*@ assert (index < num || index < j); */
    /*@ assert (index < j); */
    /*@ assert (index < j || j == index + 1); */
    /*@ assert (index + 1 <= j); */
    /*@ assert (\forall integer k; j <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index <= k < num ==> ret >= 0); */
    /*@ assert (\forall integer k; index < k < num ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index < k < num ==> pairs[index] + pairs[k] == p ==> ret >= 0); */
    /*@ assert (\forall integer k; index < k < num ==> (pairs[index] + pairs[k] == p ==> ret >= 0)); */
    /*@ assert (\forall integer k; index < k < j ==> pairs[index] + pairs[k] != p || ret >= 0); */
    /*@ assert (\forall integer k; index < k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 0)); */
    /*@ assert (\forall integer k; index < k < j ==> (pairs[index] + pairs[k] != p || ret >= 0)); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] == p || ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] == p ==> ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p || ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p || ret > 0); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p ==> ret >= 0); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 1)); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 0)); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret > 0)); */
    /*@ assert (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] != p || ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> pairs[k] + pairs[l] != p || ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] != p || ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> (pairs[k] + pairs[l] != p || ret >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i, k; 0 <= i < index ==> 0 <= k < num ==> ret >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= index); */
}

/*@ requires (j <= num) && (index <= num) && (index <= j) && (index < num) && (index < num || index < j) && (index < j) && (index < j || j == index + 1) && (index + 1 <= j) && (\forall integer k; j <= k < num ==> k < num) && (\forall integer k; index <= k < num ==> ret >= 0) && (\forall integer k; index < k < num ==> pairs[k] == pairs[k]) && (\forall integer k; index < k < num ==> pairs[index] + pairs[k] == p ==> ret >= 0) && (\forall integer k; index < k < num ==> (pairs[index] + pairs[k] == p ==> ret >= 0)) && (\forall integer k; index < k < j ==> pairs[index] + pairs[k] != p || ret >= 0) && (\forall integer k; index < k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 0)) && (\forall integer k; index < k < j ==> (pairs[index] + pairs[k] != p || ret >= 0)) && (\forall integer k; index + 1 <= k < num ==> pairs[k] == pairs[k]) && (\forall integer k; index + 1 <= k < j ==> pairs[k] == pairs[k]) && (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] == p || ret >= 0) && (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] == p ==> ret >= 0) && (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p || ret >= 0) && (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p || ret > 0) && (\forall integer k; index + 1 <= k < j ==> pairs[index] + pairs[k] != p ==> ret >= 0) && (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 1)) && (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret >= 0)) && (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] == p ==> ret > 0)) && (\forall integer k; index + 1 <= k < j ==> (pairs[index] + pairs[k] != p || ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> pairs[k] + pairs[l] != p || ret >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] != p || ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; index <= l < num ==> (pairs[k] + pairs[l] != p || ret >= 0)) && (\forall integer k; 0 <= k < index ==> \forall integer l; index + 1 <= l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)) && (\forall integer i, k; 0 <= i < index ==> 0 <= k < num ==> ret >= 0) && (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)) && (0 <= ret) && (0 <= j) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int i, int index, int j, int k, int l, int num, int p, int *pairs, int ret) {
    /*@ assert (0 <= index <= num); */
    /*@ assert (0 <= ret); */
}
