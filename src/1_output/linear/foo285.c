
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo285() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;


    while (x > 0) {
       x++;
       y++;
       z -= 2;
      }

    

  }