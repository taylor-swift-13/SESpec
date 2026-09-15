#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo191_c340(int n, int z);

int foo191_c340(int n, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= loop && loop <= z + 1) &&
(0 <= result) &&
((loop <= z@pre) => (result == divisors_count(n, loop-1) && z == z@pre && n == n@pre)) &&
(n == n@pre
          loop assigns loop, result)
    */
    
            for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}