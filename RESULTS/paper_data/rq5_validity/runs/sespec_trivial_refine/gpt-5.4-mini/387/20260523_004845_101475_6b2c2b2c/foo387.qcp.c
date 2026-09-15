#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo387(int num, int c, int r);

int foo387(int num, int c, int r) 
/*@

Require emp
Ensure (r <= 0 && r >= 0 && c != 0 && __return == 0)
*/
{

		int ret = 0;
	
 	/*@ Inv
    (r >= 0) &&
    (c != 0)
    */
while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
}