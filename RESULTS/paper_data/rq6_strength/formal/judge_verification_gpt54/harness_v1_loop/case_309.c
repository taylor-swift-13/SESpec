#include <limits.h>

/*@logic integer max0(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max0(a, lo, hi - 1) >= a[hi - 1] ? max0(a, lo, hi - 1) : a[hi - 1]);*/

/*@ requires (0 <= index <= positions_len) && (0 <= largest) && (largest == max0(positions, 0, index)) && (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *index, int k, int *largest, int *positions, int positions_len) {
    /*@ assert (largest >= positions[index-1] || index == 0) && (largest >= positions[index - 1] || index == 0) && (largest == 0 || largest >= positions[index-1]) && (largest == 0 || largest > 0) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \exists integer k) && (largest == 0 || \exists integer k) && (largest == 0 || \exists integer k) && (largest == 0 || (\forall integer k) && (largest == 0 || (\exists integer k) && (largest == 0 || (\exists integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= largest) && (0 <= index) && ((\forall integer k) && ((\forall integer k) && ((\forall integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k); */
}

/*@ requires (largest >= positions[index-1] || index == 0) && (largest >= positions[index - 1] || index == 0) && (largest == 0 || largest >= positions[index-1]) && (largest == 0 || largest > 0) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \forall integer k) && (largest == 0 || \exists integer k) && (largest == 0 || \exists integer k) && (largest == 0 || \exists integer k) && (largest == 0 || (\forall integer k) && (largest == 0 || (\exists integer k) && (largest == 0 || (\exists integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= largest) && (0 <= index) && ((\forall integer k) && ((\forall integer k) && ((\forall integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k) && ((\exists integer k);
    assigns \nothing;
*/
void check_B_implies_A(int *index, int k, int *largest, int *positions, int positions_len) {
    /*@ assert (0 <= index <= positions_len) && (0 <= largest) && (largest == max0(positions, 0, index)) && (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (\forall integer k); */
}
