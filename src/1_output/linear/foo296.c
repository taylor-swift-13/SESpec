
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo296() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;
    unsigned int y;

    x = 0;
    y = 0;


    while (x < 1000000) {
       if (x < 500000) {
       y++;
      }
       else {
       y--;
      }
       x++;
      }

    

  }