
/*@
*/

 /*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1); */
/*@
  requires 0 <= n;
  requires n <= INT_MAX - 1;
  assigns \nothing;
  ensures \result == pow2(n);
  ensures n == 0 ==> \result == 1;
  ensures n > 0 ==> \result == 2 * pow2(n - 1);
  ensures \result >= 1;
  ensures \result == 1 <==> n == 0;
*/
int foo240(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant dp[0] == 1;
          loop assigns i, dp[1..n];
            */
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
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
