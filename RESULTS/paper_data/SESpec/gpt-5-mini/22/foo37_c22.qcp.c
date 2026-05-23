#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo37_c22(int size);

int foo37_c22(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (size < 0) return -1;
    int *int_array = (int *)malloc(sizeof(int) * (size));
int int_array_len = size;

    if(int_array_len != size)
      return 0;
    return 1;
}