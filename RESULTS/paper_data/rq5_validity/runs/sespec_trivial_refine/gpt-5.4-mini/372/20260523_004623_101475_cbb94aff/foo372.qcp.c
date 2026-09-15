#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo372(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*0*/ 
 /*@ Inv
    (0 <= c && c <= num + 1) &&
    (div == \numof int k 1 <= k && k < c && num % k == 0)
    */
for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}