#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div_prefix : Z -> Z -> Z) */
int foo341(int num, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Inv
    (1 <= loop && loop <= z + 1) &&
    (0 <= result) &&
    (result == count_div_prefix(num, loop - 1)) &&
    (( z@pre >= 0 && z == z@pre ) || ( z@pre < 0 && z == -z@pre )) &&
    (num == num@pre)
    */
for (int loop = 1; loop <= z; loop++) {
		if (num % loop == 0) {
			result = result + 1;
		}
	}
		return result;
}