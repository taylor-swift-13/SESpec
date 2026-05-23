
int foo276(int n, int k) {

    int mod = 1000000007;
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    int dp_len = n+1;
    dp[0] = 1;
    dp[1] = k;
    dp[2] = k*k;

    /*@
      loop invariant i >= 3;
      loop invariant dp[0] == 1;
      loop invariant dp[1] == k;
      loop invariant dp[2] == k * k;
      loop assigns i, dp[3..n];
    */
    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }

    return dp[n];
}
