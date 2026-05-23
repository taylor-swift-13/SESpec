#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (oddsum : Z -> Z -> Z) */
int foo378(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (l <= i) &&
    ((l <= r + 1) => (i <= r + 1)) &&
    (!(l <= r + 1) => (i == l)) &&
    (sum + oddsum(i, r) == oddsum(l, r))
    */
for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}