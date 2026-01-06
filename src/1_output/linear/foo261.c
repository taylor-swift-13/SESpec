
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo261() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


    while (unknown()) {
       if(x == 0){
       x = 1;
      }
      }

    

  }