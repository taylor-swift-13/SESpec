#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo354(int num);

int foo354(int num) 
/*@

Require emp
Ensure (exists sum_66 even_65 result_64, sum_66 <= 0 && sum_66 >= 0 && even_65 >= 0 && sum_66 == num >> even_65 && (!(num > 0) => sum_66 == num && result_64 == 0 && even_65 == 0 && num == num) && sum_66 == num >> even_65 && __return == (num | result_64))
*/
{

		int even = 0;
		int result = 0;
		int sum = num;
	
 	/*@ Inv
    (sum >= 0) &&
    (even >= 0) &&
    (sum == num@pre >> even) &&
    ((!(num@pre > 0)) => ((sum == num@pre) && (result == 0) && (even == 0) && (num == num@pre))) &&
    (sum == num@pre >> even) &&
    (num == num@pre)
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