#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prod : Z -> Z -> Z) */
int foo384(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (k > n - k)
            k = n - k;
        int c = 1;
       
  /*@ Inv
    (1 <= i && i <= k + 1) &&
    (0 <= c) &&
    (0 <= k) &&
    (2 * k <= n) &&
    (k == k@pre || k == n - k@pre) &&
    (n == n@pre) &&
    (c == prod(n, i - 1)) &&
    (forall (j:Z), 1 <= j && j < i => (n - j + 1) >= 0) &&
    ((i > k) => (c == prod(n, k)))
    */
for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}