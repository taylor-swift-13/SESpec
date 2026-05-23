#include <stdlib.h>

/*@
    requires n >= 0;
    requires k > 0;
    requires \valid(dp+(0..n));
    assigns dp[0..n];
    ensures \result >= 0;
*/
int countNoOfWays(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
}
