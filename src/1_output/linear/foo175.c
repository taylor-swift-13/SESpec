
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo175(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int i;
    int c;

    i = 0;
    c = 0;


    while(i < n){
       c = c + i;
       i = i + 1;
      }

    

  }