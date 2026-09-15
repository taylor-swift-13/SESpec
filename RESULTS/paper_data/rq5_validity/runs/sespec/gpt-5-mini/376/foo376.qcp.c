#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo376(int seed, int m);

int foo376(int seed, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (m > seed - m)
			m = seed - m;
		int b = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (seed == seed@pre
          loop assigns r, b)
    */
    
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}