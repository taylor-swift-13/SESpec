#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (comb_step : Z -> Z -> Z) */

int foo384(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (k > n - k)
            k = n - k;
        int c = 1;
       
  /*0*/ 
 /*@ Inv
    (1 <= i && i <= k + 1) &&
    (c == comb_step(n, i - 1))
    */
for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}