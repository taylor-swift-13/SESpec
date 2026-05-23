#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo290(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
	
 	/*@ Inv
    (2 <= p) &&
    (N[0] == 2) &&
    (N[1] == 1)
    */
for (int p = 2; p <= c; p++) {
		N[p] = N[p - 1] + 2 * N[p - 2];
	}
		return N[c];
}