#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (comb : Z -> Z -> Z) */
int foo377(int seed, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > seed - p)
			p = seed - p;
		int b = 1;
	
 	/*@ Inv
    (1 <= r && r <= p + 1) &&
    (0 <= p) &&
    (p <= seed - p) &&
    (r - 1 <= p) &&
    (b == comb(seed, r - 1))
    */
for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}