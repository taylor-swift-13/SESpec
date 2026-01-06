
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo222(int w, int x, int y, int z) 

            /*@
            Require x > 0 && y > 0 && z > 0 && w > 0
            Ensure Results(__return)
            */
            {


    x = w;
    z = x + 1;
    y = w + 1;


    while (unknown()) {
       y = y + 1;
       z = z + 1;
      }

  }