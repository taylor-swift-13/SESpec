#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo78(int a);

int foo78(int a) 
/*@

Require emp
Ensure (2 > a / 2 && __return == 1) || (a % 2 == 0 && 2 <= a / 2 && __return == 0)
*/
{

		int i = 2;
		int mid = a/2;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}