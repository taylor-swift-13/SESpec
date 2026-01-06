
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo195() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int i;
    int j;

    i = 0;
    j = 0;
    x = 0;
    y = 0;


    while(unknown()){
       i = i + x + 1;
       if(unknown()){
       j = j + y + 1;
      }
       else{
       j = j + y + 2;
      }
       x = x + 1;
       y = y + 1;
      }

    

  }