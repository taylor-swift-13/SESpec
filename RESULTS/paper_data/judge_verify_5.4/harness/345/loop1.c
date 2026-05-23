#include <limits.h>

/*@ logic integer evendiv_sum(integer n, integer i) =
      i < 2 ? 0 :
      evendiv_sum(n, i - 1) + ((n % i == 0 && i % 2 == 0) ? i : 0); */

/*@ requires (2 <= i) && (0 <= sum) && ((i<=\at(n,Pre)) ==> (sum == evendiv_sum(n, i - 1))) && ((i<=\at(n,Pre)) ==> (0 <= sum)) && ((!(i<=\at(n,Pre))) ==> (sum == evendiv_sum(n, \at(n,Pre)))) && (n == \at(n,Pre)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0) ==> sum >= k) && (sum > 0 ==> \exists integer k; 2 <= k < i && n % k == 0 && k % 2 == 0);
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int *n) {
    /*@ assert (sum >= 0 && i >= 2); */
    /*@ assert (i == 2 || i > 2); */
    /*@ assert (sum == 0 || sum >= 2); */
    /*@ assert (sum == 0 || sum >= 0); */
    /*@ assert (sum == 0 || sum > 0); */
    /*@ assert (sum <= n * n || i <= n+1); */
    /*@ assert (sum <= n * n || i <= n + 1); */
    /*@ assert (sum % 2 == 0); */
    /*@ assert (sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (sum % 2 == 0 ==> sum >= 0); */
    /*@ assert (sum % 2 == 0 ==> sum == 0 || sum % 2 == 0); */
    /*@ assert (i >= 2 ==> sum >= 0); */
    /*@ assert (i > 2 ==> sum >= 0); */
    /*@ assert (i <= n+1 || sum <= n*(n+1)/2); */
    /*@ assert (i <= n+1 || sum <= n * (n + 1) / 2); */
    /*@ assert (i <= n + 1 || sum <= n*(n+1)/2); */
    /*@ assert (i <= n + 1 || sum <= n * (n + 1) / 2); */
    /*@ assert (i % 2 == 0 || i % 2 == 1); */
    /*@ assert (\forall integer k; 2 <= k < i ==> sum >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum == sum)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= k)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 2)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum == sum)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k != 0 || sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k != 0 || sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= k)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (k % 2 == 0 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 ==> sum >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 1 ==> sum % 2 == 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= k); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 2); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 != 0 ==> sum >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k != 0 ==> sum >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i && n % k != 0 ==> sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (\exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= k); */
    /*@ assert (\exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= 0); */
    /*@ assert (2 <= i); */
    /*@ assert (0 <= sum); */
}

/*@ requires (sum >= 0 && i >= 2) && (i == 2 || i > 2) && (sum == 0 || sum >= 2) && (sum == 0 || sum >= 0) && (sum == 0 || sum > 0) && (sum <= n * n || i <= n+1) && (sum <= n * n || i <= n + 1) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (sum % 2 == 0 ==> sum >= 0) && (sum % 2 == 0 ==> sum == 0 || sum % 2 == 0) && (i >= 2 ==> sum >= 0) && (i > 2 ==> sum >= 0) && (i <= n+1 || sum <= n*(n+1)/2) && (i <= n+1 || sum <= n * (n + 1) / 2) && (i <= n + 1 || sum <= n*(n+1)/2) && (i <= n + 1 || sum <= n * (n + 1) / 2) && (i % 2 == 0 || i % 2 == 1) && (\forall integer k; 2 <= k < i ==> sum >= 0) && (\forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum >= 0)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum >= 0)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum == sum)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= k)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 2)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 0)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum == sum)) && (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (n % k != 0 || sum >= 0)) && (\forall integer k; 2 <= k < i ==> (n % k != 0 || sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= k)) && (\forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= 0)) && (\forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum >= 0)) && (\forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1)) && (\forall integer k; 2 <= k < i ==> (k % 2 == 0 ==> sum >= 0)) && (\forall integer k; 2 <= k < i && n % k == 0 ==> sum >= 0) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 1 ==> sum % 2 == 0) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= k) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 2) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 0) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1) && (\forall integer k; 2 <= k < i && n % k == 0 && k % 2 != 0 ==> sum >= 0) && (\forall integer k; 2 <= k < i && n % k != 0 ==> sum >= 0) && (\forall integer k; 2 <= k < i && n % k != 0 ==> sum % 2 == 0 || sum % 2 == 1) && (\exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= k) && (\exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= 0) && (2 <= i) && (0 <= sum);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int *n) {
    /*@ assert (2 <= i); */
    /*@ assert (0 <= sum); */
    /*@ assert ((i<=\at(n,Pre)) ==> (sum == evendiv_sum(n, i - 1))); */
    /*@ assert ((i<=\at(n,Pre)) ==> (0 <= sum)); */
    /*@ assert ((!(i<=\at(n,Pre))) ==> (sum == evendiv_sum(n, \at(n,Pre)))); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0) ==> sum >= k); */
    /*@ assert (sum > 0 ==> \exists integer k; 2 <= k < i && n % k == 0 && k % 2 == 0); */
}
