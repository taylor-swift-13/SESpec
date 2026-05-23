#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo290(int c);

int foo290(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= p) &&
(N_l[0] == 2) &&
(N_l[1] == 1) &&
(forall (k:Z), 2 <= k && k < p => N_l[k] == N_l[k - 1] + 2 * N_l[k - 2]
          loop assigns p, N_l[0 .. c])
    */
    
            for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
}