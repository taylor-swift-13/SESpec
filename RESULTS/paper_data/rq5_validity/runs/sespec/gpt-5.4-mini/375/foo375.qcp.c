#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (binomial : Z -> Z -> Z) */
int foo375(int num, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > num - p)
			p = num - p;
		int b = 1;
	
 	/*@ Inv
    (1 <= r) &&
    (p < 1 || r <= p + 1) &&
    (num == num@pre) &&
    (p == p@pre || p == num@pre - p@pre) &&
    (p < 0 || r - 1 <= p)
    */
for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
}