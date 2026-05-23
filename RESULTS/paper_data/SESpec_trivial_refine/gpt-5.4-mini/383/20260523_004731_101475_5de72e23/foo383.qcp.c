#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo383(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*0*/ 
 /*@ Inv
    (i >= 1) &&
    (0 <= count && count <= i - 1)
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}