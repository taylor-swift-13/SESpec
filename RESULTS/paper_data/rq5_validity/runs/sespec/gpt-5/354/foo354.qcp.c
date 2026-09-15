#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo354(int num);

int foo354(int num) 
/*@

Require emp
Ensure (exists even_62 sum_61, sum_61 <= 0 && 0 <= even_62 && sum_61 == num >> even_62 && __return == (num | 0))
*/
{

		int even = 0;
		int result = 0;
		int sum = num;
	
 	/*@ Inv
    (num == num@pre) &&
    (0 <= even) &&
    (sum == (num@pre >> even))
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