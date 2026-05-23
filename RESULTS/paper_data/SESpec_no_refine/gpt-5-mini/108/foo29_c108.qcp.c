#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo29_c108(int n);

int foo29_c108(int n) 
/*@

Require emp
Ensure (n % 5 == 0 && n % 3 != 0 && __return == 0 + 5) || (n % 5 == 0 && n % 3 == 0 && __return == 0 + 3 + 5) || (n % 5 != 0 && n % 3 == 0 && __return == 0 + 3) || (n % 5 != 0 && n % 3 != 0 && __return == 0)
*/
{

        int res = 0;
        if (n % 3 == 0) {
            res += 3;
        }
        if (n % 5 == 0) {
            res += 5;
        }
        return res;
}