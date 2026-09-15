#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (rec_val : Z -> Z) */
int foo291(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
	
 	/*@ Inv
    (2 <= p && p <= c + 1) &&
    (j_len == c + 1) &&
    (j[0] == 2) &&
    (j[1] == 1) &&
    (forall (k:Z), 2 <= k && k < p => j[k] == j[k-1] + 2 * j[k-2]) &&
    ((p <= c) => (0 <= p-2 < j_len && 0 <= p-1 < j_len && 0 <= p && p < j_len))
    */
for (int p = 2; p <= c; p++) {
        j[p] = j[p - 1]
             + 2 * j[p - 2];
    }
		return j[c];
}