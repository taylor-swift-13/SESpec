#include <limits.h>

/*@ requires (a >= 0) && (b >= 0) && (p >= 1) && (a == 0 || b == 0 || (a > 0 && b > 0)) && (a <= \at(x,Pre) || b <= \at(y,Pre)) && (p == 1 || p >= 4) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a >= 0 && b >= 0 && p >= 1)) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a == 0 || b == 0 || (a > 0 && b > 0))) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (p >= 1)) && (y == \at(y,Pre)) && (x == \at(x,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int a, int b, int p, int q, int x, int y) {
    /*@ assert (q + a * b * p == x * y) && (p == 4 || p >= 1) && (p == 4 || p == 1 || p > 1) && (p == 1 || p % 4 == 0) && (p == 1 || p % 2 == 0) && (a >= 0 && b >= 0) && (a == 0 || b == 0 || (a != 0 && b != 0)) && (a != 0 && b != 0 ==> (a * b * p + q >= 0)) && (\true) && (1 <= p) && (0 <= q) && (0 <= p*q) && (0 <= b) && (0 <= a) && (0 < p) && ((a == 0 || b == 0) || (p >= 1)); */
}

/*@ requires (q + a * b * p == x * y) && (p == 4 || p >= 1) && (p == 4 || p == 1 || p > 1) && (p == 1 || p % 4 == 0) && (p == 1 || p % 2 == 0) && (a >= 0 && b >= 0) && (a == 0 || b == 0 || (a != 0 && b != 0)) && (a != 0 && b != 0 ==> (a * b * p + q >= 0)) && (\true) && (1 <= p) && (0 <= q) && (0 <= p*q) && (0 <= b) && (0 <= a) && (0 < p) && ((a == 0 || b == 0) || (p >= 1));
    assigns \nothing;
*/
void check_B_implies_A(int a, int b, int p, int q, int x, int y) {
    /*@ assert (a >= 0) && (b >= 0) && (p >= 1) && (a == 0 || b == 0 || (a > 0 && b > 0)) && (a <= \at(x,Pre) || b <= \at(y,Pre)) && (p == 1 || p >= 4) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a >= 0 && b >= 0 && p >= 1)) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (a == 0 || b == 0 || (a > 0 && b > 0))) && ((\at(x,Pre) != 0 && \at(y,Pre) != 0) ==> (p >= 1)) && (y == \at(y,Pre)) && (x == \at(x,Pre)); */
}
