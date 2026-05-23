#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo118(int a, int b, int m);

int foo118(int a, int b, int m) 
/*@

Require emp
Ensure (m % b == 0 && m % a == 0 && __return == 1) || (m % b != 0 && m % a == 0 && __return == 0) || (m % a != 0 && __return == 0)
*/
{

        if(m % a != 0) {
            return 0;
        }
        if(m % b != 0) {
            return 0;
        }
        return 1;
}