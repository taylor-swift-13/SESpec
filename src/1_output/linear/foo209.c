
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo209() 

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


    while(unknown()){
       x = x + 1;
       y = y + 2;
       z = z + 3;
      }

    

  }