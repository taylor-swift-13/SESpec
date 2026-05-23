#include <limits.h>

/*@ requires (1 <= l) && (ret >= 1) && (ret <= l) && (n % ret == 0 && y % ret == 0) && (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret) && (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0) && (n <= y) && (n == \at(n,Pre) || n == \at(y,Pre)) && (y == \at(n,Pre) || y == \at(y,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int k, int l, int n, int r, int ret, int y) {
    /*@ assert (ret == 1 || \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (ret == 1 || 1 <= ret <= l); */
    /*@ assert (ret == 1 || 1 <= ret <= l - 1); */
    /*@ assert (0 <= ret); */
    /*@ assert (y % ret == 0 || ret == 1); */
    /*@ assert (ret == 1 || y % ret == 0); */
    /*@ assert (ret == 1 || ret >= 1); */
    /*@ assert (ret == 1 || ret > 1); */
    /*@ assert (ret == 1 || ret > 0); */
    /*@ assert (ret == 1 || ret <= y); */
    /*@ assert (ret == 1 || ret <= n); */
    /*@ assert (ret == 1 || ret <= n + 1); */
    /*@ assert (ret == 1 || ret <= l); */
    /*@ assert (ret == 1 || ret <= l - 1); */
    /*@ assert (ret == 1 || ret < n + 1); */
    /*@ assert (ret == 1 || ret < l); */
    /*@ assert (ret == 1 || ret < l + 1); */
    /*@ assert (ret == 1 || ret % ret == 0); */
    /*@ assert (ret == 1 || ret % 1 == 0); */
    /*@ assert (ret == 1 || n % ret == 0); */
    /*@ assert (ret == 1 || \forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (ret == 1 || \forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)); */
    /*@ assert (ret == 1 || \exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 && ret == k); */
    /*@ assert (ret == 1 || 1 <= ret); */
    /*@ assert (ret == 1 || 1 <= ret <= n); */
    /*@ assert (ret == 1 || 0 < ret); */
    /*@ assert (ret == 1 || (y % ret == 0)); */
    /*@ assert (ret == 1 || (ret >= 1)); */
    /*@ assert (ret == 1 || (ret > 0)); */
    /*@ assert (ret == 1 || (ret > 0 && ret <= n && ret <= y)); */
    /*@ assert (ret == 1 || (ret > 0 && n % ret == 0 && y % ret == 0)); */
    /*@ assert (ret == 1 || (ret == 1 || y % ret == 0)); */
    /*@ assert (ret == 1 || (ret == 1 || ret <= y)); */
    /*@ assert (ret == 1 || (ret == 1 || ret <= n)); */
    /*@ assert (ret == 1 || (ret == 1 || n % ret == 0)); */
    /*@ assert (ret == 1 || (ret <= y)); */
    /*@ assert (ret == 1 || (ret <= n)); */
    /*@ assert (ret == 1 || (ret <= n && ret <= y)); */
    /*@ assert (ret == 1 || (ret <= l && n % ret == 0 && y % ret == 0)); */
    /*@ assert (ret == 1 || (ret % ret == 0)); */
    /*@ assert (ret == 1 || (ret % 1 == 0)); */
    /*@ assert (ret == 1 || (n % ret == 0)); */
    /*@ assert (ret == 1 || (n % ret == 0 && y % ret == 0)); */
    /*@ assert (ret == 1 || (l > 1 ==> ret >= 1)); */
    /*@ assert (ret == 1 || (l > 1 ==> ret <= n)); */
    /*@ assert (ret == 1 || (l > 1 ==> ret < l)); */
    /*@ assert (ret == 1 || (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret))); */
    /*@ assert (ret == 1 || (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret))); */
    /*@ assert (ret == 1 || (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (ret == 1 || (\exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 && ret == k)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= y)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= n)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= n && ret <= y)); */
    /*@ assert (ret == 1 || (1 <= ret && ret <= l)); */
    /*@ assert (ret <= l); */
    /*@ assert (ret <= l + 1); */
    /*@ assert (r == 1); */
    /*@ assert (n <= y); */
    /*@ assert (n <= y ==> n == n); */
    /*@ assert (n % ret == 0); */
    /*@ assert (n % ret == 0 || ret == 1); */
    /*@ assert (n % ret == 0 && y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)); */
    /*@ assert (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (\forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret); */
    /*@ assert (\exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> ret == k); */
    /*@ assert (1 <= ret); */
    /*@ assert (1 <= l); */
    /*@ assert (0 <= l); */
    /*@ assert (0 < ret); */
    /*@ assert (0 < l); */
}

