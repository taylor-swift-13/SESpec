#include <limits.h>

/*@ requires (x == 4 * y) && (y <= \at(y, Pre)) && (x % 4 == 0) && ((4 * \at(y, Pre) > 0) ==> (x == 4 * y)) && ((4 * \at(y, Pre) > 0) ==> (0 <= y)) && ((4 * \at(y, Pre) > 0) ==> (0 <= x)) && ((!(4 * \at(y, Pre) > 0)) ==> ((x == 4 * \at(y, Pre)) && (y == \at(y, Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int x, int *y) {
    /*@ assert (x == 4 * y); */
}

/*@ requires (x == 4 * y);
    assigns \nothing;
*/
void check_B_implies_A(int x, int *y) {
    /*@ assert (x == 4 * y); */
    /*@ assert (y <= \at(y, Pre)); */
    /*@ assert (x % 4 == 0); */
    /*@ assert ((4 * \at(y, Pre) > 0) ==> (x == 4 * y)); */
    /*@ assert ((4 * \at(y, Pre) > 0) ==> (0 <= y)); */
    /*@ assert ((4 * \at(y, Pre) > 0) ==> (0 <= x)); */
    /*@ assert ((!(4 * \at(y, Pre) > 0)) ==> ((x == 4 * \at(y, Pre)) && (y == \at(y, Pre)))); */
}
