#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prefix_sum : Z -> Z -> Z) */
int foo240(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
       
  /*@ Inv
    (dp_len == n + 1) &&
    (dp[0] == 1) &&
    (forall (k:Z), 0 <= k && k <= n => 0 <= k && k < dp_len) &&
    ((i <= n) => (i >= 1)) &&
    ((!(i <= n)) => true) &&
    (forall (k:Z), 1 <= k && k < i => dp[k] == prefix_sum(dp, k)) &&
    (forall (k:Z), 1 <= k && k < i => dp[k] >= 1) &&
    (forall (k:Z), 1 <= k + 1 < i => dp[k + 1] >= dp[k]) &&
    (forall (k:Z), 1 <= k && k < i => dp[k] == \sum(0, k - 1, \lambda integer t dp[t]))
    */
for (int i = 1; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant dp_len == n + 1;
          loop invariant dp[0] == 1;
          loop assigns i, dp[0 .. n];
            */
            /*@ Inv
    (1 <= i && i <= n + 1) &&
    (dp_len == n + 1) &&
    (dp[0] == 1)
    */
for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
            
        }
        return dp[n];
}