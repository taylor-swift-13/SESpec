#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (undef_data_at : Z -> Prop) */

void foo53() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;

    x = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x % 5 == 0) &&
    (x <= 105)
    */
    
    while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
    }

  }