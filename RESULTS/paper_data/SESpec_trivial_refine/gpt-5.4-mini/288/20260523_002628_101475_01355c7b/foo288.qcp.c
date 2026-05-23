#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (seq : Z -> Z) */

int foo288(int j) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
	
 	/*0*/ 
 /*@ Inv
    (2 <= p && p <= j + 1) &&
    (forall (i:Z), 0 <= i && i < p => ret[i] == seq(i))
    */
for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
}