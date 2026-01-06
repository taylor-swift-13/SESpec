
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo281(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre < y@pre) => (x == x@pre + 100 * (\at(x,Here) - x@pre)/100) && (x <= y + 99)) &&
((!(x@pre < y@pre)) => ((y == y@pre) && (x == x@pre))) &&
(y == y@pre
        loop assigns x)
    */
    
    while (x < y) {
        x = x + 100;
    }

    

  }