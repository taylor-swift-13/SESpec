#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo191(int count);

int foo191(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *W = (int *)malloc(sizeof(int) * (count + 1));
int W_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
}