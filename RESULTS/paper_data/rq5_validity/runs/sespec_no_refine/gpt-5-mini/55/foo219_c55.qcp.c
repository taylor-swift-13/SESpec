#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo219_c55(unsigned int y) 
/*@

Require emp
Ensure emp
*/{

    unsigned int x;

    x = 2;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x < y) {
       if (x < y / x) {
       x *= x;
      }
       else {
       x++;
      }
      }

  }