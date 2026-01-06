
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo126(int x, int y,int z1,int z2,int z3) 

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