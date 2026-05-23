#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo352(int number);

int foo352(int number) 
/*@

Require emp
Ensure (exists ret_62 total_61, total_61 <= 0 && 0 <= ret_62 && total_61 == number >> ret_62 && __return == (number ^ 0))
*/
{

		int result = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (0 <= ret) &&
    (total == (number@pre >> ret)) &&
    (number == number@pre)
    */
while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
}