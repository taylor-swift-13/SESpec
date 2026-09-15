#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo346(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*0*/ 
 /*@ Inv
    (max >= 0)
    */
for (int i = 2; i <= n; i++) {
           
  /*1*/ 
 while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}