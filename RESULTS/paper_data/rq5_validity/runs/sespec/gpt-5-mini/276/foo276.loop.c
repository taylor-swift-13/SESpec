
/*@ 
  logic integer MOD() = 1000000007;

  logic integer dp_seq(integer k, integer i) =
    i == 0 ? 1
    : i == 1 ? k
    : i == 2 ? k * k
    : ((k - 1) * (dp_seq(k, i-1) + dp_seq(k, i-2))) % MOD();
*/

int foo276(int n, int k) {

    int mod = 1000000007;
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    int dp_len = n+1;
    dp[0] = 1;
    dp[1] = k;
    dp[2] = k*k;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 3 <= i <= n+1;
      loop invariant \valid(dp + (0..n));
      loop invariant dp_len == n+1;
      loop invariant \forall integer j; 0 <= j < i ==> dp[j] == dp_seq(k, j);
      loop assigns i, dp[..];
    */
    for(int i=3;i<=n;i++){
        dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
    }
        
    return dp[n];
}
