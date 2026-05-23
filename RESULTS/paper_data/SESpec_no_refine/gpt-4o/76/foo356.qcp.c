#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo356(int y) 
/*@

Require emp
Ensure emp
*/{
    int c = 0;
    int z = 36 * y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c && c <= 36) &&
(z == 36 * y + c) &&
(y == y@pre
      loop assigns z, c)
    */
    
    while (unknown()) {
        if (c < 36) {
            z = z + 1;
            c = c + 1;
        }
    }

  }