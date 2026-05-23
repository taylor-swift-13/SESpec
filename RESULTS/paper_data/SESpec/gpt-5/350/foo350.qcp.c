#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo350(int num);

int foo350(int num) 
/*@

Require emp
Ensure (exists ret_62 result_61, num <= 0 && 0 <= ret_62 && 0 <= ret_62 && result_61 == (result_61 | 0) && __return == (num ^ result_61))
*/
{

		int result = 0;
		int ret = 0;
		int total = num;
	
 	/*@ Inv
    (0 <= ret) &&
    (num == num@pre) &&
    (0 <= ret) &&
    (result == (result | 0))
    */
while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }
		return num ^ result;
}