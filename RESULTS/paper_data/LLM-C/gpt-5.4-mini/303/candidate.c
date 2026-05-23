#include <stdlib.h>

/*@
    requires n >= 1;
    ensures \result == \at(((int *)0)[0], Pre);
    assigns \nothing;
*/
int jacobsthalLucas(int n);

int jacobsthalLucas(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 2;
        dp[1] = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant dp[0] == 2;
            loop invariant dp[1] == 1;
            loop invariant \forall integer k; 2 <= k < i ==> dp[k] == dp[k - 1] + 2 * dp[k - 2];
            loop assigns i, dp[2..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}
