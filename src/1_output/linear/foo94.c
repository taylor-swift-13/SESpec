
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo94(int n,int k) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
  
    int i = 0;
    int j = 0;
    
    
    while (i <= n) {
      
       i  = i + 1;
       j  = j + i;
      
  
    }
    
  
  }