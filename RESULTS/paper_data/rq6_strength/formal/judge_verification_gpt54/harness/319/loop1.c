#include <limits.h>

/*@ logic integer gcd(integer a, integer b) =
  b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b); */

/*@ requires (1 <= j) && (ret >= 1) && (ret <= j) && (n % ret == 0) && (y % ret == 0) && (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret) && (n == \at(y,Pre)) && (y == \at(n,Pre)) && (l == 1);
    assigns \nothing;
*/
void check_A_implies_B(int j, int k, int l, int n, int ret, int y) {
    /*@ assert (ret == 1 || ret >= 1); */
    /*@ assert (ret == 1 || ret > 0); */
    /*@ assert (ret == 1 || ret == j - 1 || ret < j); */
    /*@ assert (ret == 1 || ret <= y); */
    /*@ assert (ret == 1 || ret <= n); */
    /*@ assert (ret == 1 || ret <= j); */
    /*@ assert (ret == 1 || ret <= j - 1); */
    /*@ assert (ret == 1 || ret % 1 == 0); */
    /*@ assert (ret == 1 || \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (ret == 1 || \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (ret == 1 || \exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k); */
    /*@ assert (ret == 1 || 1 <= ret <= y); */
    /*@ assert (ret == 1 || 1 <= ret <= n); */
    /*@ assert (ret == 1 || (ret >= 1 && ret <= j)); */
    /*@ assert (ret == 1 || (ret == j || ret < j)); */
    /*@ assert (ret == 1 || (ret == j - 1 || ret < j)); */
    /*@ assert (ret == 1 || (ret <= n && ret <= y)); */
    /*@ assert (ret == 1 || (n % ret == 0 && y % ret == 0)); */
    /*@ assert (ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j)); */
    /*@ assert (ret == 1 || (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret))); */
    /*@ assert (ret == 1 || (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (ret == 1 || (\exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k)); */
    /*@ assert (ret == 1 || (1 <= ret <= j)); */
    /*@ assert (ret == 1 || (1 <= ret < j)); */
    /*@ assert (ret <= j); */
    /*@ assert (ret <= j || ret == 1); */
    /*@ assert (n % ret == 0 && y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> ret >= 1); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> ret >= k)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (n % k != 0 || y % k != 0 || k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> ret >= k); */
    /*@ assert (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (\forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> ret >= k); */
    /*@ assert (\forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> k <= ret); */
    /*@ assert (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0); */
    /*@ assert (\exists integer k; 1 <= k <= j && ret == k && n % k == 0 && y % k == 0); */
    /*@ assert (\exists integer k; 1 <= k <= j && n % k == 0 && y % k == 0 && ret == k); */
    /*@ assert (1 <= ret); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 < ret); */
    /*@ assert ((ret == 1) || (n % ret == 0 && y % ret == 0)); */
}

/*@ requires (ret == 1 || ret >= 1) && (ret == 1 || ret > 0) && (ret == 1 || ret == j - 1 || ret < j) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= j) && (ret == 1 || ret <= j - 1) && (ret == 1 || ret % 1 == 0) && (ret == 1 || \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret)) && (ret == 1 || \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret) && (ret == 1 || \exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k) && (ret == 1 || 1 <= ret <= y) && (ret == 1 || 1 <= ret <= n) && (ret == 1 || (ret >= 1 && ret <= j)) && (ret == 1 || (ret == j || ret < j)) && (ret == 1 || (ret == j - 1 || ret < j)) && (ret == 1 || (ret <= n && ret <= y)) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j)) && (ret == 1 || (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret))) && (ret == 1 || (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret)) && (ret == 1 || (\exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k)) && (ret == 1 || (1 <= ret <= j)) && (ret == 1 || (1 <= ret < j)) && (ret <= j) && (ret <= j || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k; 1 <= k < j ==> ret >= 1) && (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> ret >= k)) && (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret)) && (\forall integer k; 1 <= k < j ==> (n % k != 0 || y % k != 0 || k <= ret)) && (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> ret >= k) && (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret) && (\forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> ret >= k) && (\forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> k <= ret) && (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0) && (\exists integer k; 1 <= k <= j && ret == k && n % k == 0 && y % k == 0) && (\exists integer k; 1 <= k <= j && n % k == 0 && y % k == 0 && ret == k) && (1 <= ret) && (1 <= j) && (0 <= ret) && (0 < ret) && ((ret == 1) || (n % ret == 0 && y % ret == 0));
    assigns \nothing;
*/
void check_B_implies_A(int j, int k, int l, int n, int ret, int y) {
    /*@ assert (1 <= j); */
    /*@ assert (ret >= 1); */
    /*@ assert (ret <= j); */
    /*@ assert (n % ret == 0); */
    /*@ assert (y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (n == \at(y,Pre)); */
    /*@ assert (y == \at(n,Pre)); */
    /*@ assert (l == 1); */
}
