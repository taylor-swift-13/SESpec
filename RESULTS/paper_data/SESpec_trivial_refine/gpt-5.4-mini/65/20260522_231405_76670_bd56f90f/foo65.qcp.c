#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo65(int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int i;

    n = 0;
    i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (n >= 0) &&
    (i >= 0) &&
    (2 * n == i || 2 * n == i + 1)
    */
    
    while (i < 2 * k) {
        if (i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }

  }