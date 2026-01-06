
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo9(int x,int y) 

            /*@
            Require x >= 0 && x <= 2 && y <= 2 && y >= 0
            Ensure Results(__return)
            */
            {

  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == x@pre + 2 * (\at(x, Here) - x@pre)/2) &&
(y == y@pre + 2 * (\at(y, Here) - y@pre)/2) &&
((x - x@pre) % 2 == 0) &&
((y - y@pre) % 2 == 0) &&
(x >= x@pre && y >= y@pre) &&
((x == x@pre) => (y == y@pre)) &&
((x == x@pre + 2) => (y >= y@pre + 2)) &&
((x == x@pre + 4) => (y >= y@pre + 4)
          loop assigns x, y)
    */
    
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
  
    
  
    
  
  }