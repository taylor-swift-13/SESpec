
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo159(int k, int n) 

            /*@
            Require n > 0 && k > n
            Ensure Results(__return)
            */
            {

    int j;

    j = 0;


    while(j < n){
       j = j + 1;
       k = k - 1;
      }

    

  }