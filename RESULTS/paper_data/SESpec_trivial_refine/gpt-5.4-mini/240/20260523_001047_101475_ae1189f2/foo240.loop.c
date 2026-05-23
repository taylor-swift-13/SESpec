
/*@
*/

 /*@
  requires 0 <= n;
  requires n <= INT_MAX - 1;
*/

int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant dp[0] == 1;
          loop assigns i, dp[1..n];
            */
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= j <= i;
          loop assigns j, dp[i];
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
            
        return dp[n];
}
