
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo280(int x, int y) 

            /*@
            Require x < y
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(x@pre < y@pre)) => ((y == y@pre) && (x == x@pre))) &&
(y == y@pre
        loop assigns x)
    */
    
    while (x < y) {
        x = x + 100;
    }

    

  }