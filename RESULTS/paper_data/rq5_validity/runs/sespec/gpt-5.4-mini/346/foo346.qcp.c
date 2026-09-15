#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo346(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Inv
    (2 <= i) &&
    (max == 0 || max >= 2) &&
    (max <= i)
    */
for (int i = 2; i <= n; i++) {
            
            
        /*@
          loop invariant i >= 2;
          loop invariant max == 0 || max >= 2;
          loop invariant max <= i;
          loop assigns max, n;
        */
            /*@ Inv
    (i >= 2) &&
    (max == 0 || max >= 2) &&
    (max <= i)
    */
while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
        return max;
}