
/*@
  requires n >= 0;
  assigns \nothing;
*/
int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant dp_len == n + 1;
          loop invariant dp[0] == 1;
          loop invariant \forall integer k; 0 <= k <= n ==> 0 <= k < dp_len;
          loop invariant (i <= n) ==> (i >= 1);
          loop invariant (!(i <= n)) ==> \true;
          
          loop invariant \forall integer k; 1 <= k < i ==> dp[k] >= 1;
          loop invariant \forall integer k; 1 <= k + 1 < i ==> dp[k + 1] >= dp[k];
          loop invariant \forall integer k; 1 <= k < i ==> dp[k] == \sum(0, k - 1, \lambda integer t; dp[t]);
            */
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant dp_len == n + 1;
          loop invariant dp[0] == 1;
          loop assigns i, dp[0 .. n];
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
            
        return dp[n];
}
