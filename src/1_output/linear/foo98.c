
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo98(int x) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int i =0;
    int j =0;
    int y =2;
    
    
    while (i <= x) {
      
      i  = i + 1;
      j  = j + y;
  
    }
  
  
  
  }