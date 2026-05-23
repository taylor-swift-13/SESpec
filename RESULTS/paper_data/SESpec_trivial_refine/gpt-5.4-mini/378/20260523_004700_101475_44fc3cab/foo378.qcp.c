#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (odd_sum : Z -> Z -> Z) */

int foo378(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*0*/ 
 /*@ Inv
    (l <= i && i <= r + 1) &&
    (sum == \sum(integer k = l k < i (k % 2 != 0 ? k : 0)))
    */
for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}