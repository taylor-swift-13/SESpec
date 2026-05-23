#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo346(int n);

int foo346(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= i) &&
(max >= 0
          loop assigns i, max, n)
    */
    
            for (int i = 2; i <= n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= i;
              loop invariant max >= 0;
              loop invariant n >= 0;
              loop assigns i, max, n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
        return max;
}