#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo173(int n);

const char * foo173(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= i && i <= n + 1) &&
(count == count_divisors(n, i - 1)) &&
(n == n@pre
      loop assigns i, count)
    */
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}