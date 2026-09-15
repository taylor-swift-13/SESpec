#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo62_helper1_c13();
int foo13(int depth);

int foo13(int depth) 
{

    if (depth < 10) return foo13(depth + 1) + 1;
    else return 0;
}

int foo13(int depth) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (depth < 10) return foo13(depth + 1) + 1;
    else return 0;
}