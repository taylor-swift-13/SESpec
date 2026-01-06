
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo272() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int k;

    i = 0;
    j = 0;


    while (i <= k) {
       i++;
       j = j + 1;
      }

    

  }