#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo352(int number);

int foo352(int number) 
/*@

Require emp
Ensure (exists total_68 ret_67 result_66, total_68 <= 0 && total_68 >= 0 && (number > 0 => total_68 >= 0 && total_68 <= number) && (!(number > 0) => total_68 == number && ret_67 == 0 && result_66 == 0 && number == number) && __return == (number ^ result_66))
*/
{

		int result = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (total >= 0) &&
    ((number@pre > 0) => (total >= 0 && total <= number@pre)) &&
    ((!(number@pre > 0)) => ((total == number@pre) && (ret == 0) && (result == 0) && (number == number@pre))) &&
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