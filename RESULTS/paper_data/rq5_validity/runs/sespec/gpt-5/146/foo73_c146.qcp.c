#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo73_c146(int n);

int foo73_c146(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if(n <= 0) {
            return 0;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (n > 0
      loop assigns n)
    */
    
    while (n % 4 == 0) {
        n /= 4;
    }
        return n == 1;
}