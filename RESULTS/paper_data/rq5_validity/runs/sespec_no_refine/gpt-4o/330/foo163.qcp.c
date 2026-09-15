#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo163(int diff);

int foo163(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (max == 0) &&
(diff == diff@pre
      loop assigns j, result)
    */
    
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (diff == diff@pre
      loop assigns j, max)
    */
    
    for (int j = 1; j <= diff; j++) {
        max += j;
    }
		return result - max;
}