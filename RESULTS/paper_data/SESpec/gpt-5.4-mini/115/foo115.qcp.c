#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo115(int a, int b, int factor);

int foo115(int a, int b, int factor) 
/*@

Require emp
Ensure (b % factor == 0 && a % factor == 0 && __return == 1) || (b % factor != 0 && a % factor == 0 && __return == 0) || (a % factor != 0 && __return == 0)
*/
{

        return a % factor == 0 && b % factor == 0;
}