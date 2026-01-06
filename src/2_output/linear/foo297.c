
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo297() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;
    y = 500000;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x && x <= 1000000) &&
((x <= 500000 => y == 500000) && 
                     (x > 500000 => y == x)
      loop assigns x, y)
    */
    
    while(x < 1000000) {
        if (x < 500000) {
            x = x + 1;
        }
        else {
            x = x + 1;
            y = y + 1;
        }
    }

    

  }