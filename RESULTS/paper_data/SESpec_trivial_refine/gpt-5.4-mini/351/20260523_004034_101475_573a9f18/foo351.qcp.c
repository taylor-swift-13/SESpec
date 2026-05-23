#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo351(int number);

int foo351(int number) 
/*@

Require emp
Ensure (exists ret_65 total_64, total_64 <= 0 && ret_65 >= 0 && total_64 == number >> ret_65 && __return == (number ^ 0))
*/
{

		int i = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (ret >= 0) &&
    (total == (number >> ret))
    */
while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}