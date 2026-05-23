#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void vec_scale(int *out, int *A, int k, int n)

/*@
With out_l A_l
Require store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100
Ensure emp
*/{
   
  /*@ Inv
    exists  out_l A_l,    
    store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100 &&
    (0 <= i && i <= n) &&
    (n == n@pre) &&
    (k == k@pre) &&
    (true)) &&
    (true)) &&
    (forall (j:Z), i <= j && j < n => out_l[j] == out_l[j]@pre)
    */
for (int i = 0; i < n; i++) {
        out[i] = A[i] * k;
    }
    return;
}