#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo39_c116(int a, int b, int factor);

int foo39_c116(int a, int b, int factor) 
/*@

Require emp
Ensure (b % factor == 0 && a % factor == 0 && __return == 1) || (b % factor != 0 && a % factor == 0 && __return == 0) || (a % factor != 0 && __return == 0)
*/
{

        if (a % factor != 0) {
            return 0;
        }
        if (b % factor != 0) {
            return 0;
        }
        return 1;
}