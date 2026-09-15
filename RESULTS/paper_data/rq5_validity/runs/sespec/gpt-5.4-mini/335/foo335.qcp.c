#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (digit_prod : Z -> Z -> Z) */
int foo335(int a, int b) 
/*@

Require emp
Ensure Results(__return)
*/{

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
           
  /*@ Inv
    (a == a@pre) &&
    (b == b@pre) &&
    (i >= a@pre + 1) &&
    (variable == digit_prod(a@pre + 1, i - 1))
    */
for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}