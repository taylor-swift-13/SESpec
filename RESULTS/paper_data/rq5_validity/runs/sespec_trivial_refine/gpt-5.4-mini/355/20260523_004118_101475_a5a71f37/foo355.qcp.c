#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo355(int num);

int foo355(int num) 
/*@

Require emp
Ensure (exists result_65 sum_64, sum_64 <= 0 && 0 <= result_65 && (sum_64 > 0 => sum_64 == num >> result_65) && __return == (num | 0))
*/
{

		int result = 0;
		int end = 0;
		int sum = num;
	
 	/*@ Inv
    (0 <= result) &&
    (sum > 0 => sum == (num >> result))
    */
while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
}