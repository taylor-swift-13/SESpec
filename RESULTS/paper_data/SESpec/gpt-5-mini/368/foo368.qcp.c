#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (partial_ncr : Z -> Z -> Z) */
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
    (1 <= i && i <= r + 1) &&
    (0 <= r) &&
    (partial_ncr(n, i-1) == ncr) &&
    (ncr >= 0) &&
    ((forall (k:Z), 1 <= k && k <= i-1 => partial_ncr(n, k) * 1 == partial_ncr(n, k))) &&
    (p == p@pre) &&
    (r == r@pre) &&
    (n == n@pre)
    */
for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}