#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcount : Z -> Z -> Z) */
int foo339(int num, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Inv
    (1 <= index && index <= z + 1) &&
    (0 <= result && result <= index - 1) &&
    (result == divcount(num, index - 1)) &&
    (z >= 0) &&
    (num == num@pre) &&
    (z == (z@pre < 0 ? -z@pre : z@pre))
    */
for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
}