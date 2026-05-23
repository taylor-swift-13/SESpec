#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int limit_abs(int x, int lim)

/*@

Require emp
Ensure Results(__return)
*/{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}