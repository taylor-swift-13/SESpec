#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (dp_sum : Z -> Z) */
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
    (2 <= i) &&
    (dp_len == n + 1) &&
    (dp[0] == 2) &&
    (dp[1] == 1) &&
    (i >= 2 => dp[i-1] == dp_sum(i-1)) &&
    (i >= 3 => dp[i-2] == dp_sum(i-2)) &&
    ((i == n+1) => dp[n] == dp_sum(n))
    */
for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
        return dp[n];
}