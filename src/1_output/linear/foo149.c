
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo149() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int i;
    int j;

    x = 0;
    y = 0;
    j = 0;
    i = 0;


    while(unknown()){
       x = x + 1;
       y = y + 1;
       i = x + i;
       if(unknown()){
       j = y + j;
      }
       else{
       j = y + j + 1;
      }
      }

  }