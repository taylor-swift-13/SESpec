#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

double foo18(double celsius);

double foo18(double celsius) 
/*@

Require emp
Ensure Results(__return)
*/{

        return celsius * 1.80 + 32.00;
}