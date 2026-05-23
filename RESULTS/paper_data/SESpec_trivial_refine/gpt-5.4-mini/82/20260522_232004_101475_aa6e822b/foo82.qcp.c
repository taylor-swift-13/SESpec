#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo82(int z,int k)
/*@

Require emp
Ensure emp
*/{

    int x=1;
    int y=1;
    int c=1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }

  }