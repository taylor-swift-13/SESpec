
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo148() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 1;
    y = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= 1 && y >= 1) &&
(y >= x
      loop assigns x, y)
    */
    
    while(unknown()) {
       x = x + y;
       y = x + y;
    }

  }