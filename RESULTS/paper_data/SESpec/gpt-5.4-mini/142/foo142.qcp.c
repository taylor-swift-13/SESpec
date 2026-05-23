#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo67_helper1_c142(int x);
int foo142(int x);

int foo142(int x) 
/*@

Require emp
Ensure (x % 2 != 0 && __return == 1) || (x % 2 == 0 && __return == 0)
*/
{

         	return x%2 != 0;
}