#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo289(int c);

int foo289(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (j_len == c + 1) &&
(forall (k:Z), 2 <= k && k < d => j_l[k] == j_l[k - 1] + 2 * j_l[k - 2]
      loop assigns d, j_l[0..c])
    */
    
    for (d = 2; d <= c; d++) {
        j[d] = j[d - 1] + 2 * j[d - 2];
    }
		return j[c];
}