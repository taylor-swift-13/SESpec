
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo286(int x, int y, int z) 

            /*@
            Require x == y && x >= 0 && x + y + z == 0
            Ensure Results(__return)
            */
            {



    while (x > 0) {
       x--;
       y--;
       z += 2;
      }

    

  }