
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo2() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 1;
    int y = 0;
  
    
    while (y < 1000) {
      
       x  = x + y;
       y  = y + 1;
      
    }
    
    
  }