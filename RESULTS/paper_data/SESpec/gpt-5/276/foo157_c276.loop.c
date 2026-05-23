
#include <stdlib.h>

/*@
  logic integer dp_spec(integer k, integer n, integer mod) =
    n == 0 ? 1 :
    n == 1 ? k :
    n == 2 ? (k * k) % mod :
    ((k - 1) * (dp_spec(k, n - 1, mod) + dp_spec(k, n - 2, mod))) % mod;
*/

int foo157_c276(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
        int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 3 <= i;
          loop invariant dp_len == n+1;
          loop invariant dp[0] == 1;
          loop invariant dp[1] == k;
          loop invariant dp[2] == k*k;
          loop assigns i, dp[3..n];
            */
            for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
            
        return dp[n];
}
