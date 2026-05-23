#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo375(int num, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > num - p)
			p = num - p;
		int b = 1;
	
 	/*0*/ 
 /*@ Inv
    (b == 1 || b != 0) &&
    (r >= 1)
    */
for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
}