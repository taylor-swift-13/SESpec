#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo168() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x // x is non-negative and incremented in all branches) &&
(z == 10 * w // z is always 10 times w) &&
(w >= 0 // w is non-negative and incremented in every iteration
      loop assigns x, y, w, z)
    */
    
    while (unknown()) {
        if (x >= 4) {
            x = x + 1;
            y = y + 2;
        } else if (y > 10 * w && z >= 100 * x) {
            y = 0 - y;
        } else {
            x = x + 1;
            y = y + 100;
        }
        w = w + 1;
        z = z + 10;
    }

  }