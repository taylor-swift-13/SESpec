#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo30();

int foo30() 
/*@

Require emp

Ensure Results(__return)
*/{

    int *i = (int *)malloc(sizeof(int) * (10));
int i_len = 10;
    return i[3] == 0;
}