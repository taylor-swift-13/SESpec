#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo54_helper1_c28(const char **args, int args_len);
void foo28(const char **args, int args_len);

int foo54_helper1_c28(const char **args, int args_len) /*@
With args_v
Require **(args) == args_v
Ensure (args != 0 && __return == 1 && **args == args_v) || (args == 0 && __return == 0 && **args == args_v)
*/
{
    return args != 0;
}

void foo28(const char **args, int args_len) 
/*@
With args_v
Require **(args) == args_v
Ensure (exists retval_75, args == 0 && retval_75 == 0 && **args == args_v) || (exists retval_77, args != 0 && retval_77 == 1 && **args == args_v)
*/
{
    foo54_helper1_c28(args, args_len);
}