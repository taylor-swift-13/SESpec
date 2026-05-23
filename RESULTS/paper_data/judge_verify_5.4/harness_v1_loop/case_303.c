#include <limits.h>
#include <stdlib.h>

/*@logic integer dpval(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    dpval(k - 1) + 2 * dpval(k - 2);*/

/*@ requires (2 <= i <= dp_len) && (dp[i - 2] == dpval(i - 2)) && (dp[i - 1] == dpval(i - 1)) && (dp[i - 2] > 0) && (dp[i - 1] > 0) && (i == n + 1 ==> dp[n] == dpval(n)) && ((i <= n) ==> (dp[i - 1] == dpval(i - 1) && dp[i - 2] == dpval(i - 2))) && ((i > n) ==> (dp[n] == dpval(n)));
    assigns \nothing;
*/
void check_A_implies_B(int *dp, int *dp_len, int *i, int k, int *n) {
    /*@ assert (dp_len == n + 1) && (dp_len == n + 1 && dp[0] == 2 && dp[1] == 1) && (dp[1] == 1) && (dp[0] == 2) && (dp[0] == 2 && dp[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (0 <= i); */
}

/*@ requires (dp_len == n + 1) && (dp_len == n + 1 && dp[0] == 2 && dp[1] == 1) && (dp[1] == 1) && (dp[0] == 2) && (dp[0] == 2 && dp[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *dp, int *dp_len, int *i, int k, int *n) {
    /*@ assert (2 <= i <= dp_len) && (dp[i - 2] == dpval(i - 2)) && (dp[i - 1] == dpval(i - 1)) && (dp[i - 2] > 0) && (dp[i - 1] > 0) && (i == n + 1 ==> dp[n] == dpval(n)) && ((i <= n) ==> (dp[i - 1] == dpval(i - 1) && dp[i - 2] == dpval(i - 2))) && ((i > n) ==> (dp[n] == dpval(n))); */
}
