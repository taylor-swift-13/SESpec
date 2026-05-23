#include <limits.h>

/*@ logic integer gcd(integer a, integer b) =
      b == 0 ? a : gcd(b, a % b); */

/*@ requires (1 <= l) && (1 <= ret <= l) && (n <= y) && (n % ret == 0 && y % ret == 0) && (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret) && (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0);
    assigns \nothing;
*/
void check_A_implies_B(int k, int l, int n, int ret, int y) {
    /*@ assert (y % ret == 0 || ret == 1); */
    /*@ assert (ret == 1 || ret <= y); */
    /*@ assert (ret == 1 || ret <= n); */
    /*@ assert (ret == 1 || ret <= l); */
    /*@ assert (ret == 1 || (n % ret == 0 && y % ret == 0)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= y)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= n)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= l)); */
    /*@ assert (ret <= l); */
    /*@ assert (n <= y); */
    /*@ assert (n % ret == 0 || ret == 1); */
    /*@ assert (n % ret == 0 && y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (\forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret); */
    /*@ assert (1 <= ret); */
    /*@ assert (1 <= l); */
}

/*@ requires (y % ret == 0 || ret == 1) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= l) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (1 <= ret && ret <= y)) && (ret == 1 || (1 <= ret && ret <= n)) && (ret == 1 || (1 <= ret && ret <= l)) && (ret <= l) && (n <= y) && (n % ret == 0 || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)) && (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)) && (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret) && (\forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret) && (1 <= ret) && (1 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int k, int l, int n, int ret, int y) {
    /*@ assert (1 <= l); */
    /*@ assert (1 <= ret <= l); */
    /*@ assert (n <= y); */
    /*@ assert (n % ret == 0 && y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0); */
}
