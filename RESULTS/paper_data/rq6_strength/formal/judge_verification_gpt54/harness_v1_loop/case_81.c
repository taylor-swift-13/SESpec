#include <limits.h>

/*@ requires (0 <= c <= 36) && (z == 36 * y + c) && (z - c == 36 * y) && (0 <= z - 36 * y <= 36) && (36 * y <= z <= 36 * y + 36) && (x3 == \at(x3,Pre)) && (x2 == \at(x2,Pre)) && (x1 == \at(x1,Pre)) && (y == \at(y,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int x1, int x2, int x3, int y, int z) {
    /*@ assert (z == 36 * y + c) && (c <= 36) && (0 <= c); */
}

/*@ requires (z == 36 * y + c) && (c <= 36) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int x1, int x2, int x3, int y, int z) {
    /*@ assert (0 <= c <= 36) && (z == 36 * y + c) && (z - c == 36 * y) && (0 <= z - 36 * y <= 36) && (36 * y <= z <= 36 * y + 36) && (x3 == \at(x3,Pre)) && (x2 == \at(x2,Pre)) && (x1 == \at(x1,Pre)) && (y == \at(y,Pre)); */
}
