
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo278(int i, int j, int k) 

            /*@
            Require k > i - j && i < j
            Ensure Results(__return)
            */
            {



    while (i < j) {
       k = k + 1;
       i = i + 1;
      }

    

  }