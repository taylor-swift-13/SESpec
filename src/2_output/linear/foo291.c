
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo291(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= x@pre) &&
(y - x <= y@pre - x@pre) &&
((!(x@pre < y@pre)) => ((y == y@pre) && (x == x@pre))
        loop assigns x, y)
    */
    
    while (x < y) {
        if (x < 0) {
            x = x + 7;
        } else {
            x = x + 10;
        }
        if (y < 0) {
            y = y - 10;
        } else {
            y = y + 3;
        }
    }

    

  }