
/*@
  logic integer dp_seq(integer k, integer j) =
    j == 0 ? 1
    : j == 1 ? k
    : j == 2 ? k * k
    : ((k - 1) * (dp_seq(k, j - 1) + dp_seq(k, j - 2))) % 1000000007;
*/
/*@
   requires n >= 2;
   assigns \nothing;
 */
int foo276(int n, int k) {

    int mod = 1000000007;
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    int dp_len = n+1;
    dp[0] = 1;
    dp[1] = k;
    dp[2] = k*k;
    
    /*@
      loop invariant 3 <= i && i <= n+1;
      loop invariant 0 <= i;
      loop invariant dp_len == n+1;
      loop assigns i, dp[0 .. n];
    */
    for(int i=3;i<=n;i++){
        dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
    }
        
    return dp[n];
}
