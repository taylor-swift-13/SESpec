#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (sum4 : Z -> Z) */

int foo396(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*0*/ 
 /*@ Inv
    (even == sum4(c - 1)) &&
    (c >= 1)
    */
for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}