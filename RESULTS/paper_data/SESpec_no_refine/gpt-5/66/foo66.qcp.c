#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo66(int y) 
/*@

Require emp
Ensure emp
*/{

    int x;

    x = 4 * y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x > 0) {
       x -= 4;
       y--;
      }

  }