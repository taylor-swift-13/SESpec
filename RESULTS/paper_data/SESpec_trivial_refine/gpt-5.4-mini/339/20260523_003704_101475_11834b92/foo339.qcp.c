#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (count_divisors : Z -> Z) */

int foo339(int num, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    (0 <= index && index <= z + 1) &&
    (0 <= result && result <= index - 1) &&
    (result == \numof integer k 1 <= k && k < index && num % k == 0)
    */
for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
}