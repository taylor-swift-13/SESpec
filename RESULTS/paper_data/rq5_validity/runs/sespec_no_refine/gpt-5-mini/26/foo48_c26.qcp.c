#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <assert.h>

void foo48_c26(const char **args, int args_len);

void foo48_c26(const char **args, int args_len) 
/*@
With args_v
Require **(args) == args_v
Ensure emp
*/{
    float f = 2.5f;
    assert(f == 2.5f);
    assert(f < 3.0f);
    assert(f > 2.0f);
    double d = 2.5;
    assert(d == 2.5);
    assert(d < 3.0);
    assert(d > 2.0);
}