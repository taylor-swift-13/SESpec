#include <limits.h>

/*@ requires (0 <= a) && (i == 1 + 2 * a) && (j == 1 + a) && (i - j == a) && (i % 2 == 1) && (j >= 1) && (b <= 0) && (2 * b + a * (a - 1) == 0) && (0 <= i) && (0 <= j) && (0 <= a) && (b <= 0);
    assigns \nothing;
*/
void check_A_implies_B(int a, int b, int i, int j) {
    /*@ assert (j == i / 2 + 1) && (j == a + 1) && (i == 2 * a + 1) && (i % 2 == 1) && (1 <= j) && (1 <= i) && (0 <= a); */
}

/*@ requires (j == i / 2 + 1) && (j == a + 1) && (i == 2 * a + 1) && (i % 2 == 1) && (1 <= j) && (1 <= i) && (0 <= a);
    assigns \nothing;
*/
void check_B_implies_A(int a, int b, int i, int j) {
    /*@ assert (0 <= a) && (i == 1 + 2 * a) && (j == 1 + a) && (i - j == a) && (i % 2 == 1) && (j >= 1) && (b <= 0) && (2 * b + a * (a - 1) == 0) && (0 <= i) && (0 <= j) && (0 <= a) && (b <= 0); */
}
