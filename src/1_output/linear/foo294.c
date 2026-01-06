
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



    while (xa > 0) {
       xa--;
       ya++;
      }

    

  }