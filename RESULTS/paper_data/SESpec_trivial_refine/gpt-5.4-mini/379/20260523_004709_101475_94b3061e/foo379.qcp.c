#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (even_sum : Z -> Z -> Z) */
int foo379(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (l <= i) &&
    (sum == even_sum(l, i))
    */
for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}