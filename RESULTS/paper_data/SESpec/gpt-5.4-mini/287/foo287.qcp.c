#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo287(int c);

int foo287(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (p >= 2) &&
(j_l[0] == 0) &&
(j_l[1] == 1) &&
(forall (i:Z), 2 <= i && i < p => j_l[i] == j_l[i - 1] + 2 * j_l[i - 2]
          loop assigns p, j_l[0..c])
    */
    
            for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}