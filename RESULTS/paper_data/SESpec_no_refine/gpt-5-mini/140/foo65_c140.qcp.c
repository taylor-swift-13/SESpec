#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo65_c140(int n);

int foo65_c140(int n) 
/*@

Require emp
Ensure (n % 2 != 0 && n != 1 && __return == n) || (n % 2 == 0 && n != 1 && __return == n / 2) || (n == 1 && __return == 0)
*/
{

        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
}