
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo284(int y) 

            /*@
            Require y >= 0 && y <= 20000001
            Ensure Results(__return)
            */
            {

    int x;

    x = 4 * y;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == 4 * y) &&
(y >= 0) &&
(y <= y@pre
        loop assigns x, y)
    */
    
    while (x > 0) {
        x -= 4;
        y--;
    }

    

  }