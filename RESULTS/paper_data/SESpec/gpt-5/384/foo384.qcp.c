#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo384(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (k > n - k)
            k = n - k;
        int c = 1;
       
  /*@ Inv
    (1 <= i) &&
    (n == n@pre) &&
    (i == 1 => c == 1) &&
    (forall (t:Z), 1 <= t && t < i => 1 <= t && t <= k) &&
    (forall (t:Z), 1 <= t && t < i => n - t + 1 >= n - k + 1)
    */
for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }
        return c;
}