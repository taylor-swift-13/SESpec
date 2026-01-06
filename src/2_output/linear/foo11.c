
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo11(int x, int y,int z1,int z2,int z3) 

            /*@
            Require x >= 0 && x <= 10 && y <= 10 && y >= 0
            Ensure Results(__return)
            */
            {
  
  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x == 20) => (y != 0)) &&
(y == x - x@pre + y@pre) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre)
    */
    
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }

       
    
  
   
  }