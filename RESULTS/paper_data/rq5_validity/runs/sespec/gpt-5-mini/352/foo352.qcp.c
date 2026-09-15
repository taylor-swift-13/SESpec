#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (BIT_SET : Z -> Z -> Prop) */
int foo352(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (0 <= ret) &&
    (total == number@pre >> ret) &&
    ((number@pre >= 0) => total >= 0) &&
    ((!(number@pre > 0)) => ((total == number@pre) && (ret == 0) && (result == 0) && (number == number@pre)))
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