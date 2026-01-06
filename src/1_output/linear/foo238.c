
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo238() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int i;
    unsigned int j;
    unsigned int k;

    i = 0;
    j = 0;
    k = 0;


    while (k < 268435455) {
       i = i + 1;
       j = j + 2;
       k = k + 3;
      }

    

  }