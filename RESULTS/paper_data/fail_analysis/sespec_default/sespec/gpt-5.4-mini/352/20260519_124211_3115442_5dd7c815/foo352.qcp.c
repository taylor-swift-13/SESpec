#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo352(int number);

int foo352(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= ret) &&
(number == number@pre) &&
(total == number@pre >> ret
          loop assigns result, total, ret)
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