#include <limits.h>

/*@ predicate divides(integer a, integer b) = a != 0 && b % a == 0; */

/*@ requires (i >= 2) && (max == 0 || max >= 2) && (max <= i);
    assigns \nothing;
*/
void check_A_implies_B(int d, int i, int k, int n) {
    /*@ assert (n > 0 || max == 0); */
    /*@ assert (n == 0 || n >= 1); */
    /*@ assert (max == 0 || n >= 1); */
    /*@ assert (max == 0 || n > 0); */
    /*@ assert (max == 0 || max >= 2); */
    /*@ assert (max == 0 || max <= n || max <= i); */
    /*@ assert (max == 0 || max <= i); */
    /*@ assert (max == 0 || max % i == 0 || max <= i); */
    /*@ assert (max == 0 || max % 2 == 0 || max >= 2); */
    /*@ assert (max == 0 || \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d); */
    /*@ assert (max == 0 || \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d)); */
    /*@ assert (max == 0 || \exists integer k; 2 <= k <= i && max == k); */
    /*@ assert (max == 0 || (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d)); */
    /*@ assert (max == 0 || (\exists integer k; 2 <= k <= i && max == k)); */
    /*@ assert (max <= i); */
    /*@ assert (\forall integer k; 2 <= k < i ==> n % k != 0 || max >= k); */
    /*@ assert (\forall integer d; 2 <= d < i ==> n % d == 0 ==> max >= d); */
    /*@ assert (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d); */
    /*@ assert (\forall integer d; 2 <= d < i ==> (n % d == 0 ==> max >= d)); */
    /*@ assert (\forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d)); */
    /*@ assert (2 <= i); */
    /*@ assert (1 <= n); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= i); */
    /*@ assert (0 < n); */
    /*@ assert (0 < i); */
}

/*@ requires (n > 0 || max == 0) && (n == 0 || n >= 1) && (max == 0 || n >= 1) && (max == 0 || n > 0) && (max == 0 || max >= 2) && (max == 0 || max <= n || max <= i) && (max == 0 || max <= i) && (max == 0 || max % i == 0 || max <= i) && (max == 0 || max % 2 == 0 || max >= 2) && (max == 0 || \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d) && (max == 0 || \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d)) && (max == 0 || \exists integer k; 2 <= k <= i && max == k) && (max == 0 || (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d)) && (max == 0 || (\exists integer k; 2 <= k <= i && max == k)) && (max <= i) && (\forall integer k; 2 <= k < i ==> n % k != 0 || max >= k) && (\forall integer d; 2 <= d < i ==> n % d == 0 ==> max >= d) && (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d) && (\forall integer d; 2 <= d < i ==> (n % d == 0 ==> max >= d)) && (\forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d)) && (2 <= i) && (1 <= n) && (1 <= i) && (0 <= n) && (0 <= max) && (0 <= i) && (0 < n) && (0 < i);
    assigns \nothing;
*/
void check_B_implies_A(int d, int i, int k, int n) {
    /*@ assert (i >= 2); */
    /*@ assert (max == 0 || max >= 2); */
    /*@ assert (max <= i); */
}
