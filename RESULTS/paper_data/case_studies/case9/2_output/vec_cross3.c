#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void vec_cross3(int *out, int *a, int *b)

/*@
With out_l a_l b_l
Require store_int_ptr(out) && store_int_ptr(a) && store_int_ptr(b)
Ensure emp
*/{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
    return;
}