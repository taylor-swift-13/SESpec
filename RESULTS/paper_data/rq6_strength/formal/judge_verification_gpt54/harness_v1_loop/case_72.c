#include <limits.h>

/*@ requires (0 <= l <= n) && (v2 + v3 + v4 + i + j + k == l) && ((\forall integer t) && (v2 <= l) && (v3 <= l) && (v4 <= l) && (i <= l) && (j <= l) && (k <= l) && ((0 < \at(n,Pre)) ==> (j <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (i <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (k <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v3 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v2 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (l <= \at(n,Pre))) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n, int t, int v2, int v3, int v4) {
    /*@ assert (v4 <= l) && (v3 <= l) && (v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0) && (v2 == (l + 5) / 6) && (v2 <= l) && (v2 <= l / 6 + 1) && (l <= n) && (k <= l) && (j <= l) && (i <= l) && (i + j + k + v2 + v3 + v4 == l) && (0 <= l); */
}

/*@ requires (v4 <= l) && (v3 <= l) && (v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0) && (v2 == (l + 5) / 6) && (v2 <= l) && (v2 <= l / 6 + 1) && (l <= n) && (k <= l) && (j <= l) && (i <= l) && (i + j + k + v2 + v3 + v4 == l) && (0 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n, int t, int v2, int v3, int v4) {
    /*@ assert (0 <= l <= n) && (v2 + v3 + v4 + i + j + k == l) && ((\forall integer t) && (v2 <= l) && (v3 <= l) && (v4 <= l) && (i <= l) && (j <= l) && (k <= l) && ((0 < \at(n,Pre)) ==> (j <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (i <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (k <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v3 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (v2 <= \at(n,Pre))) && ((0 < \at(n,Pre)) ==> (l <= \at(n,Pre))) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre)); */
}
