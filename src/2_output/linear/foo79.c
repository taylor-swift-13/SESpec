
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo79(int x, int y) 

            /*@
            Require x >= y  && y >= 0
            Ensure Results(__return)
            */
            {

    int i = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i && i <= x) &&
(y == y@pre) &&
(x == x@pre
        loop assigns i)
    */
    
    while (unknown()) {
        if (i < y) {
            i = (i + 1);
        }
    }
  
    
    
}