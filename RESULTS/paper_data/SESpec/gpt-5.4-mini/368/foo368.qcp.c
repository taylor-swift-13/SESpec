#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (binom : Z -> Z -> Z) */
int foo368(int n, int r, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n < r) {
            return 0;
        }

        int ncr = 1;
       
  /*@ Inv
    (i >= 1) &&
    (ncr >= 0) &&
    (p == p@pre) &&
    (r == r@pre) &&
    (n == n@pre)
    */
for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}