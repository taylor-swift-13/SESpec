#include <limits.h>

/*@ requires ((\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre))) && ((\at(mid,Pre) > 0) ==> (hi + lo == 2 * \at(mid,Pre))) && ((\at(mid,Pre) > 0) ==> (lo >= 0)) && ((\at(mid,Pre) > 0) ==> (hi >= 0)) && ((!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int hi, int lo, int *mid) {
    /*@ assert (lo == 0 + (2 * (hi - 2 * mid)) / 2); */
    /*@ assert (lo + mid == hi - mid); */
    /*@ assert (lo + mid == 0 + \at(mid,Pre)); */
    /*@ assert (lo + hi == 2 * (lo + mid)); */
    /*@ assert (hi == 2*mid + lo); */
    /*@ assert (hi == 2 * mid + lo); */
    /*@ assert (0 <= lo); */
}

/*@ requires (lo == 0 + (2 * (hi - 2 * mid)) / 2) && (lo + mid == hi - mid) && (lo + mid == 0 + \at(mid,Pre)) && (lo + hi == 2 * (lo + mid)) && (hi == 2*mid + lo) && (hi == 2 * mid + lo) && (0 <= lo);
    assigns \nothing;
*/
void check_B_implies_A(int hi, int lo, int *mid) {
    /*@ assert ((\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre))); */
    /*@ assert ((\at(mid,Pre) > 0) ==> (hi + lo == 2 * \at(mid,Pre))); */
    /*@ assert ((\at(mid,Pre) > 0) ==> (lo >= 0)); */
    /*@ assert ((\at(mid,Pre) > 0) ==> (hi >= 0)); */
    /*@ assert ((!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)))); */
}
