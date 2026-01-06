
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo265(int l) 

            /*@
            Require l > 0
            Ensure Results(__return)
            */
            {

    int n;
    int i;

    i = l;


    while (i < n) {
       i = i + 1;
      }

    

  }