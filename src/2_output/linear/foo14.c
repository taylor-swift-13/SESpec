
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo14(int x,int y,int z1,int z2,int z3) 

            /*@
            Require x >= 0 && x <= 2 && y <= 2 && y >= 0
            Ensure Results(__return)
            */
            {

  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == x@pre + 2*(\at(x,Here) - x@pre)/2) &&
(y == y@pre + 2*(\at(y,Here) - y@pre)/2) &&
((y == y@pre) => (x == x@pre)) &&
(x >= x@pre && x <= x@pre + 2*(\at(x,Here) - x@pre)/2) &&
(y >= y@pre && y <= y@pre + 2*(\at(y,Here) - y@pre)/2) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre
          loop assigns x, y)
    */
    
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
      
   
  }