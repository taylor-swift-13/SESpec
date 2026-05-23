#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo240(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
       
  /*0*/ 
 /*@ Inv
    (1 <= i && i <= n + 1) &&
    (dp[0] == 1)
    */
for (int i = 1; i <= n; i++) {
           
  /*1*/ 
 /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= j && j <= i)
    */
for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
}