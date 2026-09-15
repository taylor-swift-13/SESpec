#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo367(int n);

int foo367(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 2;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= i) &&
(n == n@pre
      loop assigns i)
    */
    
    while (i <= n / i) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }
        return n;
}