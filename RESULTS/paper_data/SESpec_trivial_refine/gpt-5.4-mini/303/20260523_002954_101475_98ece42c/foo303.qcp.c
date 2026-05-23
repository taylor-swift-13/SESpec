#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (2 <= i && i <= n + 1) &&
    (dp[0] == 2) &&
    (dp[1] == 1) &&
    (forall (k:Z), 2 <= k && k < i => dp[k] == dp[k - 1] + 2 * dp[k - 2])
    */
for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
        return dp[n];
}