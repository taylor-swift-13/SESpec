#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo281(int num);

int foo281(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (div >= 0) &&
(num == num@pre) &&
((c <= num@pre) => (div <= c - 1)
          loop assigns c, div)
    */
    
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}