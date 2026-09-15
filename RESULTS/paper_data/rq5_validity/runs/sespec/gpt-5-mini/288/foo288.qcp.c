#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (seq_ret : Z -> Z) */
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
    (2 <= j + 1) &&
    (ret_len == j + 1) &&
    (ret_len >= 2) &&
    (2 <= p && p <= j + 1) &&
    (ret[0] == seq_ret(0)) &&
    (ret[1] == seq_ret(1))
    */
for (int p = 2; p <= j; p++) {
        ret[p] = ret[p - 1]
                + 2 * ret[p - 2];
    }
		return ret[j];
}