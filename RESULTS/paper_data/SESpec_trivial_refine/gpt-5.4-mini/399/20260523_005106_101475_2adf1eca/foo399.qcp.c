#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo399(int value);

int foo399(int value) 
/*@

Require emp
Ensure (value <= 0 && __return >= 0 && value >= 0)
*/
{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    (result >= 0) &&
    (value >= 0)
    */
while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}