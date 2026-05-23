#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo162_c329(int diff);

int foo162_c329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= j && j <= diff + 1) &&
(ret == sum_cubes(j-1)) &&
(diff >= 0
          loop assigns j, ret)
    */
    
            for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (1 <= j && j <= diff + 1) &&
((j <= diff) => (max == (j-1)*(j)/2)) &&
((!(j <= diff)) => (max == diff*(diff+1)/2)
          loop assigns j, max)
    */
    
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}