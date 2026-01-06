
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo182(int k, int n) 

            /*@
            Require n >= 0 && n <= 20000001 && k >= 0 && k <= 20000001
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    j = 0;
    i = 0;


    while(i <= n){
       i = i + 1;
       j = j + 1;
      }

    

  }