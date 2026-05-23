#include <limits.h>

/*@ predicate cube_progress(integer k0, integer c, integer x, integer y) =
    x == c * c * c && y == c && c <= k0; */

/*@ requires ((0 < \at(k,Pre)) ==> (y == c)) && ((0 < \at(k,Pre)) ==> (0 <= c <= k)) && ((0 < \at(k,Pre)) ==> (k == \at(k,Pre))) && ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))) && (k == \at(k,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int k, int x, int *y) {
    /*@ assert (y*y*y <= x); */
    /*@ assert (y == c); */
    /*@ assert (x == y*y*y*x || x >= 0); */
    /*@ assert (x == y*y*y - y); */
    /*@ assert (x == y*y*y + x - y*y*y); */
    /*@ assert (x == y*y*y * c); */
    /*@ assert (x == y * y * y + x - (y * y * y)); */
    /*@ assert (x == c * c * c); */
    /*@ assert (c <= k); */
    /*@ assert (0 <= x); */
    /*@ assert (0 <= c); */
}

/*@ requires (y*y*y <= x) && (y == c) && (x == y*y*y*x || x >= 0) && (x == y*y*y - y) && (x == y*y*y + x - y*y*y) && (x == y*y*y * c) && (x == y * y * y + x - (y * y * y)) && (x == c * c * c) && (c <= k) && (0 <= x) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int k, int x, int *y) {
    /*@ assert ((0 < \at(k,Pre)) ==> (y == c)); */
    /*@ assert ((0 < \at(k,Pre)) ==> (0 <= c <= k)); */
    /*@ assert ((0 < \at(k,Pre)) ==> (k == \at(k,Pre))); */
    /*@ assert ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))); */
    /*@ assert (k == \at(k,Pre)); */
}
