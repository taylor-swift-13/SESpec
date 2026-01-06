
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo231() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x && x <= 268435455) &&
(x >= 65521 => x % 2 == 1
          loop assigns x)
    */
    
            while (x < 268435455) {
       if (x < 65521) {
       x++;
      }
       else {
       x += 2;
      }

      }

    

  }