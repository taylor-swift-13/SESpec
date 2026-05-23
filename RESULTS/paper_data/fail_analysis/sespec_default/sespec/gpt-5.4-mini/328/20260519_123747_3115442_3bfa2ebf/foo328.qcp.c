#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo328(int diff);

int foo328(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c) &&
(result == sum_cubes(c - 1)) &&
(max == 0) &&
(diff == diff@pre
          loop assigns c, result)
    */
    
            for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (0 <= c) &&
(max == (c - 1) * c / 2) &&
(diff == diff@pre
          loop assigns c, max)
    */
    
            for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}