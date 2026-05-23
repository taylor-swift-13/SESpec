#include <limits.h>

/*@ logic integer pow5(integer v) = v * v * v * v * v; */
/*@ logic integer sum_pow5(integer n) =
    n <= 0 ? 0 : sum_pow5(n - 1) + pow5(n); */

/*@ requires ((0 < \at(k,Pre)) ==> (x == sum_pow5(c))) && ((0 < \at(k,Pre)) ==> (y == c)) && ((0 < \at(k,Pre)) ==> (c <= k)) && ((0 < \at(k,Pre)) ==> (c >= 0)) && ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))) && (k == \at(k,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int t, int x, int y) {
    /*@ assert (y == c); */
    /*@ assert (x == y*y*y*y*y); */
    /*@ assert (c <= k); */
    /*@ assert (\exists integer t; t == c && y == t); */
    /*@ assert (0 <= x); */
    /*@ assert (0 <= c); */
}

/*@ requires (y == c) && (x == y*y*y*y*y) && (c <= k) && (\exists integer t; t == c && y == t) && (0 <= x) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int t, int x, int y) {
    /*@ assert ((0 < \at(k,Pre)) ==> (x == sum_pow5(c))); */
    /*@ assert ((0 < \at(k,Pre)) ==> (y == c)); */
    /*@ assert ((0 < \at(k,Pre)) ==> (c <= k)); */
    /*@ assert ((0 < \at(k,Pre)) ==> (c >= 0)); */
    /*@ assert ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))); */
    /*@ assert (k == \at(k,Pre)); */
}
