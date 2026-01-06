
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo102(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
  
    int x = 0;
    
    
    while (x < n) {
      
      x  = (x + 1);
      
    }
    
    
  }