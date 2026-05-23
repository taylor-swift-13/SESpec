#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo51(int year);

int foo51(int year) 
/*@

Require emp
Ensure (year % 400 == 0 && year % 100 == 0 && year % 4 == 0 && __return == 1) || (year % 400 != 0 && year % 100 == 0 && year % 4 == 0 && __return == 0) || (year % 100 != 0 && year % 4 == 0 && __return == 1) || (year % 4 != 0 && __return == 0)
*/
{

        int leap = 0;

        if (year % 4 == 0)
        {
            if ( year % 100 == 0)
            {
                if ( year % 400 == 0)
                    leap = 1;
                else
                    leap = 0;
            }
            else
                leap = 1;
        }
        else
            leap = 0;

	return leap;
}