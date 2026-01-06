
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo27(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = n;
    
    
    while (x > 1) {
      
       x  = x - 1;
  
    }
  
   
  }