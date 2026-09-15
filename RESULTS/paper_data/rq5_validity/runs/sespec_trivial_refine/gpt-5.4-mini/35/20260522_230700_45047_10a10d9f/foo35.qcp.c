#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo35(int input);

int foo35(int input) 
/*@

Require emp
Ensure Results(__return)
*/{
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}