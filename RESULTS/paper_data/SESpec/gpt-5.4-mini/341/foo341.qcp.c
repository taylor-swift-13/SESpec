#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcount : Z -> Z -> Z) */
int foo341(int num, int z) 
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
    (0 <= result && result <= loop - 1) &&
    (result == divcount(num, loop - 1)) &&
    ((forall (k:Z), 1 <= k && k < loop => (num % k == 0) => result >= 0)) &&
    (z == (z@pre >= 0 ? z@pre : -z@pre)) &&
    (num == num@pre) &&
    ((loop <= z + 1) => (0 <= result && result <= z)) &&
    ((loop > z) => (result == divcount(num, z)))
    */
for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}