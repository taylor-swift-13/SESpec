
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo25() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 10000;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= 0) &&
(x <= 10000
      loop assigns x)
    */
    
    while (x > 0) {
      x = x - 1;
    }
  
    
  }