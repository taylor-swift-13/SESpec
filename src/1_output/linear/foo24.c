
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo24() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
  
    int i=1;
    int j=10;
   
    
    while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
      
  
    }
  
    
  
  }