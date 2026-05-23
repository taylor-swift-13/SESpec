#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo313_c391(int n);

int foo313_c391(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 1;
        int square = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}