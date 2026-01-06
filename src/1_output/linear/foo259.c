
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo259() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


    while (unknown()) {
       if(unknown()){
       x = x + 1;
       if(x > 40){
       x = 0;
      }
      }
      }

    

  }