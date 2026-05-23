#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo192(int num, int z);

int foo192(int num, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}