#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo353(int num);

int foo353(int num) 
/*@

Require emp
Ensure (exists result_62 sum_61, sum_61 <= 0 && 0 <= result_62 && 0 <= sum_61 && sum_61 <= num && sum_61 == num >> result_62 && __return == (num | 0))
*/
{

		int result = 0;
		int max = 0;
		int sum = num;
	
 	/*@ Inv
    (0 <= result) &&
    (0 <= sum) &&
    (sum <= num@pre) &&
    (sum == (num@pre >> result)) &&
    (num == num@pre)
    */
while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | max);
}