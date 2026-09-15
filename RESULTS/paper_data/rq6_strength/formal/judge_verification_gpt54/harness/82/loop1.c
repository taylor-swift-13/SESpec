#include <limits.h>

/*@ requires ((1 < \at(k,Pre)) ==> (c >= 1)) && ((1 < \at(k,Pre)) ==> (k == \at(k,Pre))) && ((1 < \at(k,Pre)) ==> (z == \at(z,Pre))) && ((!(1 < \at(k,Pre))) ==> ((c == 1)&&(y == 1)&&(x == 1)&&(k == \at(k,Pre))&&(z == \at(z,Pre)))) && (k == \at(k,Pre)) && (z == \at(z,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int x, int y, int z) {
    /*@ assert (y == 1); */
    /*@ assert (x == (z^(c-1) - 1) / (z - 1) + 1); */
    /*@ assert (c <= k); */
    /*@ assert (1 <= x); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= c - 1); */
}

/*@ requires (y == 1) && (x == (z^(c-1) - 1) / (z - 1) + 1) && (c <= k) && (1 <= x) && (1 <= c) && (0 <= c - 1);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int x, int y, int z) {
    /*@ assert ((1 < \at(k,Pre)) ==> (c >= 1)); */
    /*@ assert ((1 < \at(k,Pre)) ==> (k == \at(k,Pre))); */
    /*@ assert ((1 < \at(k,Pre)) ==> (z == \at(z,Pre))); */
    /*@ assert ((!(1 < \at(k,Pre))) ==> ((c == 1)&&(y == 1)&&(x == 1)&&(k == \at(k,Pre))&&(z == \at(z,Pre)))); */
    /*@ assert (k == \at(k,Pre)); */
    /*@ assert (z == \at(z,Pre)); */
}
