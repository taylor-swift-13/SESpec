#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo398(int number);

int foo398(int number) 
/*@

Require emp
Ensure (number <= 0 && __return >= 0 && number <= number@pre && __return + decimal_digits(number) == decimal_digits(number@pre))
*/
{

		int ret = 0;
	
 	/*@ Inv
    (ret >= 0) &&
    (number <= number@pre) &&
    (ret + decimal_digits(number) == decimal_digits(number@pre))
    */
while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}