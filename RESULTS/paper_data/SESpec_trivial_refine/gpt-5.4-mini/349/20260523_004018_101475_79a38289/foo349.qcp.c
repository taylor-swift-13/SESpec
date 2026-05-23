#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo349(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*0*/ 
 /*@ Inv
    (sum >= 0) &&
    (i >= 1) &&
    (n < 1 || i <= n + 1)
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
}