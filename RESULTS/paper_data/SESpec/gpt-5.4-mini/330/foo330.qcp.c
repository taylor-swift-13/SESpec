#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cube_sum : Z -> Z) */

/*@ Extern Coq (tri_sum : Z -> Z) */
int foo330(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (max == 0) &&
    (diff == diff@pre) &&
    (result >= 0) &&
    (result == cube_sum(j - 1))
    */
for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (diff == diff@pre) &&
    (0 <= max) &&
    (max == tri_sum(j - 1))
    */
for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
}