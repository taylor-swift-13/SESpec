#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void q_normalize(int *q)

/*@
With q_v
Require *(q) == q_v
Ensure emp
*/{
    (void)q;
    return;
}