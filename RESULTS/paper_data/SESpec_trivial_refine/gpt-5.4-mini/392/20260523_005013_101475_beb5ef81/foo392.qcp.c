#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact : Z -> Z) */
int foo392(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Inv
    (number >= 1) &&
    (ret == fact(number - 1))
    */
for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}