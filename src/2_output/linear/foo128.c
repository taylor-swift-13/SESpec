
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo128(int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < y@pre) => (x >= 1 && x <= y@pre * 2)) &&
((!(1 < y@pre)) => ((x == 1) && (y == y@pre))) &&
(y == y@pre
      loop assigns x)
    */
    
    while (x < y) {
        x = x + x;
    }
  
    
  
  }