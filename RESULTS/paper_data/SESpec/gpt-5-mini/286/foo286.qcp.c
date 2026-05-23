#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo286(int j);

int foo286(int j) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *r = (int *)malloc(sizeof(int) * (j + 1));
int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= p && p <= j + 1
      loop assigns p, r_l[0..j])
    */
    
    for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1] + 2 * r[p - 2];
    }
		return r[j];
}