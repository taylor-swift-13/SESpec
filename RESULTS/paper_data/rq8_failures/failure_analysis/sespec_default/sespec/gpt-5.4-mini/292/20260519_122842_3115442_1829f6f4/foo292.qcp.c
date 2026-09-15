#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo292(int seed);

int foo292(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (forall (i:Z), 0 <= i && i < count => p_l[i] < 1000000000) &&
(forall (i:Z), 2 <= i && i < count =>
                           p_l[i] == (2 * p_l[i - 1] + p_l[i - 2]) % 1000000000
          loop assigns count, p_l[0 .. seed])
    */
    
            for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
		return p[seed];
}