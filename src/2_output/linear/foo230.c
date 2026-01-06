
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo230() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x) &&
(x <= 65520 || (x >= 65520 && (x - 65520) % 2 == 0)) &&
(x < 65520 || x % 2 == 0
      loop assigns x)
    */
    
    while (x < 268435455) {
        if (x < 65520) {
            x++;
        }
        else {
            x += 2;
        }
    }

    

  }