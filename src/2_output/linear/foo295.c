
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo295() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x && x <= 100000000) &&
(x <= 10000000 || (x - 10000000) % 2 == 0) &&
(x >= 10000000 => (100000000 - x) % 2 == 0
      loop assigns x)
    */
    
    while (x < 100000000) {
        if (x < 10000000) {
            x++;
        } else {
            x += 2;
        }
    }

    

  }