#include <limits.h>

/*@ requires (0 <= a) && (0 <= b) && (0 <= i) && (1 <= j) && (i == 2 * a) && (j == i + 1) && (b == a) && (i % 2 == 0) && (j % 2 == 1) && (a == b) && (a <= i) && (b <= i) && (j > i) && (\exists integer k) && (\exists integer k) && (\exists integer k);
    assigns \nothing;
*/
void check_A_implies_B(int a, int b, int i, int j, int k) {
    /*@ assert (j == i + 1) && (j % 2 == 1) && (i % 2 == 0) && (b == a) && (b == a + j - i - 1) && (a == i / 2) && (a == b) && (1 <= j) && (0 <= j) && (0 <= i) && (0 <= a); */
}

/*@ requires (j == i + 1) && (j % 2 == 1) && (i % 2 == 0) && (b == a) && (b == a + j - i - 1) && (a == i / 2) && (a == b) && (1 <= j) && (0 <= j) && (0 <= i) && (0 <= a);
    assigns \nothing;
*/
void check_B_implies_A(int a, int b, int i, int j, int k) {
    /*@ assert (0 <= a) && (0 <= b) && (0 <= i) && (1 <= j) && (i == 2 * a) && (j == i + 1) && (b == a) && (i % 2 == 0) && (j % 2 == 1) && (a == b) && (a <= i) && (b <= i) && (j > i) && (\exists integer k) && (\exists integer k) && (\exists integer k); */
}
