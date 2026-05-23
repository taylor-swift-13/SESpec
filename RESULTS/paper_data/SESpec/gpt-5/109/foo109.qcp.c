#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo109(int n);

int foo109(int n) 
/*@

Require emp
Ensure (n % 5 == 0 && n % 3 != 0 && __return == 0 + 0 + 5) || (n % 5 != 0 && n % 3 != 0 && __return == 0 + 0 + 0) || (n % 5 == 0 && n % 3 == 0 && __return == 0 + 3 + 5) || (n % 5 != 0 && n % 3 == 0 && __return == 0 + 3 + 0)
*/
{

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}