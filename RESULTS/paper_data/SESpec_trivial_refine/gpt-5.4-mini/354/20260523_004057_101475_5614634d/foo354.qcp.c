#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo354(int num);

int foo354(int num) 
/*@

Require emp
Ensure (exists even_65 sum_64, sum_64 <= 0 && even_65 >= 0 && (sum_64 > 0 => sum_64 <= num) && __return == (num | 0))
*/
{

		int even = 0;
		int result = 0;
		int sum = num;
	
 	/*@ Inv
    (even >= 0) &&
    (sum > 0 => sum <= num)
    */
while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
		return (num | result);
}