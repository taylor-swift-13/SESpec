
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo262(int n) 

            /*@
            Require n >= 1 && n <= 1000
            Ensure Results(__return)
            */
            {

    int sum;
    int i;

    sum = 0;
    i = 0;


    while (i < n) {
       sum = sum + i;
       i = i + 1;
      }

    

  }