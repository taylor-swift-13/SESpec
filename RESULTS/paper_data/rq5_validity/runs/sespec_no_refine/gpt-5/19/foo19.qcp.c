#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo19(const char * s1);

int foo19(const char * s1) 
/*@
With s1_v
Require *(s1) == s1_v
Ensure Results(__return)
*/{

    return ((int)strlen(s1)) == 24;
}