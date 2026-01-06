
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo301(int n) 

            /*@
            Require n <= 50000001
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    i = 0;
    j = 0;


    while(i < n){
       if(unknown())
       i = i + 6;
       else
       i = i + 3;
      }

    

  }