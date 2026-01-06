
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo178(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


    while(x < n){
       x = x + 1;
      }

    

  }