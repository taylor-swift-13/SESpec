#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo10(int n);

int foo10(int n) 
/*@

Require emp
Ensure (n % 4 != 0 && __return == 1) || (n % 4 == 0 && __return == 0)
*/
{

        return n % 4 != 0;
}