
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo183(int t, int x, int y) 

            /*@
            Require x != y && t == y
            Ensure Results(__return)
            */
            {

    int i;

    i = 0;


    while(x > 0){
       y = x + y;
      }

    

  }