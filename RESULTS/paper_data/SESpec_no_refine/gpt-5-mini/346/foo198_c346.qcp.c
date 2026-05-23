#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo198_c346(int n);

int foo198_c346(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 2; i <= n; i++) {
           
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}