
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo275(int x, int y) 

            /*@
            Require y > 0 || x > 0
            Ensure Results(__return)
            */
            {



    while (x + y <= -2) {
       if (x > 0) {
       x++;
      }
       else {
       y++;
      }
      }

    

  }