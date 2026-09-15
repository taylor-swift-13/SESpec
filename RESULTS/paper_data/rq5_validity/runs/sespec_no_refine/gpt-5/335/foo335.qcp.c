#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo335(int a, int b);

int foo335(int a, int b) 
/*@

Require emp
Ensure Results(__return)
*/{

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
           
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (a == a@pre) &&
(b == b@pre) &&
(b@pre - a@pre < 5) &&
(a@pre != b@pre) &&
(b == b@pre) &&
(a == a@pre
          loop assigns i, variable)
    */
    
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}