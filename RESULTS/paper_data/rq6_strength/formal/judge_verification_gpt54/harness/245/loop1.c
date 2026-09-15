#include <limits.h>

/*@ logic integer count_pairs(int* pairs, integer lo, integer hi, integer p) =
    lo >= hi ? 0 :
    count_pairs(pairs, lo, hi - 1, p) +
    (pairs[lo] + pairs[hi - 1] == p ? 1 : 0); */

/*@ requires (0 <= index) && (0 <= ret) && (p == \at(p,Pre)) && (num == \at(num,Pre)) && (pairs_len == \at(pairs_len,Pre)) && (pairs == \at(pairs,Pre)) && (\forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100);
    assigns \nothing;
*/
void check_A_implies_B(int i, int index, int j, int k, int l, int *num, int p, int *pairs, int pairs_len, int ret) {
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; index + 1 <= j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)); */
    /*@ assert (ret <= num * num || index <= num); */
    /*@ assert (ret <= num * (num - 1) / 2 || index <= num); */
    /*@ assert (ret <= index * (num - index) || index <= num); */
    /*@ assert (ret <= index * (num - 1) || index <= num); */
    /*@ assert (\forall integer k; index <= k < num ==> k < num); */
    /*@ assert (\forall integer k; index + 1 <= k < num ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> pairs[k] + pairs[l] != p || ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)); */
    /*@ assert (\forall integer j; index <= j < num ==> j < num); */
    /*@ assert (\forall integer j; index + 1 <= j <= num ==> j >= index + 1); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> pairs[j] == pairs[j]); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> pairs[index] + pairs[j] == p ==> ret >= 0); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> pairs[index] + pairs[j] != p || ret >= 0); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> j >= index + 1); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> j <= num); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> j < num); */
    /*@ assert (\forall integer j; index + 1 <= j < num ==> (pairs[index] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer l; i < l < num ==> pairs[i] + pairs[l] != p || ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> pairs[i] + pairs[j] != p || ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> pairs[i] + pairs[j] != p || ret >= 0); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index <= j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && index < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] != p || ret >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] != p ==> ret >= 0); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)); */
    /*@ assert (\forall integer i, j; 0 <= i < index && i < j < num ==> ((pairs[i] + pairs[j] == p) ==> ret >= 0)); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= index); */
}

/*@ requires (\forall integer i; 0 <= i < index ==> \forall integer j; index + 1 <= j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)) && (ret <= num * num || index <= num) && (ret <= num * (num - 1) / 2 || index <= num) && (ret <= index * (num - index) || index <= num) && (ret <= index * (num - 1) || index <= num) && (\forall integer k; index <= k < num ==> k < num) && (\forall integer k; index + 1 <= k < num ==> pairs[k] == pairs[k]) && (\forall integer k; 0 <= k < index ==> pairs[k] == pairs[k]) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> pairs[k] + pairs[l] != p || ret >= 0) && (\forall integer k; 0 <= k < index ==> \forall integer l; k < l < num ==> (pairs[k] + pairs[l] == p ==> ret >= 0)) && (\forall integer j; index <= j < num ==> j < num) && (\forall integer j; index + 1 <= j <= num ==> j >= index + 1) && (\forall integer j; index + 1 <= j < num ==> pairs[j] == pairs[j]) && (\forall integer j; index + 1 <= j < num ==> pairs[index] + pairs[j] == p ==> ret >= 0) && (\forall integer j; index + 1 <= j < num ==> pairs[index] + pairs[j] != p || ret >= 0) && (\forall integer j; index + 1 <= j < num ==> j >= index + 1) && (\forall integer j; index + 1 <= j < num ==> j <= num) && (\forall integer j; index + 1 <= j < num ==> j < num) && (\forall integer j; index + 1 <= j < num ==> (pairs[index] + pairs[j] == p ==> ret >= 0)) && (\forall integer i; 0 <= i < index ==> pairs[i] == pairs[i]) && (\forall integer i; 0 <= i < index ==> \forall integer l; i < l < num ==> pairs[i] + pairs[l] != p || ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> pairs[i] + pairs[j] != p || ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i; 0 <= i < index ==> \forall integer j; index <= j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> pairs[i] + pairs[j] != p || ret >= 0) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i; 0 <= i < index ==> \forall integer j; i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)) && (\forall integer i, j; 0 <= i < index && index <= j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i, j; 0 <= i < index && index < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] == p ==> ret >= 0) && (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] != p || ret >= 0) && (\forall integer i, j; 0 <= i < index && i < j < num ==> pairs[i] + pairs[j] != p ==> ret >= 0) && (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] == p ==> ret >= 0)) && (\forall integer i, j; 0 <= i < index && i < j < num ==> (pairs[i] + pairs[j] != p || ret >= 0)) && (\forall integer i, j; 0 <= i < index && i < j < num ==> ((pairs[i] + pairs[j] == p) ==> ret >= 0)) && (0 <= ret) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int i, int index, int j, int k, int l, int *num, int p, int *pairs, int pairs_len, int ret) {
    /*@ assert (0 <= index); */
    /*@ assert (0 <= ret); */
    /*@ assert (p == \at(p,Pre)); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert (pairs_len == \at(pairs_len,Pre)); */
    /*@ assert (pairs == \at(pairs,Pre)); */
    /*@ assert (\forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100); */
}
