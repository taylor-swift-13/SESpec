
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo300(int n) 

            /*@
            Require n <= 20000001
            Ensure Results(__return)
            */
            {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;


    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
       j = j + 3;
       else
       k = k + 3;
      }

    

  }