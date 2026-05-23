#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo381(int x, int y);

int foo381(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y == y@pre) &&
(x == x@pre
          loop assigns i, count)
    */
    
            for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
}