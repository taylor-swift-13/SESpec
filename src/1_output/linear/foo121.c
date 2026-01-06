
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo121() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
 
    int i = 1;
    int sn = 0;
    
     
    while (i <= 8) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    
  
  }