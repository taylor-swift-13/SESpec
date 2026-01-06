
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo223() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


    while(unknown()){
       x = x + 2;
      }

    

  }