#include <limits.h>

/*@logic integer even_sum(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a : 0) + even_sum(a + 1, b);*/

/*@ requires (l <= i <= r + 1) && (\true) && (r == \at(r,Pre)) && (l == \at(l,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int l, int r) {
    /*@ assert (sum % 2 == 0 ==> i >= l) && (sum >= 0 || i <= r + 1) && (sum >= 0 ==> i >= l) && (sum == 0 || sum % 2 == 0) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (l <= i) && (i == l ==> sum == 0) && (i == l + (i - l)) && (i <= r + 1 || 0 <= sum) && (i <= r + 1 || 0 <= i - l) && (i <= r + 1 ==> i - l <= r - l + 1) && (i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1)) && (i % 2 == 0 ==> sum % 2 == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= sum || i <= r+1) && (0 <= sum || i <= r + 1) && (0 <= sum || i - l <= r - l + 1) && (0 <= sum || 0 <= (i - l)) && (0 <= i - l) && (0 <= i - l || i <= r+1) && (0 <= i - l || 0 <= sum) && (0 <= (i - l)) && (0 <= (i - l) || i <= r + 1) && (0 <= (i - l) || i - l <= r - l + 1); */
}

/*@ requires (sum % 2 == 0 ==> i >= l) && (sum >= 0 || i <= r + 1) && (sum >= 0 ==> i >= l) && (sum == 0 || sum % 2 == 0) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (l <= i) && (i == l ==> sum == 0) && (i == l + (i - l)) && (i <= r + 1 || 0 <= sum) && (i <= r + 1 || 0 <= i - l) && (i <= r + 1 ==> i - l <= r - l + 1) && (i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1)) && (i % 2 == 0 ==> sum % 2 == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= sum || i <= r+1) && (0 <= sum || i <= r + 1) && (0 <= sum || i - l <= r - l + 1) && (0 <= sum || 0 <= (i - l)) && (0 <= i - l) && (0 <= i - l || i <= r+1) && (0 <= i - l || 0 <= sum) && (0 <= (i - l)) && (0 <= (i - l) || i <= r + 1) && (0 <= (i - l) || i - l <= r - l + 1);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int l, int r) {
    /*@ assert (l <= i <= r + 1) && (\true) && (r == \at(r,Pre)) && (l == \at(l,Pre)); */
}
