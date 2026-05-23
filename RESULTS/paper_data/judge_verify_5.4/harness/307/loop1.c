#include <limits.h>

/*@ requires (0 <= count <= positions_len) && (largest >= 0) && (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (\forall integer k; 0 <= k < count ==> positions[k] <= largest) && (count == positions_len ==> (\forall integer k; 0 <= k < positions_len ==> positions[k] <= largest)) && ((count < \at(positions_len,Pre)) ==> (\forall integer k; 0 <= k < count ==> positions[k] <= largest)) && (\forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int largest, int *positions, int positions_len) {
    /*@ assert (largest >= positions[count-1] || count == 0); */
    /*@ assert (largest >= positions[0] || count == 0); */
    /*@ assert (largest >= 0 || count == 0); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest); */
    /*@ assert (largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0)); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest)); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest)); */
    /*@ assert (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0)); */
    /*@ assert (largest == 0 || (\exists integer i; 0 <= i < count && positions[i] == largest)); */
    /*@ assert (count > 0 ==> largest >= positions[count-1] || positions[count-1] <= 0); */
    /*@ assert (count == 0 ==> largest == 0); */
    /*@ assert (\forall integer k; count <= k < positions_len ==> positions[k] >= 0 || positions[k] <= largest); */
    /*@ assert (\forall integer k; count <= k < positions_len ==> positions[k] == positions[k]); */
    /*@ assert (\forall integer k; count <= k < positions_len ==> 0 <= positions[k] || positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] > 0 ==> positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= positions_len || positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] < 0); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= largest || largest == 0); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= 0 || positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count ==> largest >= positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < count ==> largest >= positions[k] || positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < count ==> (positions[k] > largest ==> positions[k] <= 0)); */
    /*@ assert (\forall integer k; 0 <= k < count ==> (positions[k] > 0 ==> positions[k] <= largest)); */
    /*@ assert (\forall integer k; 0 <= k < count ==> (positions[k] <= largest || positions[k] <= 0)); */
    /*@ assert (\forall integer k; 0 <= k < count ==> (positions[k] <= 0 || positions[k] <= largest)); */
    /*@ assert (\forall integer k; 0 <= k < count && positions[k] > largest ==> positions[k] <= 0); */
    /*@ assert (\forall integer k; 0 <= k < count && positions[k] > 0 ==> positions[k] <= largest); */
    /*@ assert (\forall integer k; 0 <= k < count && positions[k] <= 0 ==> largest >= 0); */
    /*@ assert (\forall integer i; 0 <= i < count ==> positions[i] <= largest || positions[i] <= 0); */
    /*@ assert (\forall integer i; 0 <= i < count && positions[i] > 0 ==> positions[i] <= largest); */
    /*@ assert (\exists integer k; 0 <= k < count ==> positions[k] == largest || largest == 0); */
    /*@ assert (\exists integer k; 0 <= k < count && positions[k] > 0 ==> largest > 0); */
    /*@ assert (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest || largest == 0); */
    /*@ assert (\exists integer k; 0 <= k < count && positions[k] == largest || largest == 0); */
    /*@ assert (\exists integer k; 0 <= k < count && positions[k] == largest ==> largest > 0); */
    /*@ assert (\exists integer i; 0 <= i < count && positions[i] == largest || largest == 0); */
    /*@ assert (0 <= largest); */
    /*@ assert (0 <= count); */
}

/*@ requires (largest >= positions[count-1] || count == 0) && (largest >= positions[0] || count == 0) && (largest >= 0 || count == 0) && (largest == 0 || \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest) && (largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest) && (largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0) && (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0)) && (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest)) && (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest)) && (largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0)) && (largest == 0 || (\exists integer i; 0 <= i < count && positions[i] == largest)) && (count > 0 ==> largest >= positions[count-1] || positions[count-1] <= 0) && (count == 0 ==> largest == 0) && (\forall integer k; count <= k < positions_len ==> positions[k] >= 0 || positions[k] <= largest) && (\forall integer k; count <= k < positions_len ==> positions[k] == positions[k]) && (\forall integer k; count <= k < positions_len ==> 0 <= positions[k] || positions[k] <= largest) && (\forall integer k; 0 <= k < count ==> positions[k] > 0 ==> positions[k] <= largest) && (\forall integer k; 0 <= k < count ==> positions[k] <= positions_len || positions[k] <= largest) && (\forall integer k; 0 <= k < count ==> positions[k] <= largest) && (\forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] <= 0) && (\forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] < 0) && (\forall integer k; 0 <= k < count ==> positions[k] <= largest || largest == 0) && (\forall integer k; 0 <= k < count ==> positions[k] <= 0 || positions[k] <= largest) && (\forall integer k; 0 <= k < count ==> largest >= positions[k]) && (\forall integer k; 0 <= k < count ==> largest >= positions[k] || positions[k] <= 0) && (\forall integer k; 0 <= k < count ==> (positions[k] > largest ==> positions[k] <= 0)) && (\forall integer k; 0 <= k < count ==> (positions[k] > 0 ==> positions[k] <= largest)) && (\forall integer k; 0 <= k < count ==> (positions[k] <= largest || positions[k] <= 0)) && (\forall integer k; 0 <= k < count ==> (positions[k] <= 0 || positions[k] <= largest)) && (\forall integer k; 0 <= k < count && positions[k] > largest ==> positions[k] <= 0) && (\forall integer k; 0 <= k < count && positions[k] > 0 ==> positions[k] <= largest) && (\forall integer k; 0 <= k < count && positions[k] <= 0 ==> largest >= 0) && (\forall integer i; 0 <= i < count ==> positions[i] <= largest || positions[i] <= 0) && (\forall integer i; 0 <= i < count && positions[i] > 0 ==> positions[i] <= largest) && (\exists integer k; 0 <= k < count ==> positions[k] == largest || largest == 0) && (\exists integer k; 0 <= k < count && positions[k] > 0 ==> largest > 0) && (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest || largest == 0) && (\exists integer k; 0 <= k < count && positions[k] == largest || largest == 0) && (\exists integer k; 0 <= k < count && positions[k] == largest ==> largest > 0) && (\exists integer i; 0 <= i < count && positions[i] == largest || largest == 0) && (0 <= largest) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int largest, int *positions, int positions_len) {
    /*@ assert (0 <= count <= positions_len); */
    /*@ assert (largest >= 0); */
    /*@ assert (positions_len == \at(positions_len,Pre)); */
    /*@ assert (positions == \at(positions,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < count ==> positions[k] <= largest); */
    /*@ assert (count == positions_len ==> (\forall integer k; 0 <= k < positions_len ==> positions[k] <= largest)); */
    /*@ assert ((count < \at(positions_len,Pre)) ==> (\forall integer k; 0 <= k < count ==> positions[k] <= largest)); */
    /*@ assert (\forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre)); */
}
