#include <limits.h>

/*@ logic integer max0(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max0(a, lo, hi - 1) >= a[hi - 1] ? max0(a, lo, hi - 1) : a[hi - 1]); */

/*@ requires (0 <= index <= positions_len) && (0 <= largest) && (largest == max0(positions, 0, index)) && (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (\forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int largest, int *positions, int positions_len) {
    /*@ assert (largest >= positions[index-1] || index == 0); */
    /*@ assert (largest >= positions[index - 1] || index == 0); */
    /*@ assert (largest == 0 || largest >= positions[index-1]); */
    /*@ assert (largest == 0 || largest > 0); */
    /*@ assert (largest == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= largest); */
    /*@ assert (largest == 0 || \forall integer k; 0 <= k < index ==> largest >= positions[k]); */
    /*@ assert (largest == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]); */
    /*@ assert (largest == 0 || \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0); */
    /*@ assert (largest == 0 || (\forall integer k; 0 <= k < index ==> largest >= positions[k])); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest)); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> largest >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> largest >= positions[k] || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] > largest ==> positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] > 0 ==> largest > 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] > 0 ==> largest == positions[k]); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == largest || largest == 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == largest ==> largest >= 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == largest ==> largest > 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0 || largest == 0); */
    /*@ assert (0 <= largest); */
    /*@ assert (0 <= index); */
    /*@ assert ((\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0)); */
    /*@ assert ((\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest)); */
    /*@ assert ((\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k])); */
    /*@ assert ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> largest > 0); */
    /*@ assert ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && positions[k] > 0 && largest == positions[k])); */
    /*@ assert ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && largest == positions[k] && positions[k] > 0)); */
    /*@ assert ((\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest) || largest == 0); */
    /*@ assert ((\exists integer k; 0 <= k < index && positions[k] == largest) || largest == 0); */
}

/*@ requires (largest >= positions[index-1] || index == 0) && (largest >= positions[index - 1] || index == 0) && (largest == 0 || largest >= positions[index-1]) && (largest == 0 || largest > 0) && (largest == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= largest) && (largest == 0 || \forall integer k; 0 <= k < index ==> largest >= positions[k]) && (largest == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]) && (largest == 0 || \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0) && (largest == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest) && (largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest) && (largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0) && (largest == 0 || (\forall integer k; 0 <= k < index ==> largest >= positions[k])) && (largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest)) && (largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0)) && (\forall integer k; 0 <= k < index ==> positions[k] <= largest) && (\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0) && (\forall integer k; 0 <= k < index ==> largest >= positions[k]) && (\forall integer k; 0 <= k < index ==> largest >= positions[k] || positions[k] <= 0) && (\forall integer k; 0 <= k < index && positions[k] > largest ==> positions[k] <= 0) && (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest) && (\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]) && (\forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0) && (\exists integer k; 0 <= k < index && positions[k] > 0 ==> largest > 0) && (\exists integer k; 0 <= k < index && positions[k] > 0 ==> largest == positions[k]) && (\exists integer k; 0 <= k < index && positions[k] == largest || largest == 0) && (\exists integer k; 0 <= k < index && positions[k] == largest ==> largest >= 0) && (\exists integer k; 0 <= k < index && positions[k] == largest ==> largest > 0) && (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0 || largest == 0) && (0 <= largest) && (0 <= index) && ((\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0)) && ((\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest)) && ((\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k])) && ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> largest > 0) && ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && positions[k] > 0 && largest == positions[k])) && ((\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && largest == positions[k] && positions[k] > 0)) && ((\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest) || largest == 0) && ((\exists integer k; 0 <= k < index && positions[k] == largest) || largest == 0);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int largest, int *positions, int positions_len) {
    /*@ assert (0 <= index <= positions_len); */
    /*@ assert (0 <= largest); */
    /*@ assert (largest == max0(positions, 0, index)); */
    /*@ assert (positions_len == \at(positions_len,Pre)); */
    /*@ assert (positions == \at(positions,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre)); */
}
