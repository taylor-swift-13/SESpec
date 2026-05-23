#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z -> Z) */
int foo329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Inv
    (diff == diff@pre) &&
    (1 <= j && j <= diff + 1)
    */
for (int j = 1; j <= diff; j++) {
        ret += j * j * j;
    }
	
 	/*@ Inv
    (diff == diff@pre) &&
    (max == (j - 1) * j / 2) &&
    (1 <= j && j <= diff + 1)
    */
for (int j = 1; j <= diff; j++) {
        max += j;
    }
		return ret - max;
}