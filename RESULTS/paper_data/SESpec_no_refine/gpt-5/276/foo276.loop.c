
#include <stdlib.h>

int foo276(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
        int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 3 <= i <= n+1;
          loop invariant 0 <= i-1 < dp_len;
          loop invariant 0 <= i-2 < dp_len;
          loop invariant dp[0] == 1;
          loop invariant dp[1] == k;
          loop invariant dp[2] == k*k;
          loop invariant \forall integer t; 3 <= t < i ==> dp[t] == ((k-1) * (dp[t-1] + dp[t-2])) % mod;
          loop assigns i, dp[..];
            */
            for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
            
        return dp[n];
}
