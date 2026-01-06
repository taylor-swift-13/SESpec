
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo75(int y,int x1,int x2,int x3) 

            /*@
            Require 0 <= y && y <= 127
            Ensure Results(__return)
            */
            {
  int c = 0;
  int z = 36 * y;
  

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c && c <= 36) &&
(z == 36 * y + c) &&
(x3 == x3@pre) &&
(x2 == x2@pre) &&
(x1 == x1@pre) &&
(y == y@pre
          loop assigns z, c)
    */
    
            while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }
    
      
  
}