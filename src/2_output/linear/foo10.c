
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo10(int x,int y) 

            /*@
            Require x >= 0 && x <= 2 && y <= 2 && y >= 0
            Ensure Results(__return)
            */
            {

  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == x@pre + (y - y@pre)) &&
(y == y@pre + (x - x@pre)) &&
(y >= y@pre && x >= x@pre) &&
((x - x@pre) == (y - y@pre)) &&
((x % 2) == (x@pre % 2)) &&
((y % 2) == (y@pre % 2))
    */
    
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
      
  
  }