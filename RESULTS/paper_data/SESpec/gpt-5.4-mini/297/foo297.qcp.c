#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fib : Z -> Z) */
int foo297(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*@ Inv
    (2 <= l) &&
    (result[0] == 2) &&
    (result[1] == 1) &&
    (forall (k:Z), 0 <= k && k < l => result[k] == fib(k))
    */
for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
}