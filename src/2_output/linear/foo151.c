
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo151() 

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
    (0 <= x && x <= 4 => y == 100 * x) &&
(x >= 4 => y == 400 + (x - 4)) &&
(x >= 0
      loop assigns x, y)
    */
    
    while(unknown()) {
        if(x >= 4) {
            x = x + 1;
            y = y + 1;
        }
        else if(x < 0) {
            y = y - 1;
        }
        else {
            x = x + 1;
            y = y + 100;
        }
    }

    

  }