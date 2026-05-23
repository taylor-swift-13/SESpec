#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo128_c315(int s);

int foo128_c315(int s) 
/*@

Require emp
Ensure Results(__return)
*/{

        int foo128_c315 = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int l = 1; l <= s; l++) {
           
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo128_c315) {
                    foo128_c315 = volume;
                }
            }
        }
        return foo128_c315;
}