/*@ requires (ret == 1 || \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret) && (ret == 1 || 1 <= ret <= l) && (ret == 1 || 1 <= ret <= l - 1) && (0 <= ret) && (y % ret == 0 || ret == 1) && (ret == 1 || y % ret == 0) && (ret == 1 || ret >= 1) && (ret == 1 || ret > 1) && (ret == 1 || ret > 0) && (ret == 1 || ret <= y) && (ret == 1 || ret <= n) && (ret == 1 || ret <= n + 1) && (ret == 1 || ret <= l) && (ret == 1 || ret <= l - 1) && (ret == 1 || ret < n + 1) && (ret == 1 || ret < l) && (ret == 1 || ret < l + 1) && (ret == 1 || ret % ret == 0) && (ret == 1 || ret % 1 == 0) && (ret == 1 || n % ret == 0) && (ret == 1 || \forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)) && (ret == 1 || \forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)) && (ret == 1 || \exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 && ret == k) && (ret == 1 || 1 <= ret) && (ret == 1 || 1 <= ret <= n) && (ret == 1 || 0 < ret) && (ret == 1 || (y % ret == 0)) && (ret == 1 || (ret >= 1)) && (ret == 1 || (ret > 0)) && (ret == 1 || (ret > 0 && ret <= n && ret <= y)) && (ret == 1 || (ret > 0 && n % ret == 0 && y % ret == 0)) && (ret == 1 || (ret == 1 || y % ret == 0)) && (ret == 1 || (ret == 1 || ret <= y)) && (ret == 1 || (ret == 1 || ret <= n)) && (ret == 1 || (ret == 1 || n % ret == 0)) && (ret == 1 || (ret <= y)) && (ret == 1 || (ret <= n)) && (ret == 1 || (ret <= n && ret <= y)) && (ret == 1 || (ret <= l && n % ret == 0 && y % ret == 0)) && (ret == 1 || (ret % ret == 0)) && (ret == 1 || (ret % 1 == 0)) && (ret == 1 || (n % ret == 0)) && (ret == 1 || (n % ret == 0 && y % ret == 0)) && (ret == 1 || (l > 1 ==> ret >= 1)) && (ret == 1 || (l > 1 ==> ret <= n)) && (ret == 1 || (l > 1 ==> ret < l)) && (ret == 1 || (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret))) && (ret == 1 || (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret))) && (ret == 1 || (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret)) && (ret == 1 || (\exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 && ret == k)) && (ret == 1 || (1 <= ret && ret <= y)) && (ret == 1 || (1 <= ret && ret <= n)) && (ret == 1 || (1 <= ret && ret <= n && ret <= y)) && (ret == 1 || (1 <= ret && ret <= l)) && (ret <= l) && (ret <= l + 1) && (r == 1) && (n <= y) && (n <= y ==> n == n) && (n % ret == 0) && (n % ret == 0 || ret == 1) && (n % ret == 0 && y % ret == 0) && (\forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret)) && (\forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret)) && (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret) && (\forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret) && (\exists integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> ret == k) && (1 <= ret) && (1 <= l) && (0 <= l) && (0 < ret) && (0 < l);
    assigns \nothing;
*/
void check_B_implies_A(int k, int l, int n, int r, int ret, int y) {
    /*@ assert (1 <= l); */
    /*@ assert (ret >= 1); */
    /*@ assert (ret <= l); */
    /*@ assert (n % ret == 0 && y % ret == 0); */
    /*@ assert (\forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret); */
    /*@ assert (\exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0); */
    /*@ assert (n <= y); */
    /*@ assert (n == \at(n,Pre) || n == \at(y,Pre)); */
    /*@ assert (y == \at(n,Pre) || y == \at(y,Pre)); */
}
