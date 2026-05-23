#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo325(int value);

int foo325(int value) 
/*@

Require emp
Ensure (value <= 0 && __return == 0)
*/
{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}