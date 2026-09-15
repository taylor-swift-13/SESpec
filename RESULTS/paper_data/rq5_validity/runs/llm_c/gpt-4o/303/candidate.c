#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result == 2 || \result == 1 || \result == \sum(0, n, \lambda integer i; (i == 0 ? 2 : (i == 1 ? 1 : (jacobsthalLucas(i - 1) + 2 * jacobsthalLucas(i - 2)))));
    assigns \nothing;
*/
int jacobsthalLucas(int n);

/*@
    requires n >= 0;
    ensures \result == 2 || \result == 1 || \result == \sum(0, n, \lambda integer i; (i == 0 ? 2 : (i == 1 ? 1 : (jacobsthalLucas(i - 1) + 2 * jacobsthalLucas(i - 2)))));
    assigns \nothing;
*/
int jacobsthalLucas(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 2;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}
