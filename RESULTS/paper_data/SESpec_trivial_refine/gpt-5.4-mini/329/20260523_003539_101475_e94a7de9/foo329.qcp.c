#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cube : Z -> Z) */
int foo329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Inv
    (ret >= 0) &&
    (max == 0) &&
    (j >= 1)
    */
for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
	
 	/*@ Inv
    (max == (j - 1) * j / 2) &&
    (j >= 1)
    */
for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}