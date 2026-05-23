#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo82(int z,int k)
/*@

Require emp
Ensure emp
*/{

    int x=1;
    int y=1;
    int c=1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < k@pre) => (c >= 1)) &&
((!(1 < k@pre)) => ((c == 1) && (y == 1) && (x == 1) && (k == k@pre) && (z == z@pre))) &&
(k == k@pre) &&
(z == z@pre
      loop assigns c, x, y)
    */
    
    while (c < k) {
        c = c + 1;
        x = x * z + 1;
        y = y * z;
    }

  }