#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo52_c129(int year);

int foo52_c129(int year) 
/*@

Require emp
Ensure (year % 400 == 0 && year % 100 == 0 && year % 4 == 0 && __return == 1) || (year % 400 != 0 && year % 100 == 0 && year % 4 == 0 && __return == 0) || (year % 100 != 0 && year % 4 == 0 && __return == 1) || (year % 4 != 0 && __return == 0)
*/
{

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}