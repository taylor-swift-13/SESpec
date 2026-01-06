
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo190(int y) 

            /*@
            Require y > -1000 && y < 1000
            Ensure Results(__return)
            */
            {

    int x;

    x = -50;


    while(x < 0){
       x = x + y;
       y = y + 1;
      }

    

  }