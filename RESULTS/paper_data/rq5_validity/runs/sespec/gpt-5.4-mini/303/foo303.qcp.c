#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (dpval : Z -> Z) */
int foo303(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 2;
        dp[1] = 1;
       
  /*@ Inv
    (2 <= i && i <= dp_len) &&
    (dp[i - 2] == dpval(i - 2)) &&
    (dp[i - 1] == dpval(i - 1)) &&
    (dp[i - 2] > 0) &&
    (dp[i - 1] > 0) &&
    (i == n + 1 => dp[n] == dpval(n)) &&
    ((i <= n) => (dp[i - 1] == dpval(i - 1) && dp[i - 2] == dpval(i - 2))) &&
    ((i > n) => (dp[n] == dpval(n)))
    */
for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}