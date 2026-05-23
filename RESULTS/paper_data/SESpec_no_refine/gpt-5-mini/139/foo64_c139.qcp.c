#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo64_c139(int a, int b, int m);

int foo64_c139(int a, int b, int m) 
/*@

Require emp
Ensure (m % a != 0 && __return == 1) || (m % b != 0 && m % a == 0 && __return == 1) || (m % b == 0 && m % a == 0 && __return == 0)
*/
{

        return m % a != 0 || m % b != 0;
}