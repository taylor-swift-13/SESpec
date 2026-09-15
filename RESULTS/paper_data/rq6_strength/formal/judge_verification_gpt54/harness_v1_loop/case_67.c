#include <limits.h>

/*@ requires (0 <= i) && (0 <= j <= i) && (0 <= k <= i) && (j + k == i) && (i % 3 == 0) && (j % 3 == 0) && (k % 3 == 0) && (i == j + k) && (0 <= i) && ((i < n) ==> (j + k < n + 2)) && ((i >= n) ==> (j + k >= n));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int n) {
    /*@ assert (k % 3 == 0) && (j <= i && k <= i) && (j + k == i) && (j % 3 == 0) && (i == j + k) && (i % 3 == 0) && (i % 2 == 0 || i % 2 == 1) && (0 <= k) && (0 <= j) && (0 <= i) && ((i % 2 == 0) ==> (k == i - j)) && ((i % 2 != 0) ==> (j == i - k)); */
}

/*@ requires (k % 3 == 0) && (j <= i && k <= i) && (j + k == i) && (j % 3 == 0) && (i == j + k) && (i % 3 == 0) && (i % 2 == 0 || i % 2 == 1) && (0 <= k) && (0 <= j) && (0 <= i) && ((i % 2 == 0) ==> (k == i - j)) && ((i % 2 != 0) ==> (j == i - k));
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int n) {
    /*@ assert (0 <= i) && (0 <= j <= i) && (0 <= k <= i) && (j + k == i) && (i % 3 == 0) && (j % 3 == 0) && (k % 3 == 0) && (i == j + k) && (0 <= i) && ((i < n) ==> (j + k < n + 2)) && ((i >= n) ==> (j + k >= n)); */
}
