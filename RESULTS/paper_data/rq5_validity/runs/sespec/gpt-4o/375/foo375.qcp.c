#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (factorial : Z -> Z) */
/*@ Extern Coq (combination : Z -> Z -> Z) */
int foo375(int num, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > num - p)
			p = num - p;
		int b = 1;
	
 	/*@ Inv
    (1 <= r && r <= p + 1) &&
    (p == (p@pre > num@pre - p@pre ? num@pre - p@pre : p@pre)) &&
    (num == num@pre)
    */
for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }
		return b;
}