#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo253(int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int i;

    n = 0;
    i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < 2 * k) {
       if(i % 2 == 0){
       n = n + 1;
      }
       i = i + 1;
      }

  }