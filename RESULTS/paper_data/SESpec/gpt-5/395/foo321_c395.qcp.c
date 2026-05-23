#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo321_c395(int p);

int foo321_c395(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int odd = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c >= 1) &&
(odd == 16 * sum4(c - 1)) &&
(p == p@pre
          loop assigns c, odd)
    */
    
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}