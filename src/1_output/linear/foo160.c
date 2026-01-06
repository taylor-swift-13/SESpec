
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo160() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int i;
    int j;

    x = i;
    y = j;


    while(x != 0){
       x = x - 1;
       y = y - 1;
      }

    

  }