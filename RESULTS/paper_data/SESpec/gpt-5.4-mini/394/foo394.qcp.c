#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact : Z -> Z) */
int foo394(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Inv
    (1 <= loop && loop <= num + 1) &&
    (ret == fact(loop - 1))
    */
for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
}