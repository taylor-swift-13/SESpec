#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo398(int number);

int foo398(int number) 
/*@

Require emp
Ensure (number <= 0 && __return >= 0 && number >= 0 && number <= number@pre && power(10, __return) >= 1 && number * power(10, __return) <= number@pre && number@pre < (number + 1) * power(10, __return) && (number == 0 => number@pre < power(10, __return)) && (number@pre == 0 => __return == 0))
*/
{

		int ret = 0;
	
 	/*@ Inv
    (ret >= 0) &&
    (number >= 0) &&
    (number <= number@pre) &&
    (power(10, ret) >= 1) &&
    (number * power(10, ret) <= number@pre) &&
    (number@pre < (number + 1) * power(10, ret)) &&
    ((number == 0) => (number@pre < power(10, ret))) &&
    ((number@pre == 0) => (ret == 0))
    */
while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}