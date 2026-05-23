#include <limits.h>

/*@logic integer gcd(integer a, integer b) =
  b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);*/

/*@ requires (1 <= j) && (ret >= 1) && (ret <= j) && (n % ret == 0) && (y % ret == 0) && (\forall integer k) && (n == \at(y,Pre)) && (y == \at(n,Pre)) && (l == 1);
    assigns \nothing;
*/
void check_A_implies_B(int j, int k, int l, int n, int ret, int y) {
    /*@ assert (ret == 1 || ret >= 1) && (ret == 1 || ret > 0) && (ret == 1 || ret == j - 1 || ret < j) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= j) && (ret == 1 || ret <= j - 1) && (ret == 1 || ret % 1 == 0) && (ret == 1 || \forall integer k) && (ret == 1 || \forall integer k) && (ret == 1 || \exists integer k) && (ret == 1 || 1 <= ret <= y) && (ret == 1 || 1 <= ret <= n) && (ret == 1 || (ret >= 1 && ret <= j)) && (ret == 1 || (ret == j || ret < j)) && (ret == 1 || (ret == j - 1 || ret < j)) && (ret == 1 || (ret <= n && ret <= y)) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j)) && (ret == 1 || (\forall integer k) && (ret == 1 || (\forall integer k) && (ret == 1 || (\exists integer k) && (ret == 1 || (1 <= ret <= j)) && (ret == 1 || (1 <= ret < j)) && (ret <= j) && (ret <= j || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= ret) && (1 <= j) && (0 <= ret) && (0 < ret) && ((ret == 1) || (n % ret == 0 && y % ret == 0)); */
}

/*@ requires (ret == 1 || ret >= 1) && (ret == 1 || ret > 0) && (ret == 1 || ret == j - 1 || ret < j) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= j) && (ret == 1 || ret <= j - 1) && (ret == 1 || ret % 1 == 0) && (ret == 1 || \forall integer k) && (ret == 1 || \forall integer k) && (ret == 1 || \exists integer k) && (ret == 1 || 1 <= ret <= y) && (ret == 1 || 1 <= ret <= n) && (ret == 1 || (ret >= 1 && ret <= j)) && (ret == 1 || (ret == j || ret < j)) && (ret == 1 || (ret == j - 1 || ret < j)) && (ret == 1 || (ret <= n && ret <= y)) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j)) && (ret == 1 || (\forall integer k) && (ret == 1 || (\forall integer k) && (ret == 1 || (\exists integer k) && (ret == 1 || (1 <= ret <= j)) && (ret == 1 || (1 <= ret < j)) && (ret <= j) && (ret <= j || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= ret) && (1 <= j) && (0 <= ret) && (0 < ret) && ((ret == 1) || (n % ret == 0 && y % ret == 0));
    assigns \nothing;
*/
void check_B_implies_A(int j, int k, int l, int n, int ret, int y) {
    /*@ assert (1 <= j) && (ret >= 1) && (ret <= j) && (n % ret == 0) && (y % ret == 0) && (\forall integer k) && (n == \at(y,Pre)) && (y == \at(n,Pre)) && (l == 1); */
}
