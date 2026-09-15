#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max2 : Z -> Z -> Z) */
int foo315(int s) 
/*@

Require emp
Ensure Results(__return)
*/{

        int foo315 = 0;

       
  /*@ Inv
    (l >= 1) &&
    (foo315 >= 0)
    */
for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant b >= 1;
          loop invariant foo315 >= 0;
          loop assigns b, foo315;
            */
            /*@ Inv
    (b >= 1) &&
    (foo315 >= 0)
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