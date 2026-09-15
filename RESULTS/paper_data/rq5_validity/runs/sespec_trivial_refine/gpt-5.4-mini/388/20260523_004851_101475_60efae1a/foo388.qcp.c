#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo388(int num, int c, int r);

int foo388(int num, int c, int r) 
/*@

Require emp
Ensure (r <= 0 && __return == 0)
*/
{

		int result = 0;
	
 	/*@ Inv
    emp
    */
while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}