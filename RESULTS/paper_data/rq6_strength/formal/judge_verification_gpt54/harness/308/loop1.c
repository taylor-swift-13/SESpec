#include <limits.h>

/*@ logic integer max_prefix(int* positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > max_prefix(positions, lo + 1, hi) ? positions[lo] : max_prefix(positions, lo + 1, hi)); */

/*@ requires (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (\forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k],Pre)) && (result >= 0) && (\forall integer k; 0 <= k < index ==> positions[k] <= result) && ((index < \at(positions_len,Pre)) ==> (result >= 0)) && ((index < \at(positions_len,Pre)) ==> (((result == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (result >= 0))) && ((!(index < \at(positions_len,Pre))) ==> (result >= 0));
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int *positions, int positions_len) {
    /*@ assert (result >= positions[0] || index == 0); */
    /*@ assert (result >= 0 || result == 0); */
    /*@ assert (result > 0 ==> \exists integer k; 0 <= k < index && positions[k] == result); */
    /*@ assert (result > 0 ==> (\exists integer k; 0 <= k < index && positions[k] == result)); */
    /*@ assert (result == 0 || result >= positions[0]); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || \forall integer k; 0 <= k < index ==> result >= positions[k]); */
    /*@ assert (result == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= result); */
    /*@ assert (result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]); */
    /*@ assert (result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < index && positions[k] >= result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < index && positions[k] == result); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0); */
    /*@ assert (result == 0 || (\forall integer k; 0 <= k < index ==> result >= positions[k])); */
    /*@ assert (result == 0 || (\forall integer k; 0 <= k < index ==> positions[k] <= result)); */
    /*@ assert (result == 0 || (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k])); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0)); */
    /*@ assert (result == 0 ==> \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < index ==> result >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> result >= positions[k] || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k] || result == 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> positions[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= result || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= 0 || result >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> result >= positions[k])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> positions[k] <= result)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (positions[k] <= 0 || result >= positions[k])); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (positions[k] <= 0 || positions[k] <= result)); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result); */
    /*@ assert (\exists integer k; 0 <= k < index && result == positions[k] || result == 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] > 0 ==> result > 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] > 0 && result == positions[k] || result == 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == result || result == 0); */
    /*@ assert (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0 || result == 0); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
}

/*@ requires (result >= positions[0] || index == 0) && (result >= 0 || result == 0) && (result > 0 ==> \exists integer k; 0 <= k < index && positions[k] == result) && (result > 0 ==> (\exists integer k; 0 <= k < index && positions[k] == result)) && (result == 0 || result >= positions[0]) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result == 0 || \forall integer k; 0 <= k < index ==> result >= positions[k]) && (result == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= result) && (result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]) && (result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result) && (result == 0 || \exists integer k; 0 <= k < index && positions[k] >= result) && (result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0) && (result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result) && (result == 0 || \exists integer k; 0 <= k < index && positions[k] == result) && (result == 0 || \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0) && (result == 0 || (\forall integer k; 0 <= k < index ==> result >= positions[k])) && (result == 0 || (\forall integer k; 0 <= k < index ==> positions[k] <= result)) && (result == 0 || (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k])) && (result == 0 || (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result)) && (result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result)) && (result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0)) && (result == 0 ==> \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result) && (\forall integer k; 0 <= k < index ==> result >= positions[k]) && (\forall integer k; 0 <= k < index ==> result >= positions[k] || positions[k] <= 0) && (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k]) && (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k] || result == 0) && (\forall integer k; 0 <= k < index ==> positions[k] > 0 ==> positions[k] <= result) && (\forall integer k; 0 <= k < index ==> positions[k] <= result) && (\forall integer k; 0 <= k < index ==> positions[k] <= result || positions[k] <= 0) && (\forall integer k; 0 <= k < index ==> positions[k] <= 0 || result >= positions[k]) && (\forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result) && (\forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> result >= positions[k])) && (\forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> positions[k] <= result)) && (\forall integer k; 0 <= k < index ==> (positions[k] <= 0 || result >= positions[k])) && (\forall integer k; 0 <= k < index ==> (positions[k] <= 0 || positions[k] <= result)) && (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]) && (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result) && (\exists integer k; 0 <= k < index && result == positions[k] || result == 0) && (\exists integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]) && (\exists integer k; 0 <= k < index && positions[k] > 0 ==> result > 0) && (\exists integer k; 0 <= k < index && positions[k] > 0 && result == positions[k] || result == 0) && (\exists integer k; 0 <= k < index && positions[k] == result || result == 0) && (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0 || result == 0) && (0 <= result) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int *positions, int positions_len) {
    /*@ assert (positions_len == \at(positions_len,Pre)); */
    /*@ assert (positions == \at(positions,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k],Pre)); */
    /*@ assert (result >= 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> positions[k] <= result); */
    /*@ assert ((index < \at(positions_len,Pre)) ==> (result >= 0)); */
    /*@ assert ((index < \at(positions_len,Pre)) ==> (((result == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (result >= 0))); */
    /*@ assert ((!(index < \at(positions_len,Pre))) ==> (result >= 0)); */
}
