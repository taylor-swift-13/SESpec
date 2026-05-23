#include <limits.h>

/*@logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n - 1) + n * n * n * n;*/

/*@ requires (1 <= c) && (c <= \at(p,Pre) + 1 || \at(p,Pre) < 0) && (even == 16 * sum4(c - 1)) && ((c <= \at(p,Pre)) ==> (even == 16 * sum4(c - 1))) && (p == \at(p,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int even, int k, int p, int t) {
    /*@ assert (even == 0 || even >= 0) && (even == 0 || even > 0) && (even == 0 ==> c == 1) && (even <= even + 1) && (even % 2 == 0) && (even % 2 == 0 || even % 2 == 1) && (c > 1 ==> even >= 0) && (c > 1 ==> even > 0) && (c == 1 || c > 1) && (c == 1 || c <= p + 1) && (c == 1 ==> even == 0) && (c <= p+1 || 0 <= c) && (c <= p + 1 || 0 <= c) && (c <= p + 1 ==> even >= 0) && (c <= p + 1 ==> even % 2 == 0) && (c % 2 == 1 || c % 2 == 0) && (c % 2 == 0 || c % 2 == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer t) && (\exists integer t) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (0 <= even) && (0 <= c) && (0 < c); */
}

/*@ requires (even == 0 || even >= 0) && (even == 0 || even > 0) && (even == 0 ==> c == 1) && (even <= even + 1) && (even % 2 == 0) && (even % 2 == 0 || even % 2 == 1) && (c > 1 ==> even >= 0) && (c > 1 ==> even > 0) && (c == 1 || c > 1) && (c == 1 || c <= p + 1) && (c == 1 ==> even == 0) && (c <= p+1 || 0 <= c) && (c <= p + 1 || 0 <= c) && (c <= p + 1 ==> even >= 0) && (c <= p + 1 ==> even % 2 == 0) && (c % 2 == 1 || c % 2 == 0) && (c % 2 == 0 || c % 2 == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer t) && (\exists integer t) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (0 <= even) && (0 <= c) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int even, int k, int p, int t) {
    /*@ assert (1 <= c) && (c <= \at(p,Pre) + 1 || \at(p,Pre) < 0) && (even == 16 * sum4(c - 1)) && ((c <= \at(p,Pre)) ==> (even == 16 * sum4(c - 1))) && (p == \at(p,Pre)); */
}
