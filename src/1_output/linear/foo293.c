
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo293(int i, int j, int r) 

            /*@
            Require r > i + j
            Ensure Results(__return)
            */
            {



    while (i > 0) {
       i = i - 1;
       j = j + 1;
      }

    

  }