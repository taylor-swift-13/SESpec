#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo213() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;

    x = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x % 5 == 0
          loop assigns x)
    */
    
            while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
      }

  }