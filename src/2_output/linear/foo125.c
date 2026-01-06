
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo125(int x, int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i = x;
    int j = y;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre != 0) => (x == x@pre - (x@pre - x))) &&
((x@pre != 0) => (y == y@pre - (x@pre - x))) &&
((!(x@pre != 0)) => ((j == y@pre)&&(i == x@pre)&&(y == y@pre)&&(x == x@pre))) &&
(j == y@pre) &&
(i == x@pre
      loop assigns x, y)
    */
    
    while (x != 0) {
        x = x - 1;
        y = y - 1;
    }
  
    
  
  }