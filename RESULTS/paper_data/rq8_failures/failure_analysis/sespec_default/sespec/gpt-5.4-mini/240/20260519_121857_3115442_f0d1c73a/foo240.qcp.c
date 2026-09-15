#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo240(int n);

int foo240(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (dp_l[0] == 1) &&
(forall (k:Z), 1 <= k && k < i => dp_l[k] == 0
          loop assigns i, dp_l[0 .. n])
    */
    
            for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant dp[0] == 1;
              loop invariant \forall integer k; 1 <= k < i ==> dp[k] == 0;
              loop assigns i, dp[0 .. n];
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
        return dp[n];
}