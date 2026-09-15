#include <limits.h>

/*@ logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n - 1) + n * n * n * n; */

/*@ requires (1 <= c) && (c <= \at(p,Pre) + 1 || \at(p,Pre) < 0) && (even == 16 * sum4(c - 1)) && ((c <= \at(p,Pre)) ==> (even == 16 * sum4(c - 1))) && (p == \at(p,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int even, int k, int p, int t) {
    /*@ assert (even == 0 || even >= 0); */
    /*@ assert (even == 0 || even > 0); */
    /*@ assert (even == 0 ==> c == 1); */
    /*@ assert (even <= even + 1); */
    /*@ assert (even % 2 == 0); */
    /*@ assert (even % 2 == 0 || even % 2 == 1); */
    /*@ assert (c > 1 ==> even >= 0); */
    /*@ assert (c > 1 ==> even > 0); */
    /*@ assert (c == 1 || c > 1); */
    /*@ assert (c == 1 || c <= p + 1); */
    /*@ assert (c == 1 ==> even == 0); */
    /*@ assert (c <= p+1 || 0 <= c); */
    /*@ assert (c <= p + 1 || 0 <= c); */
    /*@ assert (c <= p + 1 ==> even >= 0); */
    /*@ assert (c <= p + 1 ==> even % 2 == 0); */
    /*@ assert (c % 2 == 1 || c % 2 == 0); */
    /*@ assert (c % 2 == 0 || c % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k <= c ==> even >= 0); */
    /*@ assert (\forall integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even <= even + (2*k)*(2*k)*(2*k)*(2*k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even + (2*k)*(2*k)*(2*k)*(2*k) >= even); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even + (2*k)*(2*k) >= even); */
    /*@ assert (\forall integer k; 1 <= k < c ==> even % 2 == 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= (2*k)*(2*k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) % 2 == 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= even + (2*c)*(2*c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= (2*c)*(2*c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (2*k) * (2*k) >= 0); */
    /*@ assert (\exists integer t; 1 <= t < c ==> even >= (2*t)*(2*t)); */
    /*@ assert (\exists integer t; 0 <= t < c ==> even >= (2*t)*(2*t)); */
    /*@ assert (\exists integer k; 1 <= k <= c ==> even >= 0); */
    /*@ assert (\exists integer k; 1 <= k <= c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)); */
    /*@ assert (\exists integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0); */
    /*@ assert (\exists integer k; 1 <= k < c ==> even >= 0); */
    /*@ assert (\exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)); */
    /*@ assert (\exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)); */
    /*@ assert (\exists integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0); */
    /*@ assert (\exists integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= even); */
    /*@ assert (0 <= c); */
    /*@ assert (0 < c); */
}

/*@ requires (even == 0 || even >= 0) && (even == 0 || even > 0) && (even == 0 ==> c == 1) && (even <= even + 1) && (even % 2 == 0) && (even % 2 == 0 || even % 2 == 1) && (c > 1 ==> even >= 0) && (c > 1 ==> even > 0) && (c == 1 || c > 1) && (c == 1 || c <= p + 1) && (c == 1 ==> even == 0) && (c <= p+1 || 0 <= c) && (c <= p + 1 || 0 <= c) && (c <= p + 1 ==> even >= 0) && (c <= p + 1 ==> even % 2 == 0) && (c % 2 == 1 || c % 2 == 0) && (c % 2 == 0 || c % 2 == 1) && (\forall integer k; 1 <= k <= c ==> even >= 0) && (\forall integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0) && (\forall integer k; 1 <= k < c ==> even >= 0) && (\forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)) && (\forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)) && (\forall integer k; 1 <= k < c ==> even <= even + (2*k)*(2*k)*(2*k)*(2*k)) && (\forall integer k; 1 <= k < c ==> even + (2*k)*(2*k)*(2*k)*(2*k) >= even) && (\forall integer k; 1 <= k < c ==> even + (2*k)*(2*k) >= even) && (\forall integer k; 1 <= k < c ==> even % 2 == 0) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= (2*k)*(2*k)) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) % 2 == 0) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= even + (2*c)*(2*c)) && (\forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= (2*c)*(2*c)) && (\forall integer k; 1 <= k < c ==> (2*k) * (2*k) >= 0) && (\exists integer t; 1 <= t < c ==> even >= (2*t)*(2*t)) && (\exists integer t; 0 <= t < c ==> even >= (2*t)*(2*t)) && (\exists integer k; 1 <= k <= c ==> even >= 0) && (\exists integer k; 1 <= k <= c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)) && (\exists integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0) && (\exists integer k; 1 <= k < c ==> even >= 0) && (\exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)) && (\exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k)) && (\exists integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0) && (\exists integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0) && (1 <= c) && (0 <= even) && (0 <= c) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int even, int k, int p, int t) {
    /*@ assert (1 <= c); */
    /*@ assert (c <= \at(p,Pre) + 1 || \at(p,Pre) < 0); */
    /*@ assert (even == 16 * sum4(c - 1)); */
    /*@ assert ((c <= \at(p,Pre)) ==> (even == 16 * sum4(c - 1))); */
    /*@ assert (p == \at(p,Pre)); */
}
