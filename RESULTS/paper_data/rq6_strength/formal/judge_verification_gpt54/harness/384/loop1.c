#include <limits.h>

/*@ logic integer prod(integer n, integer i) =
    i <= 0 ? 1 : prod(n, i - 1) * (n - i + 1) / i; */

/*@ requires (1 <= i <= k + 1) && (0 <= c) && (0 <= k) && (2 * k <= n) && (k == \at(k,Pre) || k == n - \at(k,Pre)) && (n == \at(n,Pre)) && (c == prod(n, i - 1)) && (\forall integer j; 1 <= j < i ==> (n - j + 1) >= 0) && ((i > k) ==> (c == prod(n, k)));
    assigns \nothing;
*/
void check_A_implies_B(int c, int *i, int *j, int *k, int n, int *t) {
    /*@ assert (c == 1 || c >= 1); */
    /*@ assert (c == 1 || c > 0); */
    /*@ assert (c <= c * i); */
    /*@ assert (\forall integer t; 1 <= t < i ==> t <= n); */
    /*@ assert (\forall integer t; 1 <= t < i ==> t <= k); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= t - 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= i); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= i - t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= i - t + 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 >= 0); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 > t - 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 > i - t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 > i - 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> n - t + 1 > 0); */
    /*@ assert (\forall integer t; 1 <= t < i ==> i >= t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> i > t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> i <= k + 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> i != t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> c >= 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> c >= 0); */
    /*@ assert (\forall integer t; 1 <= t < i ==> c * t >= 1); */
    /*@ assert (\forall integer t; 1 <= t < i ==> (n - t + 1) >= t); */
    /*@ assert (\forall integer t; 1 <= t < i ==> (n - t + 1) > 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 >= j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 >= i); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 >= i - j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 >= 1); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 >= 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 > j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 > j - 1); */
    /*@ assert (\forall integer j; 1 <= j < i ==> n - j + 1 > 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> i >= j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> i > j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> i <= k + 1); */
    /*@ assert (\forall integer j; 1 <= j < i ==> i != j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> i != 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> c >= 1); */
    /*@ assert (\forall integer j; 1 <= j < i ==> c >= 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> c * j == c * j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> (n - j + 1) >= j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> (n - j + 1) >= i - j); */
    /*@ assert (\forall integer j; 1 <= j < i ==> (n - j + 1) >= 0); */
    /*@ assert (\forall integer j; 1 <= j < i ==> (n - j + 1) > 0); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= c); */
    /*@ assert (1 <= c * i); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= c); */
    /*@ assert (0 < i); */
    /*@ assert (0 < c); */
}

/*@ requires (c == 1 || c >= 1) && (c == 1 || c > 0) && (c <= c * i) && (\forall integer t; 1 <= t < i ==> t <= n) && (\forall integer t; 1 <= t < i ==> t <= k) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= t) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= t - 1) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= i) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= i - t) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= i - t + 1) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= 1) && (\forall integer t; 1 <= t < i ==> n - t + 1 >= 0) && (\forall integer t; 1 <= t < i ==> n - t + 1 > t - 1) && (\forall integer t; 1 <= t < i ==> n - t + 1 > i - t) && (\forall integer t; 1 <= t < i ==> n - t + 1 > i - 1) && (\forall integer t; 1 <= t < i ==> n - t + 1 > 0) && (\forall integer t; 1 <= t < i ==> i >= t) && (\forall integer t; 1 <= t < i ==> i > t) && (\forall integer t; 1 <= t < i ==> i <= k + 1) && (\forall integer t; 1 <= t < i ==> i != t) && (\forall integer t; 1 <= t < i ==> c >= 1) && (\forall integer t; 1 <= t < i ==> c >= 0) && (\forall integer t; 1 <= t < i ==> c * t >= 1) && (\forall integer t; 1 <= t < i ==> (n - t + 1) >= t) && (\forall integer t; 1 <= t < i ==> (n - t + 1) > 0) && (\forall integer j; 1 <= j < i ==> n - j + 1 >= j) && (\forall integer j; 1 <= j < i ==> n - j + 1 >= i) && (\forall integer j; 1 <= j < i ==> n - j + 1 >= i - j) && (\forall integer j; 1 <= j < i ==> n - j + 1 >= 1) && (\forall integer j; 1 <= j < i ==> n - j + 1 >= 0) && (\forall integer j; 1 <= j < i ==> n - j + 1 > j) && (\forall integer j; 1 <= j < i ==> n - j + 1 > j - 1) && (\forall integer j; 1 <= j < i ==> n - j + 1 > 0) && (\forall integer j; 1 <= j < i ==> i >= j) && (\forall integer j; 1 <= j < i ==> i > j) && (\forall integer j; 1 <= j < i ==> i <= k + 1) && (\forall integer j; 1 <= j < i ==> i != j) && (\forall integer j; 1 <= j < i ==> i != 0) && (\forall integer j; 1 <= j < i ==> c >= 1) && (\forall integer j; 1 <= j < i ==> c >= 0) && (\forall integer j; 1 <= j < i ==> c * j == c * j) && (\forall integer j; 1 <= j < i ==> (n - j + 1) >= j) && (\forall integer j; 1 <= j < i ==> (n - j + 1) >= i - j) && (\forall integer j; 1 <= j < i ==> (n - j + 1) >= 0) && (\forall integer j; 1 <= j < i ==> (n - j + 1) > 0) && (1 <= i) && (1 <= c) && (1 <= c * i) && (0 <= i) && (0 <= c) && (0 < i) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int *i, int *j, int *k, int n, int *t) {
    /*@ assert (1 <= i <= k + 1); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= k); */
    /*@ assert (2 * k <= n); */
    /*@ assert (k == \at(k,Pre) || k == n - \at(k,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (c == prod(n, i - 1)); */
    /*@ assert (\forall integer j; 1 <= j < i ==> (n - j + 1) >= 0); */
    /*@ assert ((i > k) ==> (c == prod(n, k))); */
}
