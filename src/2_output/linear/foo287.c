
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo287(int x, int y) 

            /*@
            Require x < 100 && y < 100
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre < 100 && y@pre < 100) => (x == x@pre + (\at(x,Here) - x@pre) && x <= 100)) &&
((x@pre < 100 && y@pre < 100) => (y == y@pre + (\at(y,Here) - y@pre) && y <= 100)) &&
((!(x@pre < 100 && y@pre < 100)) => ((y == y@pre)&&(x == x@pre))
        loop assigns x, y)
    */
    
    while (x < 100 && y < 100) {
       x = x + 1;
       y = y + 1;
    }

    

  }