
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo86(int y,int z1,int z2,int z3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = -50;
  
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= y@pre) &&
(x <= -50 + (y*(y-1))/2 - ((y@pre*(y@pre-1))/2)) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre
      loop assigns x, y)
    */
    
    while (x < 0) {
      x = x + y;
      y = y + 1;
    }
    
  
  }