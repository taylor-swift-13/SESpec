#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo172(int n);

int foo172(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int sum1 = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (sum1 == 0) &&
(n == n@pre
      loop assigns i, sum)
    */
    
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (n == n@pre
      loop assigns i, sum1)
    */
    
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }
        return sum - sum1;
}