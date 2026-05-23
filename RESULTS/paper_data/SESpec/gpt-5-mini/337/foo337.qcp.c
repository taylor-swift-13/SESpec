#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo337(int num);

int foo337(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= j) &&
(num >= 1) &&
(num@pre >= 1) &&
(ret >= 0
	  loop assigns j, ret, num)
    */
    
	for (int j = 2; j <= num; j++) {
		
		/*@
		  loop invariant 2 <= j;
		  loop invariant num >= 1;
		  loop invariant \at(num,Pre) >= 1;
		  loop invariant ret >= 0;
		  loop assigns j, num, ret;
		*/
		while (num % j == 0) {
			ret = j;
			num /= j;
		}
		
	}
		return ret;
}