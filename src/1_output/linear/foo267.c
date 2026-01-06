
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo267(int k, int n) 

            /*@
            Require n >= 1 && k >= n
            Ensure Results(__return)
            */
            {

    int j;

    j = 0;


    while (j <= n - 1) {
       j = j + 1;
       k = k - 1;
      }

    

  }