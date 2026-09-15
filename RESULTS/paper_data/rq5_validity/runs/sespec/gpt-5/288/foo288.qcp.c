#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (step : Z -> Z -> Z) */
int foo288(int j) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
	
 	/*@ Inv
    (2 <= p) &&
    (ret[0] == 0) &&
    (ret[1] == 1) &&
    (forall (k:Z), 0 <= k && k < 2 => ret[k] == (k==0 ? 0 : 1)) &&
    (2 <= p => step(ret, p-1) == 0) &&
    (exists (k:Z), 0 <= k && k < p && ret[k] == ret[p-1]) &&
    ((p <= j) => (0 <= p && p < ret_len && step(ret, p-1) == 0))
    */
for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
}