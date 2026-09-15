#include <limits.h>

/*@ requires (0 <= l <= n) && (0 <= j <= l) && (0 <= i <= l) && (0 <= k <= l) && (0 <= v4 <= l) && (0 <= v3 <= l) && (0 <= v2 <= l) && (0 <= v1 <= l) && (0 <= v5 <= l) && (i + j + k + v1 + v2 + v3 + v4 + v5 == l) && (v5 <= l) && (v1 <= l) && (v2 <= l) && (v3 <= l) && (v4 <= l) && (i <= l) && (j <= l) && (k <= l) && (n == \at(n,Pre)) && ((0 < \at(n,Pre)) ==> (0 <= j <= l)) && ((0 < \at(n,Pre)) ==> (0 <= i <= l)) && ((0 < \at(n,Pre)) ==> (0 <= k <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v4 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v3 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v2 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v1 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= v5 <= l)) && ((0 < \at(n,Pre)) ==> (0 <= l <= n)) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n, int v1, int v2, int v3, int v4, int v5) {
    /*@ assert (v5 <= l); */
    /*@ assert (v4 <= l); */
    /*@ assert (v3 <= l); */
    /*@ assert (v2 <= l); */
    /*@ assert (v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0); */
    /*@ assert (v1 <= l); */
    /*@ assert (l <= n); */
    /*@ assert (i >= 0 && j >= 0 && k >= 0); */
    /*@ assert (i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0); */
    /*@ assert (i + j + k + v1 + v2 + v3 + v4 + v5 == l); */
    /*@ assert (0 <= l); */
}

/*@ requires (v5 <= l) && (v4 <= l) && (v3 <= l) && (v2 <= l) && (v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0) && (v1 <= l) && (l <= n) && (i >= 0 && j >= 0 && k >= 0) && (i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0) && (i + j + k + v1 + v2 + v3 + v4 + v5 == l) && (0 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n, int v1, int v2, int v3, int v4, int v5) {
    /*@ assert (0 <= l <= n); */
    /*@ assert (0 <= j <= l); */
    /*@ assert (0 <= i <= l); */
    /*@ assert (0 <= k <= l); */
    /*@ assert (0 <= v4 <= l); */
    /*@ assert (0 <= v3 <= l); */
    /*@ assert (0 <= v2 <= l); */
    /*@ assert (0 <= v1 <= l); */
    /*@ assert (0 <= v5 <= l); */
    /*@ assert (i + j + k + v1 + v2 + v3 + v4 + v5 == l); */
    /*@ assert (v5 <= l); */
    /*@ assert (v1 <= l); */
    /*@ assert (v2 <= l); */
    /*@ assert (v3 <= l); */
    /*@ assert (v4 <= l); */
    /*@ assert (i <= l); */
    /*@ assert (j <= l); */
    /*@ assert (k <= l); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= j <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= i <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= k <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= v4 <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= v3 <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= v2 <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= v1 <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= v5 <= l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= l <= n)); */
    /*@ assert ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))); */
}
