#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo398(int number);

int foo398(int number) 
/*@

Require emp
Ensure (number <= 0 && __return == 0)
*/
{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}