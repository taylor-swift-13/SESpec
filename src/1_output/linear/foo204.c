
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo204(int x, int y) 

            /*@
            Require x <= 5 && x >= 4 && y <= 5 && y >= 4
            Ensure Results(__return)
            */
            {



    while(unknown()){
       if(x >= 0 && y >= 0){
       x = x - 1;
      }
       else if(x < 0 && y >= 0){
       y = y - 1;
      }
       else if(y < 0){
       x = x + 1;
       y = y - 1;
      }
      }

    

  }