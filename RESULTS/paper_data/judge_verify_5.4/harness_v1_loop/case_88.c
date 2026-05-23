#include <limits.h>

/*@logic integer fourth_sum(integer n) =
    n <= 0 ? 0 : fourth_sum(n - 1) + n * n * n * n;*/

/*@ requires (0 <= c) && (c == y) && (x == fourth_sum(c)) && ((0 < \at(k,Pre)) ==> (c <= \at(k,Pre))) && ((0 < \at(k,Pre)) ==> (x == fourth_sum(c) && c == y && 0 <= c <= \at(k,Pre))) && ((0 < \at(k,Pre)) ==> (c == y)) && ((0 < \at(k,Pre)) ==> (x == fourth_sum(c))) && ((0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre))) && ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))) && (k == \at(k,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int t, int x, int y) {
    /*@ assert (y == c) && (x == y*y*y*y*(c ? 1 : 0) || x >= 0) && (x == y*y*y*y + x - (y*y*y*y)) && (x == y*y*y*y * c || x >= 0) && (x == \sum(0, c-1, \lambda integer t) && (c <= k) && (0 <= x) && (0 <= c); */
}

/*@ requires (y == c) && (x == y*y*y*y*(c ? 1 : 0) || x >= 0) && (x == y*y*y*y + x - (y*y*y*y)) && (x == y*y*y*y * c || x >= 0) && (x == \sum(0, c-1, \lambda integer t) && (c <= k) && (0 <= x) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int t, int x, int y) {
    /*@ assert (0 <= c) && (c == y) && (x == fourth_sum(c)) && ((0 < \at(k,Pre)) ==> (c <= \at(k,Pre))) && ((0 < \at(k,Pre)) ==> (x == fourth_sum(c) && c == y && 0 <= c <= \at(k,Pre))) && ((0 < \at(k,Pre)) ==> (c == y)) && ((0 < \at(k,Pre)) ==> (x == fourth_sum(c))) && ((0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre))) && ((!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)))) && (k == \at(k,Pre)); */
}
