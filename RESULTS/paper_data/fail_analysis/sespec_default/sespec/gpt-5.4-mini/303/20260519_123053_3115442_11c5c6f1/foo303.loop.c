
/*@
  logic integer dp_value(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    dp_value(k - 1) + 2 * dp_value(k - 2);
*/

int foo303(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 2;
        dp[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, dp[0..n];
            */
            for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
            
        return dp[n];
}
