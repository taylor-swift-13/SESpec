#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo300_c385(int n, int m);

int foo300_c385(int n, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
}