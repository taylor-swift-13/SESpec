#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo276_c66(int y) 
/*@

Require emp
Ensure emp
*/{

    int x;

    x = 4 * y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((4 * y@pre > 0) => (x == 4 * y)) &&
((4 * y@pre > 0) => (y <= y@pre)) &&
((4 * y@pre > 0) => (x >= 0)) &&
((!(4 * y@pre > 0)) => ((x == 4 * y@pre)&&(y == y@pre))
      loop assigns x, y)
    */
    
    while (x > 0) {
       x -= 4;
       y--;
    }

  }