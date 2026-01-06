
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo281(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



    while (x < y) {
       x = x + 100;
      }

    

  }