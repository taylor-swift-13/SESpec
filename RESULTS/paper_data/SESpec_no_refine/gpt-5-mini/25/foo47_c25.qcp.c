#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <assert.h>

typedef enum { VAL5 = 5 } enum1;

void foo47_c25(const char **args, int args_len);

void foo47_c25(const char **args, int args_len) 
/*@
With args_v
Require **(args) == args_v
Ensure emp
*/{
    enum1 e = VAL5;
    assert(e == VAL5);
}