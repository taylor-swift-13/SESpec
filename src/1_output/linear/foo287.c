
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo287(int x, int y) 

            /*@
            Require x < 100 && y < 100
            Ensure Results(__return)
            */
            {



    while (x < 100 && y < 100) {
       x = x + 1;
       y = y + 1;
      }

    

  }