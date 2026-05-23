#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)

/*@
With out_l A_l B_l
Require store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100
Ensure emp
*/{
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            int s = 0;
            for (int k = 0; k < ca_rb; k++) {
                s = s + A[i * ca_rb + k] * B[k * cb + j];
            }
            out[i * cb + j] = s;
        }
    }
    return;
}