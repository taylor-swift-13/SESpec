#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stddef.h>

int data;
int foo57_helper1_c37();
int foo57_c37();

int foo57_helper1_c37() /*@

Require emp

Ensure Results(__return)
*/
{
    return &data != NULL;
}

int foo57_c37() 
/*@

Require emp

Ensure Results(__return)
*/{
    return foo57_helper1_c37();
}