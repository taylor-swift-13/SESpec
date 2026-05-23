#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo323(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        if (n == 1) return 1;
       
  /*0*/ 
 /*@ Inv
    (count >= 0) &&
    (i >= 2) &&
    (count <= i - 2)
    */
for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}