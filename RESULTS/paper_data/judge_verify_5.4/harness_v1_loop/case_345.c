#include <limits.h>

/*@logic integer evendiv_sum(integer n, integer i) =
      i < 2 ? 0 :
      evendiv_sum(n, i - 1) + ((n % i == 0 && i % 2 == 0) ? i : 0);*/

/*@ requires (2 <= i) && (0 <= sum) && ((i<=\at(n,Pre)) ==> (sum == evendiv_sum(n, i - 1))) && ((i<=\at(n,Pre)) ==> (0 <= sum)) && ((!(i<=\at(n,Pre))) ==> (sum == evendiv_sum(n, \at(n,Pre)))) && (n == \at(n,Pre)) && (\forall integer k) && (sum > 0 ==> \exists integer k);
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int n) {
    /*@ assert (sum >= 0 && i >= 2) && (i == 2 || i > 2) && (sum == 0 || sum >= 2) && (sum == 0 || sum >= 0) && (sum == 0 || sum > 0) && (sum <= n * n || i <= n+1) && (sum <= n * n || i <= n + 1) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (sum % 2 == 0 ==> sum >= 0) && (sum % 2 == 0 ==> sum == 0 || sum % 2 == 0) && (i >= 2 ==> sum >= 0) && (i > 2 ==> sum >= 0) && (i <= n+1 || sum <= n*(n+1)/2) && (i <= n+1 || sum <= n * (n + 1) / 2) && (i <= n + 1 || sum <= n*(n+1)/2) && (i <= n + 1 || sum <= n * (n + 1) / 2) && (i % 2 == 0 || i % 2 == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (2 <= i) && (0 <= sum); */
}

/*@ requires (sum >= 0 && i >= 2) && (i == 2 || i > 2) && (sum == 0 || sum >= 2) && (sum == 0 || sum >= 0) && (sum == 0 || sum > 0) && (sum <= n * n || i <= n+1) && (sum <= n * n || i <= n + 1) && (sum % 2 == 0) && (sum % 2 == 0 || sum % 2 == 1) && (sum % 2 == 0 ==> sum >= 0) && (sum % 2 == 0 ==> sum == 0 || sum % 2 == 0) && (i >= 2 ==> sum >= 0) && (i > 2 ==> sum >= 0) && (i <= n+1 || sum <= n*(n+1)/2) && (i <= n+1 || sum <= n * (n + 1) / 2) && (i <= n + 1 || sum <= n*(n+1)/2) && (i <= n + 1 || sum <= n * (n + 1) / 2) && (i % 2 == 0 || i % 2 == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (2 <= i) && (0 <= sum);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int n) {
    /*@ assert (2 <= i) && (0 <= sum) && ((i<=\at(n,Pre)) ==> (sum == evendiv_sum(n, i - 1))) && ((i<=\at(n,Pre)) ==> (0 <= sum)) && ((!(i<=\at(n,Pre))) ==> (sum == evendiv_sum(n, \at(n,Pre)))) && (n == \at(n,Pre)) && (\forall integer k) && (sum > 0 ==> \exists integer k); */
}
