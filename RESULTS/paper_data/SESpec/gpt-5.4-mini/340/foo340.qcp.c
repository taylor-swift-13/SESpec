#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors : Z -> Z -> Z) */
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
    (0 <= result && result <= loop - 1) &&
    (result == count_divisors(n, loop - 1)) &&
    (forall (k:Z), 1 <= k && k < loop => (n % k == 0 || n % k != 0)) &&
    (forall (k:Z), 1 <= k && k < loop => (n % k == 0 => result >= 1)) &&
    ((loop > z) => (result == count_divisors(n, z))) &&
    ((loop > z) => (0 <= result && result <= z)) &&
    ((loop > z) => (z == (z@pre >= 0 ? z@pre : -z@pre))) &&
    ((loop > z) => (n == n@pre))
    */
for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}