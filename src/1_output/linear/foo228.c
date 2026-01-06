
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo228() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;


    while (x < 99) {
       if(y % 2 == 0){
       x = x + 2;
      }
       else{
       x = x + 1;
      }
      }

    

  }