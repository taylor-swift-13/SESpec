#include <limits.h>

/*@ requires (2 <= x) && ((y < 2) || (x <= y)) && (x >= 2) && (y == \at(y,Pre)) && (x == 2 || x > 2) && ((x < y) ==> (x < y + 1)) && ((2 < \at(y,Pre)) ==> (x <= \at(y,Pre))) && ((2 < \at(y,Pre)) ==> (x <= y)) && ((2 < \at(y,Pre)) ==> (x >= 2)) && ((!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)))) && (y == \at(y,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int k, int x, int y) {
    /*@ assert (x == 2 || x > 2); */
    /*@ assert (x <= y || x >= y / x); */
    /*@ assert (x <= y || x >= 2); */
    /*@ assert (x <= y || x > y / x); */
    /*@ assert (\true); */
    /*@ assert (\forall integer k; 2 <= k < x ==> k <= y); */
    /*@ assert (2 <= x); */
    /*@ assert (0 < x); */
}

/*@ requires (x == 2 || x > 2) && (x <= y || x >= y / x) && (x <= y || x >= 2) && (x <= y || x > y / x) && (\true) && (\forall integer k; 2 <= k < x ==> k <= y) && (2 <= x) && (0 < x);
    assigns \nothing;
*/
void check_B_implies_A(int k, int x, int y) {
    /*@ assert (2 <= x); */
    /*@ assert ((y < 2) || (x <= y)); */
    /*@ assert (x >= 2); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x == 2 || x > 2); */
    /*@ assert ((x < y) ==> (x < y + 1)); */
    /*@ assert ((2 < \at(y,Pre)) ==> (x <= \at(y,Pre))); */
    /*@ assert ((2 < \at(y,Pre)) ==> (x <= y)); */
    /*@ assert ((2 < \at(y,Pre)) ==> (x >= 2)); */
    /*@ assert ((!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)))); */
    /*@ assert (y == \at(y,Pre)); */
}
