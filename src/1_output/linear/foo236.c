
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo236() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;

    x = 268435440;


    while (x > 0) {
       x -= 2;
      }

    

  }