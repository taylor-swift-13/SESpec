#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (seqN : Z -> Z) */
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
    (N_len == c + 1) &&
    (p >= 2) &&
    (forall (k:Z), (0 <= k && k < p) => N[k] == seqN(k)) &&
    (forall (k:Z), (2 <= k && k < p) => N[k] == N[k - 1] + 2 * N[k - 2]) &&
    ((p <= c) => (0 <= p && p < N_len && 0 <= p - 1 && p - 1 < N_len && 0 <= p - 2 && p - 2 < N_len))
    */
for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
}