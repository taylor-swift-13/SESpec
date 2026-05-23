#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo386(int num, int b, int r);

int foo386(int num, int b, int r) 
/*@

Require emp
Ensure (r <= 0 && r >= 0 && num >= 0 && __return >= 0)
*/
{

		int result = 0;
	
 	/*@ Inv
    (r >= 0) &&
    (num >= 0) &&
    (result >= 0) &&
    (b == b@pre)
    */
while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / b;
        num %= b;
    }
		return result;
}