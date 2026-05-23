#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo347(int x, int y);

int foo347(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (y < 0) {
            y = -y;
        }
        int count = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= i && i <= y + 1) &&
(y == abs_pre_y(y@pre)) &&
(x == x@pre) &&
(0 <= count && count <= i - 1
      loop assigns i, count)
    */
    
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }
        return count;
}