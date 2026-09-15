#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo270(int n, int r, int p);

int foo270(int n, int r, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n < r) {
            return 0;
        }

        int ncr = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (p == p@pre) &&
(r == r@pre) &&
(n == n@pre
      loop assigns i, ncr)
    */
    
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

        return ncr % p;
}