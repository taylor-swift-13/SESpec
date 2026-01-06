
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo219() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int s;

    s = 0;


    while(unknown()){
       if (s != 0){
       s = s + 1;
      }
      }

    

  }