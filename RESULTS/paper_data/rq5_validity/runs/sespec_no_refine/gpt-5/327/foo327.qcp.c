#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo327(int n);

int foo327(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int fact = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= i) &&
(n == n@pre) &&
(fact == prod2(i)) &&
(n == n@pre
      loop assigns i, fact)
    */
    
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
        int foo327 = 0;
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (foo327 >= 0 && foo327 <= 9
      loop assigns foo327, fact)
    */
    
    while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }
        return foo327;
}