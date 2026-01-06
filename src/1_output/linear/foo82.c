
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo82(int x, int y,int z1,int z2,int z3) 

            /*@
            Require x >= y  && y >= 0
            Ensure Results(__return)
            */
            {

    int i = 0;
    
    
    while (unknown()) {
      if ( i < y )
      {
      i  = (i + 1);
      }

    }

    

}