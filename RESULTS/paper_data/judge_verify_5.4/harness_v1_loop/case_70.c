#include <limits.h>

/*@ requires (0 <= l <= n) && (0 <= j <= l) && (0 <= i <= l) && (0 <= k <= l) && (0 <= v4 <= l) && (v4 + i + j + k == l) && (j + i + k + v4 <= n) && (l >= v4) && (l >= i) && (l >= j) && (l >= k) && ((0 < \at(n,Pre)) ==> (v4 + i + j + k == l)) && ((0 < \at(n,Pre)) ==> (0 <= j <= l)) && ((0 < \at(n,Pre)) ==> (0 <= i <= l)) && ((0 < \at(n,Pre)) ==> (0 <= k <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v4 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= l <= n)) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n, int v4) {
    /*@ assert (l <= n) && (k <= l) && (i >= 0 && j >= 0 && k >= 0 && v4 >= 0) && (i + j + k + v4 == l) && (i + j + k + v4 <= l) && (0 <= v4) && (0 <= l) && (0 <= k) && (0 <= j) && (0 <= i); */
}

/*@ requires (l <= n) && (k <= l) && (i >= 0 && j >= 0 && k >= 0 && v4 >= 0) && (i + j + k + v4 == l) && (i + j + k + v4 <= l) && (0 <= v4) && (0 <= l) && (0 <= k) && (0 <= j) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n, int v4) {
    /*@ assert (0 <= l <= n) && (0 <= j <= l) && (0 <= i <= l) && (0 <= k <= l) && (0 <= v4 <= l) && (v4 + i + j + k == l) && (j + i + k + v4 <= n) && (l >= v4) && (l >= i) && (l >= j) && (l >= k) && ((0 < \at(n,Pre)) ==> (v4 + i + j + k == l)) && ((0 < \at(n,Pre)) ==> (0 <= j <= l)) && ((0 < \at(n,Pre)) ==> (0 <= i <= l)) && ((0 < \at(n,Pre)) ==> (0 <= k <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v4 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= l <= n)) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre)); */
}
