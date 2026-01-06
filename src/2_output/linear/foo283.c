
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo283() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;
    y = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == 4 * y) &&
(y >= 0) &&
(x >= 0) &&
(x % 4 == 0
      loop assigns x, y)
    */
    
    while (unknown()) {
       x += 4;
       y++;
    }

    

  }