
#include <stdlib.h>

/*@
  logic integer fib2(integer i) =
    i == 0 ? 0 :
    i == 1 ? 1 :
             fib2(i - 1) + 2 * fib2(i - 2);
*/

int foo205(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i;
          loop invariant dp_len == n + 1;
          loop invariant dp[0] == 0 && dp[1] == 1;
          loop invariant \forall integer j; 2 <= j < i ==> dp[j] == dp[j-1] + 2 * dp[j-2];
          loop invariant \forall integer k; 0 <= k < i ==> dp[k] == fib2(k);
          loop invariant (!(i <= n)) ==> (\forall integer k; 0 <= k <= n ==> dp[k] == fib2(k));
          loop assigns i, dp[0 .. dp_len - 1];
            */
            for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
            
        return dp[n];
}
