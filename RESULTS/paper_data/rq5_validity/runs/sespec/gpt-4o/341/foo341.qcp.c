#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors : Z -> Z -> Z) */
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
    (result == count_divisors(num, loop - 1)) &&
    (forall (k:Z), 1 <= k && k < loop => (num % k == 0 => count_divisors(num, k) == count_divisors(num, k - 1) + 1)) &&
    (forall (k:Z), 1 <= k && k < loop => (num % k != 0 => count_divisors(num, k) == count_divisors(num, k - 1))) &&
    (z == z@pre) &&
    (num == num@pre)
    */
for (int loop = 1; loop <= z; loop++) {
        if (num % loop == 0) {
            result = result + 1;
        }
    }
		return result;
}