#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void vec_add(int *out, int *A, int *B, int n)

/*@
With out_l A_l B_l
Require store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100 && store_int_array(B, n, B_l) && n > 0 && n < 100
Ensure emp
*/{
    for (int i = 0; i < n; i++) {
        out[i] = A[i] + B[i];
    }
    return;
}