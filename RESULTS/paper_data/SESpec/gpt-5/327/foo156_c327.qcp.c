#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo156_c327(int n);

int foo156_c327(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int fact = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (n == n@pre) &&
(2 <= i => 1 <= i - 1
          loop assigns i, fact)
    */
    
            for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo156_c327 = 0;
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (fact >= 0) &&
(foo156_c327 >= 0
          loop assigns foo156_c327, fact)
    */
    
            while (fact > 0) {
            foo156_c327 = fact % 10;
            fact /= 10;
        }
        return foo156_c327;
}