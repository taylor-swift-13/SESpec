#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo289(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
	
 	/*@ Inv
    (2 <= d && d <= c + 1) &&
    (0 <= d && d <= j_len) &&
    (j_len == c + 1) &&
    (j[0] == 2) &&
    (j[1] == 1) &&
    (forall (k:Z), 2 <= k && k < d => j[k] == j[k-1] + 2 * j[k-2]) &&
    (forall (k:Z), 0 <= k && k < d => k < j_len)
    */
for (int d = 2; d <= c; d++) {
        j[d] = j[d - 1]
                + 2 * j[d - 2];
    }
		return j[c];
}