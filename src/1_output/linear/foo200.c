
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo200() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x1;
    int x2;
    int x3;
    int d1;
    int d2;
    int d3;

    d1 = 1;
    d2 = 1;
    d2 = 1;


    while(x1 > 0 && x2 > 0 && x3 > 0){
       if(unknown()){
       x1 = x1 - d1;
      }
       if(unknown()){
       x2 = x2 - d2;
      }
       if(unknown()){
       x3 = x3 - d3;
      }
      }

    

  }