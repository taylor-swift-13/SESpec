#include <limits.h>

/*@ requires (x <= w) && (0 <= w) && (y % 2 == 0) && (z == 10 * w) && (x >= 0) && (z >= 0) && (x <= w) && (w >= x) && (z == 10 * w) && (y % 2 == 0);
    assigns \nothing;
*/
void check_A_implies_B(int *w, int x, int y, int z) {
    /*@ assert (z == 10*w); */
    /*@ assert (z == 10 * w); */
    /*@ assert (y >= 0 || y <= 0); */
    /*@ assert (x <= w); */
    /*@ assert (x <= w + 1); */
    /*@ assert (0 <= z); */
    /*@ assert (0 <= x); */
    /*@ assert (0 <= w); */
}

/*@ requires (z == 10*w) && (z == 10 * w) && (y >= 0 || y <= 0) && (x <= w) && (x <= w + 1) && (0 <= z) && (0 <= x) && (0 <= w);
    assigns \nothing;
*/
void check_B_implies_A(int *w, int x, int y, int z) {
    /*@ assert (x <= w); */
    /*@ assert (0 <= w); */
    /*@ assert (y % 2 == 0); */
    /*@ assert (z == 10 * w); */
    /*@ assert (x >= 0); */
    /*@ assert (z >= 0); */
    /*@ assert (x <= w); */
    /*@ assert (w >= x); */
    /*@ assert (z == 10 * w); */
    /*@ assert (y % 2 == 0); */
}
