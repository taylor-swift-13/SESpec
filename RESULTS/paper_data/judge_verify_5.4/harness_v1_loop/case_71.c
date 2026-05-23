#include <limits.h>

/*@logic integer count_mod5(integer x) =
    x <= 0 ? 0 : count_mod5(x - 1) + ((((x - 1) % 5) == 0) ? 1 : 0);

  logic integer count_mod4(integer x) =
    x <= 0 ? 0 : count_mod4(x - 1) + ((((x - 1) % 4) == 0 && ((x - 1) % 5) != 0) ? 1 : 0);

  logic integer count_mod3(integer x) =
    x <= 0 ? 0 : count_mod3(x - 1) + ((((x - 1) % 3) == 0 && ((x - 1) % 5) != 0 && ((x - 1) % 4) != 0) ? 1 : 0);

  logic integer count_mod2(integer x) =
    x <= 0 ? 0 : count_mod2(x - 1) + ((((x - 1) % 2) == 0 && ((x - 1) % 5) != 0 && ((x - 1) % 4) != 0 && ((x - 1) % 3) != 0) ? 1 : 0);*/

/*@ requires (0 <= l <= n) && (0 <= j <= l) && (0 <= i <= l) && (0 <= k <= l) && (0 <= v4 <= l) && (0 <= v3 <= l) && (n == \at(n,Pre)) && (l + j + i + k + v4 + v3 >= l) && (j == count_mod2(l)) && (i == count_mod3(l)) && (v4 == count_mod4(l)) && (v3 == count_mod5(l)) && (k + j + i + v4 + v3 == l) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t);
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n, int t, int v3, int v4) {
    /*@ assert (v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0) && (l <= n) && (k == l - v3 - v4 - i - j) && (i + j + k + v3 + v4 == l) && (0 <= v4) && (0 <= v3) && (0 <= l) && (0 <= k) && (0 <= j) && (0 <= i); */
}

/*@ requires (v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0) && (l <= n) && (k == l - v3 - v4 - i - j) && (i + j + k + v3 + v4 == l) && (0 <= v4) && (0 <= v3) && (0 <= l) && (0 <= k) && (0 <= j) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n, int t, int v3, int v4) {
    /*@ assert (0 <= l <= n) && (0 <= j <= l) && (0 <= i <= l) && (0 <= k <= l) && (0 <= v4 <= l) && (0 <= v3 <= l) && (n == \at(n,Pre)) && (l + j + i + k + v4 + v3 >= l) && (j == count_mod2(l)) && (i == count_mod3(l)) && (v4 == count_mod4(l)) && (v3 == count_mod5(l)) && (k + j + i + v4 + v3 == l) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t); */
}
