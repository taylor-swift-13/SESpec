#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (pow2 : Z -> Z) */
/*@ Extern Coq (closed_j : Z -> Z) */
int foo287(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
	
 	/*@ Inv
    (j_len == c + 1) &&
    (j[0] == 0) &&
    (exists (t:Z), 0 <= t && t < p && j[t] == j[p - 1])
    */
for (int p = 2; p <= c; p++) {
        j[p] = j[p - 1]
             + 2 * j[p - 2];
    }
		return j[c];
}