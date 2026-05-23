
/*@
requires n >= 0;

ensures \true;
*/
int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 1;
        
        /*@
          loop invariant 0 <= i <= n + 1;
          loop invariant \exists integer k; 0 <= k < i && dp[k] == 1;
          loop invariant i <= dp_len;
          loop assigns i, dp[0..n];
        */
        for (int i = 1; i <= n; i++) {
            
            
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
