
#include <stdlib.h>

/*@
  logic integer dp_rec(integer k) =
    k == 0 ? 0
  : k == 1 ? 1
  : dp_rec(k-1) + 2*dp_rec(k-2);
*/

/*@
  predicate dp_prefix(int* dp, integer len, integer hi) =
    0 <= hi <= len &&
    \forall integer j; 0 <= j < hi ==> dp[j] == dp_rec(j);
*/

int foo302(int n) {

    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp_len = n + 1;
    dp[0] = 0;
    dp[1] = 1;

    /*@
      loop invariant 2 <= i;
      loop invariant dp[0] == dp_rec(0) && dp[1] == dp_rec(1);
      loop assigns i, dp[0..n];
    */
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }

    return dp[n];
}
