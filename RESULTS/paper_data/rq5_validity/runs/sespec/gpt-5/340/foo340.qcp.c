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
    (n == n@pre) &&
    (result >= 0) &&
    (result <= loop - 1) &&
    (forall (d:Z), 1 <= d && d < loop => ((n % d == 0) || (n % d != 0))) &&
    (forall (d:Z), 1 <= d && d < loop && (n % d == 0) => 0 <= d && d <= z) &&
    (forall (t:Z), 1 <= t && t < loop => result >= 0) &&
    (forall (k:Z), 1 <= k && k < loop => ((n % k == 0) => result >= 1) || ((n % k != 0) => result >= 0)) &&
    ((loop <= z@pre) => (loop >= 1 && loop <= z)) &&
    ((loop <= z@pre) => (result >= 0 && result <= loop - 1)) &&
    (n == n@pre)
    */
for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }
		return result;
}