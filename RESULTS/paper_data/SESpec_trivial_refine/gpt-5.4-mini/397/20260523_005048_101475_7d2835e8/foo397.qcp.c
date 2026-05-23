#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo397(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Inv
    (c >= 1) &&
    (even % 16 == 0) &&
    (even >= 0)
    */
for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}