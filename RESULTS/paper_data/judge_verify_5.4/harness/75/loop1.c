#include <limits.h>

/*@ logic integer count_div9(integer l) =
    l <= 0 ? 0 : count_div9(l - 1) + ((l - 1) % 9 == 0 ? 1 : 0); */
/*@ logic integer count_div8_only(integer l) =
    l <= 0 ? 0 : count_div8_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 == 0) ? 1 : 0); */
/*@ logic integer count_div7_only(integer l) =
    l <= 0 ? 0 : count_div7_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 == 0) ? 1 : 0); */
/*@ logic integer count_div6_only(integer l) =
    l <= 0 ? 0 : count_div6_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 == 0) ? 1 : 0); */
/*@ logic integer count_div5_only(integer l) =
    l <= 0 ? 0 : count_div5_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 == 0) ? 1 : 0); */
/*@ logic integer count_div4_only(integer l) =
    l <= 0 ? 0 : count_div4_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 == 0) ? 1 : 0); */
/*@ logic integer count_div3_only(integer l) =
    l <= 0 ? 0 : count_div3_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 == 0) ? 1 : 0); */
/*@ logic integer count_div2_only(integer l) =
    l <= 0 ? 0 : count_div2_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 != 0 && (l - 1) % 2 == 0) ? 1 : 0); */
/*@ logic integer count_other(integer l) =
    l <= 0 ? 0 : count_other(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 != 0 && (l - 1) % 2 != 0) ? 1 : 0); */

/*@ requires (0 <= l <= n) && (0 <= j <= n) && (0 <= i <= n) && (0 <= k <= n) && (0 <= v4 <= n) && (0 <= v3 <= n) && (0 <= v2 <= n) && (0 <= v1 <= n) && (0 <= v5 <= n) && (0 <= v6 <= n) && (v6 == count_div9(l)) && (v5 == count_div8_only(l)) && (v1 == count_div7_only(l)) && (v2 == count_div6_only(l)) && (v3 == count_div5_only(l)) && (v4 == count_div4_only(l)) && (i == count_div3_only(l)) && (j == count_div2_only(l)) && (k == count_other(l)) && (l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k) && ((l < n) ==> (l % 9 == 0 || l % 8 == 0 || l % 7 == 0 || l % 6 == 0 || l % 5 == 0 || l % 4 == 0 || l % 3 == 0 || l % 2 == 0 || l % 2 != 0)) && ((l == 0) ==> (v6 == 0 && v5 == 0 && v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0 && i == 0 && j == 0 && k == 0)) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int k, int l, int n, int v1, int v2, int v3, int v4, int v5, int v6) {
    /*@ assert (l <= n); */
    /*@ assert (i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0 && v6 >= 0); */
    /*@ assert (i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == l); */
    /*@ assert (0 <= v6); */
    /*@ assert (0 <= v5); */
    /*@ assert (0 <= v4); */
    /*@ assert (0 <= v3); */
    /*@ assert (0 <= v2); */
    /*@ assert (0 <= v1); */
    /*@ assert (0 <= l); */
    /*@ assert (0 <= k); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= i); */
}

/*@ requires (l <= n) && (i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0 && v6 >= 0) && (i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == l) && (0 <= v6) && (0 <= v5) && (0 <= v4) && (0 <= v3) && (0 <= v2) && (0 <= v1) && (0 <= l) && (0 <= k) && (0 <= j) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int k, int l, int n, int v1, int v2, int v3, int v4, int v5, int v6) {
    /*@ assert (0 <= l <= n); */
    /*@ assert (0 <= j <= n); */
    /*@ assert (0 <= i <= n); */
    /*@ assert (0 <= k <= n); */
    /*@ assert (0 <= v4 <= n); */
    /*@ assert (0 <= v3 <= n); */
    /*@ assert (0 <= v2 <= n); */
    /*@ assert (0 <= v1 <= n); */
    /*@ assert (0 <= v5 <= n); */
    /*@ assert (0 <= v6 <= n); */
    /*@ assert (v6 == count_div9(l)); */
    /*@ assert (v5 == count_div8_only(l)); */
    /*@ assert (v1 == count_div7_only(l)); */
    /*@ assert (v2 == count_div6_only(l)); */
    /*@ assert (v3 == count_div5_only(l)); */
    /*@ assert (v4 == count_div4_only(l)); */
    /*@ assert (i == count_div3_only(l)); */
    /*@ assert (j == count_div2_only(l)); */
    /*@ assert (k == count_other(l)); */
    /*@ assert (l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k); */
    /*@ assert ((l < n) ==> (l % 9 == 0 || l % 8 == 0 || l % 7 == 0 || l % 6 == 0 || l % 5 == 0 || l % 4 == 0 || l % 3 == 0 || l % 2 == 0 || l % 2 != 0)); */
    /*@ assert ((l == 0) ==> (v6 == 0 && v5 == 0 && v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0 && i == 0 && j == 0 && k == 0)); */
    /*@ assert (n == \at(n,Pre)); */
}
