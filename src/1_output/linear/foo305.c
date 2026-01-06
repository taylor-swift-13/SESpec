
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo305() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


    while (x < 1000000) {
       if (x < 750000) {
       x++;
      }
       else{
       x = x + 2;
      }
      }

    

  }