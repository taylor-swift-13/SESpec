
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo103() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 0 ;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x && x <= 100
      loop assigns x)
    */
    
    while (x < 100) {
        x = (x + 1);
    }
   
  }