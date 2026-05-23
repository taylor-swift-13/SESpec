#include <limits.h>

/*@ requires (x == \at(x,Pre)) && (y == \at(y,Pre)) && (0 <= q) && (0 <= r) && (y * q + r <= x) && (x == \at(x,Pre)) && (y == \at(y,Pre)) && ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (x >= y * q + r)) && ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (0 <= q)) && ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))) || (0 <= r))) && ((!(\at(x,Pre) > \at(y,Pre) * 0 + 0)) ==> ((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre)))) && (y == \at(y,Pre)) && (x == \at(x,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *q, int r, int x, int y) {
    /*@ assert (x > y * q + r || x == y * q + r); */
    /*@ assert (x > y * q + r || x <= y * q + r); */
    /*@ assert (0 <= x - (y * q + r)); */
    /*@ assert (0 <= r); */
    /*@ assert (0 <= q); */
}

/*@ requires (x > y * q + r || x == y * q + r) && (x > y * q + r || x <= y * q + r) && (0 <= x - (y * q + r)) && (0 <= r) && (0 <= q);
    assigns \nothing;
*/
void check_B_implies_A(int *q, int r, int x, int y) {
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (0 <= q); */
    /*@ assert (0 <= r); */
    /*@ assert (y * q + r <= x); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (x >= y * q + r)); */
    /*@ assert ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (0 <= q)); */
    /*@ assert ((\at(x,Pre) > \at(y,Pre) * 0 + 0) ==> (((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))) || (0 <= r))); */
    /*@ assert ((!(\at(x,Pre) > \at(y,Pre) * 0 + 0)) ==> ((r == 0)&&(q == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre)))); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x == \at(x,Pre)); */
}
