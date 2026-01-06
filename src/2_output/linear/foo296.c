
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo296() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;
    unsigned int y;

    x = 0;
    y = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x <= 1000000) &&
((x <= 500000 => y == x) && 
                     (x > 500000 => y == 1000000 - x)
      loop assigns x, y)
    */
    
    while (x < 1000000) {
        if (x < 500000) {
            y++;
        }
        else {
            y--;
        }
        x++;
    }

    

  }