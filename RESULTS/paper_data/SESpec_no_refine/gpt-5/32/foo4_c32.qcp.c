#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo4_c32(double i);

int foo4_c32(double i) 
/*@

Require emp
Ensure Results(__return)
*/{
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}