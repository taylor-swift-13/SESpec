
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo282(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int i;
    int k;

    i = 0;
    k = n;


    while (i < n && n > 0) {
       k--;
       i++;
      }

    

  }