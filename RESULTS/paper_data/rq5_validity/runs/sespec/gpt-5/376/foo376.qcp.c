#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (binom : Z -> Z -> Z) */
int foo376(int seed, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (m > seed - m)
			m = seed - m;
		int b = 1;
	
 	/*@ Inv
    (1 <= r && r <= m + 1) &&
    (0 <= m && m <= seed) &&
    (seed == seed@pre) &&
    (r == 1 => b == 1)
    */
for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }
		return b;
}