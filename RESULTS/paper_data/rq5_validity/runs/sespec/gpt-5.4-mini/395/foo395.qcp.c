#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo395(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int odd = 0;
	
 	/*@ Inv
    (p == p@pre) &&
    (0 <= odd) &&
    (odd >= 0)
    */
for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }
		return odd;
}