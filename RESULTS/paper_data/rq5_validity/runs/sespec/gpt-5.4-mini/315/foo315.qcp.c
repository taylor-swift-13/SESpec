#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (vol : Z -> Z -> Z -> Z) */
int foo315(int s) 
/*@

Require emp
Ensure Results(__return)
*/{

        int foo315 = 0;

       
  /*@ Inv
    (l >= 1) &&
    (s == s@pre) &&
    (foo315 >= 0)
    */
for (int l = 1; l <= s; l++) {

            /*@ 
              loop invariant 1 <= b <= s - l + 2;
              loop invariant foo315 >= 0;
              loop invariant s == \at(s,Pre);
              loop assigns b, foo315;
            */
            /*@ Inv
    (1 <= b && b <= s - l + 2) &&
    (foo315 >= 0) &&
    (s == s@pre)
    */
for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo315) {
                    foo315 = volume;
                }
            }
            
        }
        return foo315;
}