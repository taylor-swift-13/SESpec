
/*@
  logic integer dp_rec(integer n) =
    n <= 0 ? 0 :
    n == 1 ? 1 :
    dp_rec(n - 1) + 2 * dp_rec(n - 2);
*/

int foo302(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
        
        /*@
          loop invariant \forall integer k; 2 <= k < i ==> dp[k] == dp[k - 1] + 2 * dp[k - 2];
          loop assigns i, dp[0..n];
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
            
        return dp[n];
}
