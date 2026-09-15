#include <limits.h>

/*@ requires (x <= w) && (0 <= w) && (y % 2 == 0) && (z == 10 * w) && (x >= 0) && (z >= 0) && (x <= w) && (w >= x) && (z == 10 * w) && (y % 2 == 0);
    assigns \nothing;
*/
void check_A_implies_B(int w, int x, int y, int z) {
    /*@ assert (z == 10*w) && (z == 10 * w) && (y >= 0 || y <= 0) && (x <= w) && (x <= w + 1) && (0 <= z) && (0 <= x) && (0 <= w); */
}

/*@ requires (z == 10*w) && (z == 10 * w) && (y >= 0 || y <= 0) && (x <= w) && (x <= w + 1) && (0 <= z) && (0 <= x) && (0 <= w);
    assigns \nothing;
*/
void check_B_implies_A(int w, int x, int y, int z) {
    /*@ assert (x <= w) && (0 <= w) && (y % 2 == 0) && (z == 10 * w) && (x >= 0) && (z >= 0) && (x <= w) && (w >= x) && (z == 10 * w) && (y % 2 == 0); */
}
