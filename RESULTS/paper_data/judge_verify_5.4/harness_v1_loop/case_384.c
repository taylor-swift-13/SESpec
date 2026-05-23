#include <limits.h>

/*@logic integer prod(integer n, integer i) =
    i <= 0 ? 1 : prod(n, i - 1) * (n - i + 1) / i;*/

/*@ requires (1 <= i <= k + 1) && (0 <= c) && (0 <= k) && (2 * k <= n) && (k == \at(k,Pre) || k == n - \at(k,Pre)) && (n == \at(n,Pre)) && (c == prod(n, i - 1)) && (\forall integer j) && ((i > k) ==> (c == prod(n, k)));
    assigns \nothing;
*/
void check_A_implies_B(int c, int i, int j, int k, int n, int t) {
    /*@ assert (c == 1 || c >= 1) && (c == 1 || c > 0) && (c <= c * i) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (1 <= i) && (1 <= c) && (1 <= c * i) && (0 <= i) && (0 <= c) && (0 < i) && (0 < c); */
}

/*@ requires (c == 1 || c >= 1) && (c == 1 || c > 0) && (c <= c * i) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (\forall integer j) && (1 <= i) && (1 <= c) && (1 <= c * i) && (0 <= i) && (0 <= c) && (0 < i) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int i, int j, int k, int n, int t) {
    /*@ assert (1 <= i <= k + 1) && (0 <= c) && (0 <= k) && (2 * k <= n) && (k == \at(k,Pre) || k == n - \at(k,Pre)) && (n == \at(n,Pre)) && (c == prod(n, i - 1)) && (\forall integer j) && ((i > k) ==> (c == prod(n, k))); */
}
