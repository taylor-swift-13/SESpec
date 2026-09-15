
/*@
  logic integer sum_prefix{L}(int* a, integer hi) =
    hi <= 0 ? 0 : sum_prefix(a, hi - 1) + a[hi - 1];
*/


/*@
*/
        


int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant dp_len == n + 1;
          loop invariant \valid(dp + (0 .. dp_len-1));
          loop invariant dp[0] == 1;
          loop invariant \forall integer t; 1 <= t < i ==> dp[t] == sum_prefix(dp, t);
          loop invariant \forall integer k; 0 <= k < i ==> \initialized(&dp[k]);
          loop assigns i, j, dp[..];
            */
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n;
          loop invariant 0 <= j <= i;
          loop invariant \valid(dp + (0 .. dp_len-1));
          loop invariant dp_len == n + 1;
          loop invariant \forall integer k; 0 <= k < i ==> \initialized(&dp[k]);
          loop invariant dp[i] == \at(dp[i], Pre) + \sum(integer k, 0, j-1, dp[k]);
          loop assigns dp[i], j;
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
            
        return dp[n];
}
