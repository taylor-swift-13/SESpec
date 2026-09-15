
#include <stdlib.h>

/*@
  logic integer dp_spec(integer k) =
    k == 0 ? 0 :
    k == 1 ? 1 :
    dp_spec(k - 1) + 2 * dp_spec(k - 2);
*/

int foo302(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant dp_len == n + 1;
          loop invariant \valid(dp + (0 .. dp_len - 1));
          loop invariant dp[0] == dp_spec(0) && dp[1] == dp_spec(1);
          loop invariant \forall integer k; 0 <= k < i ==> dp[k] == dp_spec(k);
          loop assigns i, dp[..];
            */
            for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
            
        return dp[n];
}
