#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z -> Z) */
/*@ Extern Coq (sum_linear : Z -> Z -> Z) */
int foo330(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (diff == diff@pre) &&
    (max == 0)
    */
for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }
	
 	/*@ Inv
    (diff == diff@pre)
    */
for (int j = 1; j <= diff; j++) {
        max += j;
    }
		return result - max;
}