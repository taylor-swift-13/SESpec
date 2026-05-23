#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo54_helper1_c28(const char **args, int args_len);
void foo54_c28(const char **args, int args_len);

int foo54_helper1_c28(const char **args, int args_len) /*@
With args_v
Require **(args) == args_v
Ensure Results(__return)
*/
{
    return args != 0;
}

void foo54_c28(const char **args, int args_len) 
/*@
With args_v
Require **(args) == args_v
Ensure emp
*/{
    foo54_helper1_c28(args, args_len);
}