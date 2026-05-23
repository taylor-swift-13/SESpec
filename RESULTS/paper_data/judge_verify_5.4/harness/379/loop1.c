#include <limits.h>

/*@ logic integer even_sum(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a : 0) + even_sum(a + 1, b); */

/*@ requires (l <= i <= r + 1) && (\true) && (r == \at(r,Pre)) && (l == \at(l,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int l, int r) {
    /*@ assert (sum % 2 == 0 ==> i >= l); */
    /*@ assert (sum >= 0 || i <= r + 1); */
    /*@ assert (sum >= 0 ==> i >= l); */
    /*@ assert (sum == 0 || sum % 2 == 0); */
    /*@ assert (sum % 2 == 0); */
    /*@ assert (sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (l <= i); */
    /*@ assert (i == l ==> sum == 0); */
    /*@ assert (i == l + (i - l)); */
    /*@ assert (i <= r + 1 || 0 <= sum); */
    /*@ assert (i <= r + 1 || 0 <= i - l); */
    /*@ assert (i <= r + 1 ==> i - l <= r - l + 1); */
    /*@ assert (i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (i % 2 == 0 ==> sum % 2 == 0); */
    /*@ assert (\forall integer k; l <= k < i ==> (sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % 2 == 1 ==> sum == sum)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum == sum)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; l <= k < i && k % 2 == 1 ==> sum % 2 == 0); */
    /*@ assert (\forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0); */
    /*@ assert (\forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (\forall integer k; l <= k < i && k % 2 != 0 ==> sum == sum); */
    /*@ assert (\forall integer k; l <= k < i && k % 2 != 0 ==> sum % 2 == 0); */
    /*@ assert (\exists integer k; l <= k <= i ==> (k % 2 == 0 ==> sum >= 0)); */
    /*@ assert (\exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= k); */
    /*@ assert (\exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= 0); */
    /*@ assert (\exists integer k; l <= k < i && k % 2 == 0 ==> sum >= k); */
    /*@ assert (\exists integer k; l <= k < i && k % 2 == 0 ==> sum >= 0); */
    /*@ assert (0 <= sum || i <= r+1); */
    /*@ assert (0 <= sum || i <= r + 1); */
    /*@ assert (0 <= sum || i - l <= r - l + 1); */
    /*@ assert (0 <= sum || 0 <= (i - l)); */
    /*@ assert (0 <= i - l); */
    /*@ assert (0 <= i - l || i <= r+1); */
    /*@ assert (0 <= i - l || 0 <= sum); */
    /*@ assert (0 <= (i - l)); */
    /*@ assert (0 <= (i - l) || i <= r + 1); */
    /*@ assert (0 <= (i - l) || i - l <= r - l + 1); */
}

/*@ requires (sum % 2 == 0 ==> i >= l) && (sum >= 0 || i <= r + 1) && (sum >= 0 ==> i >= l) && (sum == 0 || sum % 2 == 0) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (l <= i) && (i == l ==> sum == 0) && (i == l + (i - l)) && (i <= r + 1 || 0 <= sum) && (i <= r + 1 || 0 <= i - l) && (i <= r + 1 ==> i - l <= r - l + 1) && (i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1)) && (i % 2 == 0 ==> sum % 2 == 0) && (\forall integer k; l <= k < i ==> (sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; l <= k < i ==> (k % 2 == 1 ==> sum == sum)) && (\forall integer k; l <= k < i ==> (k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum == sum)) && (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0)) && (\forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; l <= k < i && k % 2 == 1 ==> sum % 2 == 0) && (\forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0) && (\forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1) && (\forall integer k; l <= k < i && k % 2 != 0 ==> sum == sum) && (\forall integer k; l <= k < i && k % 2 != 0 ==> sum % 2 == 0) && (\exists integer k; l <= k <= i ==> (k % 2 == 0 ==> sum >= 0)) && (\exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= k) && (\exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= 0) && (\exists integer k; l <= k < i && k % 2 == 0 ==> sum >= k) && (\exists integer k; l <= k < i && k % 2 == 0 ==> sum >= 0) && (0 <= sum || i <= r+1) && (0 <= sum || i <= r + 1) && (0 <= sum || i - l <= r - l + 1) && (0 <= sum || 0 <= (i - l)) && (0 <= i - l) && (0 <= i - l || i <= r+1) && (0 <= i - l || 0 <= sum) && (0 <= (i - l)) && (0 <= (i - l) || i <= r + 1) && (0 <= (i - l) || i - l <= r - l + 1);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int l, int r) {
    /*@ assert (l <= i <= r + 1); */
    /*@ assert (\true); */
    /*@ assert (r == \at(r,Pre)); */
    /*@ assert (l == \at(l,Pre)); */
}
