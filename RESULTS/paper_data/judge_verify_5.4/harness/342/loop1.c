#include <limits.h>

/*@ logic integer count_nondiv(integer code, integer l, integer u) =
    u < l ? 0 :
    count_nondiv(code, l, u - 1) + ((u % code != 0) ? 1 : 0); */

/*@ requires (c >= l) && (0 <= result) && (result == count_nondiv(code, l, c - 1)) && (0 <= result <= c - l) && (result == 0 || (\exists integer i; l <= i < c && i % code != 0)) && (m == \at(m,Pre)) && (l == \at(l,Pre)) && (b == \at(b,Pre)) && (code == \at(code,Pre)) && ((c > m) ==> (result == count_nondiv(code, l, m)));
    assigns \nothing;
*/
void check_A_implies_B(int b, int c, int code, int i, int k, int l, int m, int t) {
    /*@ assert (result > 0 ==> l <= c); */
    /*@ assert (result > 0 ==> l < c); */
    /*@ assert (result > 0 ==> c > l); */
    /*@ assert (result > 0 ==> \exists integer k; l <= k < c && k % code != 0); */
    /*@ assert (result > 0 ==> \exists integer i; l <= i < c && i % code != 0); */
    /*@ assert (result == c - l ==> \forall integer k; l <= k < c ==> k % code != 0); */
    /*@ assert (result == c - l ==> \forall integer i; l <= i < c ==> i % code != 0); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 ==> \forall integer k; l <= k < c ==> k % code == 0); */
    /*@ assert (result == 0 ==> \forall integer i; l <= i < c ==> i % code == 0); */
    /*@ assert (result <= c - l); */
    /*@ assert (result <= c - l + 1); */
    /*@ assert (result < b ==> result <= c - l); */
    /*@ assert (result < b ==> result <= c - l + 1); */
    /*@ assert (result < b ==> result <= b); */
    /*@ assert (result < b ==> result < c - l + 1); */
    /*@ assert (result < b ==> result < b); */
    /*@ assert (result < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result > 0)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0)); */
    /*@ assert (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0)); */
    /*@ assert (result < b ==> \exists integer t; l <= t < c && t % code != 0 ==> result > 0); */
    /*@ assert (l <= c); */
    /*@ assert (\forall integer t; l <= t < c && t % code != 0 ==> result >= 1); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code == 0 || result >= 1)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code == 0 ==> result <= c - l)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> i <= m); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code == 0 || result >= 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code == 0 || result > 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code == 0 ==> result >= 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code == 0 ==> result <= c - l)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0)); */
    /*@ assert (\forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0)); */
    /*@ assert (\exists integer t; l <= t <= c ==> t % code != 0); */
    /*@ assert (\exists integer t; l <= t < c ==> t % code != 0); */
    /*@ assert (\exists integer t; l <= t < c && t % code != 0 ==> result >= 1); */
    /*@ assert (\exists integer t; l <= t < c && t % code != 0 ==> result >= 0); */
    /*@ assert (\exists integer t; l <= t < c && t % code != 0 ==> result > 0); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= c - l - result); */
}

/*@ requires (result > 0 ==> l <= c) && (result > 0 ==> l < c) && (result > 0 ==> c > l) && (result > 0 ==> \exists integer k; l <= k < c && k % code != 0) && (result > 0 ==> \exists integer i; l <= i < c && i % code != 0) && (result == c - l ==> \forall integer k; l <= k < c ==> k % code != 0) && (result == c - l ==> \forall integer i; l <= i < c ==> i % code != 0) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result == 0 ==> \forall integer k; l <= k < c ==> k % code == 0) && (result == 0 ==> \forall integer i; l <= i < c ==> i % code == 0) && (result <= c - l) && (result <= c - l + 1) && (result < b ==> result <= c - l) && (result < b ==> result <= c - l + 1) && (result < b ==> result <= b) && (result < b ==> result < c - l + 1) && (result < b ==> result < b) && (result < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result > 0)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0)) && (result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0)) && (result < b ==> \exists integer t; l <= t < c && t % code != 0 ==> result > 0) && (l <= c) && (\forall integer t; l <= t < c && t % code != 0 ==> result >= 1) && (\forall integer k; l <= k < c ==> (k % code == 0 || result >= 1)) && (\forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)) && (\forall integer k; l <= k < c ==> (k % code == 0 ==> result >= 0)) && (\forall integer k; l <= k < c ==> (k % code == 0 ==> result <= c - l)) && (\forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 1)) && (\forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 0)) && (\forall integer i; l <= i < c ==> i <= m) && (\forall integer i; l <= i < c ==> (i % code == 0 || result >= 0)) && (\forall integer i; l <= i < c ==> (i % code == 0 || result > 0)) && (\forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0)) && (\forall integer i; l <= i < c ==> (i % code == 0 ==> result >= 0)) && (\forall integer i; l <= i < c ==> (i % code == 0 ==> result <= c - l)) && (\forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1)) && (\forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0)) && (\forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0)) && (\exists integer t; l <= t <= c ==> t % code != 0) && (\exists integer t; l <= t < c ==> t % code != 0) && (\exists integer t; l <= t < c && t % code != 0 ==> result >= 1) && (\exists integer t; l <= t < c && t % code != 0 ==> result >= 0) && (\exists integer t; l <= t < c && t % code != 0 ==> result > 0) && (0 <= result) && (0 <= c - l - result);
    assigns \nothing;
*/
void check_B_implies_A(int b, int c, int code, int i, int k, int l, int m, int t) {
    /*@ assert (c >= l); */
    /*@ assert (0 <= result); */
    /*@ assert (result == count_nondiv(code, l, c - 1)); */
    /*@ assert (0 <= result <= c - l); */
    /*@ assert (result == 0 || (\exists integer i; l <= i < c && i % code != 0)); */
    /*@ assert (m == \at(m,Pre)); */
    /*@ assert (l == \at(l,Pre)); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert (code == \at(code,Pre)); */
    /*@ assert ((c > m) ==> (result == count_nondiv(code, l, m))); */
}
