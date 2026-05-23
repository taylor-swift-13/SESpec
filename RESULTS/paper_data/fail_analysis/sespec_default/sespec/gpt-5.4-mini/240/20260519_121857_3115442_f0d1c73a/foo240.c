
int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant dp[0] == 1;
          loop invariant \forall integer k; 1 <= k < i ==> dp[k] == 0;
          loop assigns i, dp[0 .. n];
            */
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant dp[0] == 1;
              loop invariant \forall integer k; 1 <= k < i ==> dp[k] == 0;
              loop assigns i, dp[0 .. n];
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
            
        return dp[n];
}
