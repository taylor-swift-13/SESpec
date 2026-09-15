#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo302(int n);

int foo302(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (forall (k:Z), 2 <= k && k < i => dp_l[k] == dp_l[k - 1] + 2 * dp_l[k - 2]
          loop assigns i, dp_l[0..n])
    */
    
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}