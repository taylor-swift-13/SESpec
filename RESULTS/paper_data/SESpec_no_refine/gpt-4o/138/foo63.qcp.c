#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo63(int a, int b, int factor);

int foo63(int a, int b, int factor) 
/*@

Require emp
Ensure (b % factor == 0 && a % factor == 0 && __return == 0) || (b % factor != 0 && a % factor == 0 && __return == 1) || (a % factor != 0 && __return == 1)
*/
{

        if(a % factor != 0) {
            return 1;
        }
        if(b % factor != 0) {
            return 1;
        }
        return 0;
}