
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo36() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int c = 0;
  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((c == 0)) || ((1 <= c && c <= 40) && (c != 40 => c <= 39))
          loop assigns c)
    */
    
            while (unknown()) {
      if (unknown()) {
        if (c != 40) {
          c  = c + 1;
        }
      } else {
        if (c == 40) {
          c  = 1;
        }
      }
    }

      
    
  
  }