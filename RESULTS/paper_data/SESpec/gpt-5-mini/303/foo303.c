
#include <stdlib.h>

/*@
  logic integer dp_sum(integer k) =
    k == 0 ? 2
    : k == 1 ? 1
    : (dp_sum(k-1) + 2*dp_sum(k-2));
*/

/*@
  requires n >= 0;
  
  ensures n == 0 ==> \result == 2;
  ensures n == 1 ==> \result == 1;
  ensures n >= 2 ==> \true;
*/
int foo303(int n) {

    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp_len = n + 1;
    dp[0] = 2;
    dp[1] = 1;
        
    /*@
      loop invariant 2 <= i;
      loop invariant dp_len == n + 1;
      loop invariant dp[0] == 2;
      loop invariant dp[1] == 1;
      loop invariant i >= 2 ==> dp[i-1] == dp_sum(i-1);
      loop invariant i >= 3 ==> dp[i-2] == dp_sum(i-2);
      loop invariant (i == n+1) ==> dp[n] == dp_sum(n);
      loop assigns i, dp[0 .. n];
    */
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
            
    return dp[n];
}
