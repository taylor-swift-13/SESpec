
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo264() 

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
    (x == y) &&
(((y == 1) && (x == 1)) || (x >= 1 && y >= 1)
      loop assigns x, y)
    */
    
    while (unknown()) {
       x = x + y;
       y = x;
    }

    

  }