#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo157_c276(int n, int k);

int foo157_c276(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
}