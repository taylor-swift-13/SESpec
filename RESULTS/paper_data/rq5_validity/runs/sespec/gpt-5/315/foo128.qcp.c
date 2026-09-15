#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo128(int s);

int foo128(int s) 
/*@

Require emp
Ensure Results(__return)
*/{

        int foo128 = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (s == s@pre) &&
(foo128 >= 0
          loop assigns l, foo128)
    */
    
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= s + 1 ==> \true;
          loop invariant foo128 >= 0;
          loop invariant s == \at(s,Pre);
          loop invariant 1 <= b <= s - l + 2;
          loop assigns foo128, b;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo128) {
                    foo128 = volume;
                }
            }
            
        }
        return foo128;
}