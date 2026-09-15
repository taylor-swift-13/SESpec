#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo295_c384(int n, int k);

int foo295_c384(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (k > n - k)
            k = n - k;
        int c = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}