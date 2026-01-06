
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo125(int x, int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i = x;
    int j = y;
    
    
    while (x != 0) {
  
      x  = x - 1;
      y  = y - 1;
  
    }
  
    
  
  }