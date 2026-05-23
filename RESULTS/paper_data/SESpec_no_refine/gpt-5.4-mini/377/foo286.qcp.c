#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo286(int seed, int p);

int foo286(int seed, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > seed - p)
			p = seed - p;
		int b = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (seed == seed@pre
          loop assigns r, b)
    */
    
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}