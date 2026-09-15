#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sumcube : Z -> Z) */

/*@ Extern Coq (sum : Z -> Z) */
int foo330(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (max == 0) &&
    (j >= 1) &&
    (result == sumcube(j - 1))
    */
for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
	
 	/*@ Inv
    (j >= 1) &&
    (max == sum(j - 1))
    */
for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
}