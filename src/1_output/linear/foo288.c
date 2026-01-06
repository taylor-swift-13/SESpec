
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo288(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



    while (x < y) {
       if ((x < 0 && y < 0)){
       x = x + 7;
       y = y - 10;
      }
       else if ((x < 0 && y >= 0)){
       x = x + 7;
       y = y + 3;
      }
       else {
       x = x + 10;
       y = y + 3;
      }

      }

    

  }