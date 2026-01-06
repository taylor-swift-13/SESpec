
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo189() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;
    y = 50;


    while(x < 100){
       if(x < 50){
       x = x + 1;
      }
       else{
       x = x + 1;
       y = y + 1;
      }
      }

    

  }