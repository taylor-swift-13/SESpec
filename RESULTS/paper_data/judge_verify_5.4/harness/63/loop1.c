#include <limits.h>

/*@ requires (0 <= a) && (0 <= b) && (0 <= i) && (1 <= j) && (i == 2 * a) && (j == i + 1) && (b == a) && (i % 2 == 0) && (j % 2 == 1) && (a == b) && (a <= i) && (b <= i) && (j > i) && (\exists integer k; 0 <= k <= a && i == 2 * k) && (\exists integer k; 0 <= k <= a && j == 2 * k + 1) && (\exists integer k; 0 <= k <= a && b == k);
    assigns \nothing;
*/
void check_A_implies_B(int *a, int b, int i, int j, int *k) {
    /*@ assert (j == i + 1); */
    /*@ assert (j % 2 == 1); */
    /*@ assert (i % 2 == 0); */
    /*@ assert (b == a); */
    /*@ assert (b == a + j - i - 1); */
    /*@ assert (a == i / 2); */
    /*@ assert (a == b); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= a); */
}

/*@ requires (j == i + 1) && (j % 2 == 1) && (i % 2 == 0) && (b == a) && (b == a + j - i - 1) && (a == i / 2) && (a == b) && (1 <= j) && (0 <= j) && (0 <= i) && (0 <= a);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int b, int i, int j, int *k) {
    /*@ assert (0 <= a); */
    /*@ assert (0 <= b); */
    /*@ assert (0 <= i); */
    /*@ assert (1 <= j); */
    /*@ assert (i == 2 * a); */
    /*@ assert (j == i + 1); */
    /*@ assert (b == a); */
    /*@ assert (i % 2 == 0); */
    /*@ assert (j % 2 == 1); */
    /*@ assert (a == b); */
    /*@ assert (a <= i); */
    /*@ assert (b <= i); */
    /*@ assert (j > i); */
    /*@ assert (\exists integer k; 0 <= k <= a && i == 2 * k); */
    /*@ assert (\exists integer k; 0 <= k <= a && j == 2 * k + 1); */
    /*@ assert (\exists integer k; 0 <= k <= a && b == k); */
}
