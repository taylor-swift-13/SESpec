#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo27_c5(int n);

int foo27_c5(int n) 
{

    if (n > 100) return n - 10;
    else return foo27_c5(foo27_c5(n + 11));
}

int foo27_c5(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (n > 100) return n - 10;
    else return foo27_c5(foo27_c5(n + 11));
}