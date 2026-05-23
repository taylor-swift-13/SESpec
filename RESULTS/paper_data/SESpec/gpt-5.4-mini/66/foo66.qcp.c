#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo66(int y) 
/*@

Require emp
Ensure emp
*/{

    int x;

    x = 4 * y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == 4 * y) &&
    (y <= y@pre) &&
    (x % 4 == 0) &&
    ((4 * y@pre > 0) => (x == 4 * y)) &&
    ((4 * y@pre > 0) => (0 <= y)) &&
    ((4 * y@pre > 0) => (0 <= x)) &&
    ((!(4 * y@pre > 0)) => ((x == 4 * y@pre) && (y == y@pre)))
    */
    
    while (x > 0) {
       x -= 4;
       y--;
    }

  }