
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo277(int n) 

            /*@
            Require n >= 0 && n <= 20000001
            Ensure Results(__return)
            */
            {

    int i;
    int k;

    i = 0;
    k = n;


    while (i < n) {
       k--;
       i += 2;
      }

    

  }