
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo205() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    y = x;


    while(x < 1024){
       x = x + 1;
       y = y + 1;
      }

    

  }