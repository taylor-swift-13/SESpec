
/*@ logic integer ways(integer k, integer n) =
      n == 0 ? 1 :
      n == 1 ? k :
      n == 2 ? k * k :
      ((k - 1) * (ways(k, n - 1) + ways(k, n - 2))) % 1000000007;
*/

/*@
  requires n >= 2;
  
  ensures \true;
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
          loop invariant i >= 3;
          loop invariant dp_len == n + 1;
          loop invariant dp[0] == 1;
          loop invariant dp[1] == k;
          loop invariant dp[2] == k * k;
          loop assigns i, dp[0..dp_len-1];
            */
            for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
            
        return dp[n];
}
