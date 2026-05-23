#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (jrec : Z -> Z) */
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
    (2 <= j_len) &&
    (2 <= (c + 1)) &&
    (0 <= p && p <= c + 1) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < p => j[k] == jrec(k)) &&
    (forall (k:Z), 0 <= k && k < p => 0 <= j[k]) &&
    ((p <= c) => j[p] == jrec(p)) &&
    ((!(p <= c)) => (p == c + 1)) &&
    (forall (k:Z), 0 <= k && k <= c => j[k] == jrec(k) || k >= p)
    */
for (int p = 2; p <= c; p++) {
		j[p] = j[p - 1] + 2 * j[p - 2];
	}
		return j[c];
}