#include <stdlib.h>

int countNoOfWays(int n, int k);

/*@
    requires n >= 2;
    requires \true;
    assigns \nothing;
    ensures -2147483648 <= \result <= 2147483647;
*/
int countNoOfWays(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
int dp_len = n+1;
        /*@ assert \valid(dp + (0..n)); */
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        /*@
            loop invariant 3 <= i <= n+1;
            loop invariant \forall integer j; 0 <= j < i ==> \valid(&dp[j]);
            loop assigns i, dp[3..n];
            loop variant n - i + 1;
        */
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
}
