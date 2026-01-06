
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo225() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;

    x = 1;


    while(unknown()){
       x = x + 2;
      }

    

  }