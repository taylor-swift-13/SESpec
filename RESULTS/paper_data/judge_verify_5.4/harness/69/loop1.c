#include <limits.h>

/*@ logic integer count_div3(integer x) =
    x <= 0 ? 0 : count_div3(x - 1) + (((x - 1) % 3) == 0 ? 1 : 0); */
/*@ logic integer count_div2not3(integer x) =
    x <= 0 ? 0 : count_div2not3(x - 1) + ((((x - 1) % 2) == 0 && ((x - 1) % 3) != 0) ? 1 : 0); */
/*@ logic integer count_other(integer x) =
    x <= 0 ? 0 : count_other(x - 1) + ((((x - 1) % 3) != 0 && ((x - 1) % 2) != 0) ? 1 : 0); */

/*@ requires (0 <= l <= n) && (0 <= i) && (0 <= j) && (0 <= k) && (i + j + k == l) && (i == count_div3(l)) && (j == count_div2not3(l)) && (k == count_other(l)) && (l == i + j + k) && (l <= n) && ((0 < \at(n,Pre)) ==> (i + j + k == l)) && ((0 < \at(n,Pre)) ==> (0 <= j && j <= n)) && ((0 < \at(n,Pre)) ==> (0 <= i && i <= n)) && ((0 < \at(n,Pre)) ==> (0 <= k && k <= n)) && ((0 < \at(n,Pre)) ==> (0 <= l && l <= n)) && ((!(0 < \at(n,Pre))) ==> ((l == 0) && (k == 0) && (i == 0) && (j == 0) && (n == \at(n,Pre)))) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n) {
    /*@ assert (l <= n); */
    /*@ assert (k == l - i - j); */
    /*@ assert (i == (l + 2) / 3); */
    /*@ assert (i + j + k == l); */
    /*@ assert (0 <= l); */
}

/*@ requires (l <= n) && (k == l - i - j) && (i == (l + 2) / 3) && (i + j + k == l) && (0 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n) {
    /*@ assert (0 <= l <= n); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= k); */
    /*@ assert (i + j + k == l); */
    /*@ assert (i == count_div3(l)); */
    /*@ assert (j == count_div2not3(l)); */
    /*@ assert (k == count_other(l)); */
    /*@ assert (l == i + j + k); */
    /*@ assert (l <= n); */
    /*@ assert ((0 < \at(n,Pre)) ==> (i + j + k == l)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= j && j <= n)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= i && i <= n)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= k && k <= n)); */
    /*@ assert ((0 < \at(n,Pre)) ==> (0 <= l && l <= n)); */
    /*@ assert ((!(0 < \at(n,Pre))) ==> ((l == 0) && (k == 0) && (i == 0) && (j == 0) && (n == \at(n,Pre)))); */
    /*@ assert (n == \at(n,Pre)); */
}
