
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo30() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 100;
    
    
    while (x > 0) {
      
      x  = x - 1;
      
    }
  
    
  }