
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo128(int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 1;
    
    
    while (x < y) {
  
       x  = x + x ;
       
    }
  
    
  
  }