#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (coeff : Z -> Z -> Z) */
int foo376(int seed, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (m > seed - m)
			m = seed - m;
		int b = 1;
	
 	/*@ Inv
    (1 <= r) &&
    (seed == seed@pre) &&
    (m <= m@pre) &&
    (b == coeff(seed, r - 1)) &&
    ((r <= m) => (b == coeff(seed, r - 1))) &&
    ((r > m) => (b == coeff(seed, m)))
    */
for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
		return b;
}