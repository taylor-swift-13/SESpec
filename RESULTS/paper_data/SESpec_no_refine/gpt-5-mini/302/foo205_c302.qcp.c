#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo205_c302(int n);

int foo205_c302(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}