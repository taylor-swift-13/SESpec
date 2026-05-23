#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo288(int l, int r);

int foo288(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (r == r@pre) &&
(l == l@pre
          loop assigns i, sum)
    */
    
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}