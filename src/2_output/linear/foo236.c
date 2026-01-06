
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo236() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 268435440;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == 268435440 - 2*(268435440 - x)/2) &&
(x % 2 == 0
      loop assigns x)
    */
    
    while (x > 0) {
        x -= 2;
    }

    

  }