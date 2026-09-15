#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo14(int unknown);

int foo14(int unknown) 
/*@

Require emp
Ensure Results(__return)
*/{
    int arr_len = unknown > 0 ? 1 : 0;
    int *arr = arr_len ? (int *)malloc(sizeof(int) * arr_len) : 0;
    if (unknown > 0) arr[0] = 1;
    if (unknown > 0) return arr_len == 1 && arr[0] == 1;
    return arr_len == 0;
}