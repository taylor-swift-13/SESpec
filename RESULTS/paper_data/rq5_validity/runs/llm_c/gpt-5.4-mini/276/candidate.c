#include <stdlib.h>

/*@
    requires n >= 0;
    requires k >= 0;
    requires n >= 2;
    requires \valid_range((int *)malloc(sizeof(int) * (n+1)), 0, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int countNoOfWays(int n, int k);

int countNoOfWays(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        /*@
            loop invariant 3 <= i <= n+1;
            loop invariant \valid_range(dp, 0, n);
            loop invariant dp[0] == 1;
            loop invariant dp[1] == k;
            loop invariant dp[2] == k*k;
            loop assigns i, dp[3..n];
            loop variant n - i + 1;
        */
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
}
