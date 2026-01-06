
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo84(int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = -50;
  
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= y@pre && (y > 0 || x < 0)
      loop assigns x, y)
    */
    
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    
  
  }