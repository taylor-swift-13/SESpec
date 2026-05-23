#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo33(int denom);

int foo33(int denom) 
/*@

Require emp
Ensure (denom != 0 && __return == 1) || (denom == 0 && __return == 0)
*/
{
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}