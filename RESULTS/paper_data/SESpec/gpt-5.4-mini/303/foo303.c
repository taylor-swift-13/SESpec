
/*@
  logic integer dpval(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    dpval(k - 1) + 2 * dpval(k - 2);
*/

/*@
  requires n >= 1;
*/
int foo303(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 2;
        dp[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= dp_len;
          loop invariant dp[i - 2] == dpval(i - 2);
          loop invariant dp[i - 1] == dpval(i - 1);
          loop invariant dp[i - 2] > 0;
          loop invariant dp[i - 1] > 0;
          loop invariant i == n + 1 ==> dp[n] == dpval(n);
          loop invariant (i <= n) ==> (dp[i - 1] == dpval(i - 1) && dp[i - 2] == dpval(i - 2));
          loop invariant (i > n) ==> (dp[n] == dpval(n));
          loop assigns i, dp[0..dp_len-1];
            */
            for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
            
        return dp[n];
}
