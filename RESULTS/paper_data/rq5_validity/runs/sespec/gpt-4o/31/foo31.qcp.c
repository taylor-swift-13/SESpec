#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo31(int i);

int foo31(int i) 
/*@

Require emp
Ensure (i != 0 && __return == 1) || (i == 0 && __return == 0)
*/
{
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}