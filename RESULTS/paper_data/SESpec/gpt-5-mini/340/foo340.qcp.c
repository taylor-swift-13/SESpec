#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo340(int n, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Inv
    (1 <= loop && loop <= z + 1) &&
    (0 <= result && result <= z) &&
    (result <= loop - 1) &&
    (forall (k:Z), 1 <= k && k < loop => (0 <= k && k <= z)) &&
    (forall (k:Z), 1 <= k && k < loop => (n % k == 0 => 1 <= result)) &&
    (z == (z@pre >= 0 ? z@pre : -z@pre)) &&
    (n == n@pre)
    */
for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}