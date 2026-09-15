#include <limits.h>

/*@ predicate foo86_y(integer kpre, integer c, integer y) = y == c; */
/*@ predicate foo86_x(integer kpre, integer c, integer x) = x == c * (c + 1) * (2 * c + 1) / 6; */
/*@ predicate foo86_c(integer kpre, integer c) = c >= 0; */
/*@ predicate foo86_goal(integer kpre, integer c, integer x, integer y) = x >= y * y; */

/*@ requires ((0 < \at(k,Pre)) ==> (foo86_goal(\at(k,Pre), c, x, y))) && ((0 < \at(k,Pre)) ==> (foo86_y(\at(k,Pre), c, y))) && ((0 < \at(k,Pre)) ==> (foo86_x(\at(k,Pre), c, x))) && ((0 < \at(k,Pre)) ==> (foo86_c(\at(k,Pre), c))) && ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))) && (k == \at(k,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int k, int t, int x, int *y) {
    /*@ assert (y == c); */
    /*@ assert (x == y * y); */
    /*@ assert (x == y * y * c); */
    /*@ assert (x == c * c); */
    /*@ assert (x == c * c * (c + 1) / 2); */
    /*@ assert (x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1))); */
    /*@ assert (c <= k); */
    /*@ assert (0 <= x); */
    /*@ assert (0 <= c); */
}

/*@ requires (y == c) && (x == y * y) && (x == y * y * c) && (x == c * c) && (x == c * c * (c + 1) / 2) && (x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1))) && (c <= k) && (0 <= x) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int k, int t, int x, int *y) {
    /*@ assert ((0 < \at(k,Pre)) ==> (foo86_goal(\at(k,Pre), c, x, y))); */
    /*@ assert ((0 < \at(k,Pre)) ==> (foo86_y(\at(k,Pre), c, y))); */
    /*@ assert ((0 < \at(k,Pre)) ==> (foo86_x(\at(k,Pre), c, x))); */
    /*@ assert ((0 < \at(k,Pre)) ==> (foo86_c(\at(k,Pre), c))); */
    /*@ assert ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))); */
    /*@ assert (k == \at(k,Pre)); */
}
