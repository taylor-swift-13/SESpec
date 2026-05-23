#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo292_c382(int n, int x, int y);

int foo292_c382(int n, int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
}