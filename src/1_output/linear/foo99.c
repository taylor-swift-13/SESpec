
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo99(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = n;
    int y = 0;
    
    
    while (x > 0) {
      
      y  = y + 1;
      x  = x - 1;
  
    }
  
    
  
  }