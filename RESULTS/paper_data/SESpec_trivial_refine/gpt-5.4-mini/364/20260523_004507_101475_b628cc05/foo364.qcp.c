#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo364(int n);

int foo364(int n) 
/*@

Require emp
Ensure (n / 400 == 0 && n / 100 == 0 && __return == (n - n / 4 + n / 4 * 2) % 7) || (n / 400 == 0 && n / 100 != 0 && __return == (n - n / 4 + n / 100 + (n / 4 - n / 100) * 2) % 7) || (n / 400 != 0 && n / 100 == 0 && __return == (n - n / 4 - n / 400 + (n / 4 + n / 400) * 2) % 7) || (n / 400 != 0 && n / 100 != 0 && __return == (n - n / 4 + n / 100 - n / 400 + (n / 4 - n / 100 + n / 400) * 2) % 7)
*/
{

        int hund1 = n / 100;
        int hund4 = n / 400;
        int leap = n / 4;
        int ordd = n - leap ;
        if (hund1 != 0) {
            ordd += hund1 ;
            leap -= hund1 ;
        }
        if (hund4 != 0) {
            ordd -= hund4 ;
            leap += hund4 ;
        }
        int days = ordd + leap * 2;
        return days % 7;
}