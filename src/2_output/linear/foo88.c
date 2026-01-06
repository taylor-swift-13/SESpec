
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


int foo88(int x) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int lock = 1;
    int y = x + 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre != y) => (y >= x@pre + 1)) &&
((!(x@pre != y)) => ((y == x@pre + 1) && (lock == 1) && (x == x@pre))) &&
(x != y => (lock == 0 || x == y || (lock == 1 && x == x@pre))) &&
(lock == 1 || x != y
      loop assigns lock, x, y)
    */
    
    while (x != y) {
        if (unknown()) {
            lock = 1;
            x = y;
        } else {
            lock = 0;
            x = y;
            y = y + 1;
        }
    }
    
  }