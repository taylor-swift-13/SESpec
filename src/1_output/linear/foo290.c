
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo290(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



    while (x < y) {
       if (x < 0){
       x = x + 7;
      }
       else {
       x = x + 10;
      }
       if (y < 0){
       y = y - 10;
      }
       else {
       y = y + 3;
      }

      }

    

  }