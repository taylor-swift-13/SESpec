#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo55(unsigned int y) 
/*@

Require emp
Ensure emp
*/{

    unsigned int x;

    x = 2;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= 2) &&
    (y == y@pre) &&
    ((x >= 2 && y >= 2) => (x <= y || x > y)) &&
    ((x < y) => (x >= 2 && y >= 2)) &&
    ((x < y && x < y / x) => (x * x <= y)) &&
    ((x >= y) => (x >= 2 && y == y@pre)) &&
    ((2 < y@pre) => (x >= 2)) &&
    ((!(2 < y@pre)) => ((x == 2)&&(y == y@pre)))
    */
    
    while (x < y) {
      if (x < y / x) {
        x *= x;
      } else {
        x++;
      }
    }

  }