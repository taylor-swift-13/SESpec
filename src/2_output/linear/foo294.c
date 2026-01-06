
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo294(int xa, int ya) 

            /*@
            Require xa + ya > 0
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((xa@pre > 0) => (xa + ya == xa@pre + ya@pre)) &&
((xa@pre > 0) => (ya == ya@pre + (xa@pre - xa))) &&
((!(xa@pre > 0)) => ((ya == ya@pre)&&(xa == xa@pre))
        loop assigns xa, ya)
    */
    
    while (xa > 0) {
        xa--;
        ya++;
    }

    

  }