#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo382(int n, int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (max == 0 || (max % x == y && max <= i - 1)) &&
    (forall (k:Z), 1 <= k && k < i => (k % x == y => max >= k)) &&
    (y == y@pre) &&
    (x == x@pre) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }
        return max;
}