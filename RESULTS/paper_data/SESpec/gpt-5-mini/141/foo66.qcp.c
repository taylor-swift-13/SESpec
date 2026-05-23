#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo66(int n);

int foo66(int n) 
/*@

Require emp
Ensure (n == 1 && __return == 0) || (n % 2 == 0 && n != 1 && __return == n / 2) || (n % 2 != 0 && n != 1 && __return == n)
*/
{

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}