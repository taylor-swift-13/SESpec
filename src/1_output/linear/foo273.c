
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo273(int i) 

            /*@
            Require i >= 0 && i <= 200
            Ensure Results(__return)
            */
            {



    while (i > 0) {
       i = i - 1;
      }

    

  }