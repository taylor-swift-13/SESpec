#include <limits.h>

/*@logic integer gcd(integer a, integer b) =
      b == 0 ? a : gcd(b, a % b);*/

/*@ requires (1 <= l) && (1 <= ret <= l) && (n <= y) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\exists integer k);
    assigns \nothing;
*/
void check_A_implies_B(int k, int l, int n, int ret, int y) {
    /*@ assert (y % ret == 0 || ret == 1) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= l) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (1 <= ret && ret <= y)) && (ret == 1 || (1 <= ret && ret <= n)) && (ret == 1 || (1 <= ret && ret <= l)) && (ret <= l) && (n <= y) && (n % ret == 0 || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= ret) && (1 <= l); */
}

/*@ requires (y % ret == 0 || ret == 1) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= l) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (1 <= ret && ret <= y)) && (ret == 1 || (1 <= ret && ret <= n)) && (ret == 1 || (1 <= ret && ret <= l)) && (ret <= l) && (n <= y) && (n % ret == 0 || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= ret) && (1 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int k, int l, int n, int ret, int y) {
    /*@ assert (1 <= l) && (1 <= ret <= l) && (n <= y) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\exists integer k); */
}
