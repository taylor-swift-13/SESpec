#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo355(int num);

int foo355(int num) 
/*@

Require emp
Ensure (exists result_67 sum_66 end_65, sum_66 <= 0 && result_67 >= 0 && sum_66 == num >> result_67 && (!(num > 0) => sum_66 == num && end_65 == 0 && result_67 == 0 && num == num) && __return == (num | end_65))
*/
{

		int result = 0;
		int end = 0;
		int sum = num;
	
 	/*@ Inv
    (result >= 0) &&
    (num == num@pre) &&
    (sum == num@pre >> result) &&
    ((!(num@pre > 0)) => ((sum == num@pre) && (end == 0) && (result == 0) && (num == num@pre)))
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