#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo117(int a, int b, int m);

int foo117(int a, int b, int m) 
/*@

Require emp
Ensure (m % b == 0 && m % a == 0 && __return == 1) || (m % b != 0 && m % a == 0 && __return == 0) || (m % a != 0 && __return == 0)
*/
{

        return m % a == 0 && m % b == 0;
}