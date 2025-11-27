
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo1() 
/*@

Require emp

Ensure emp
*/{
  
    int x = 1;
    int y = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == (y * (y - 1)) / 2 + 1) &&
(y >= 0
      loop assigns x, y)
    */
    
    while (y < 100000) {
      
        x = x + y;
        y = y + 1;
      
    }
  
    
  }