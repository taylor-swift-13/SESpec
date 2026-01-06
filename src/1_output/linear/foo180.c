
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo180(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int x;
    int m;

    x = 0;
    m = 0;


    while(x < n){
       if(unknown()){
       m = x;
      }
       x = x + 1;
      }

    

  }