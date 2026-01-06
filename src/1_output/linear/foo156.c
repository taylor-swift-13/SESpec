
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo156() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int j;
    int k;
    int t;

    j = 2;
    k = 0;


    while(unknown()){
       if (t == 0){
       j = j + 4;
      }
       else {
       j = j + 2;
       k = k + 1;
      }
      }

    

  }