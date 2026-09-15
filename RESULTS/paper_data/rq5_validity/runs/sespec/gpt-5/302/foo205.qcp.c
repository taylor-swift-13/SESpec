#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo205(int n);

int foo205(int n) 
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
    (2 <= i) &&
(dp_len == n + 1) &&
(dp_l[0] == 0 && dp_l[1] == 1) &&
(forall (j:Z), 2 <= j && j < i => dp_l[j] == dp_l[j-1] + 2 * dp_l[j-2]) &&
(forall (k:Z), 0 <= k && k < i => dp_l[k] == fib2(k)) &&
((!(i <= n)) => (forall (k:Z), 0 <= k && k <= n => dp_l[k] == fib2(k))
          loop assigns i, dp_l[0 .. dp_len - 1])
    */
    
            for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}