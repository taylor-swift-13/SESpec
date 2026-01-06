
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo235() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 268435441;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x % 2 == 1) &&
(x <= 268435441
      loop assigns x)
    */
    
    while (x > 1) {
        x -= 2;
    }

    

  }