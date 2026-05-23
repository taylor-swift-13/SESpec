#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo172_c334(int n);

int foo172_c334(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int sum1 = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}