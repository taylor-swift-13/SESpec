
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo226() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 1;
    y = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((y == 0) && (x == 1)) || (x == 0)) &&
(y >= 0 && y <= 1024
      loop assigns x, y)
    */
    
    while (y < 1024) {
       x = 0;
       y = y + 1;
    }

    

  }