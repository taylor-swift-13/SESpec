#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors : Z -> Z -> Z) */
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
    (result == count_divisors(num, index - 1)) &&
    (z == z@pre) &&
    (num == num@pre) &&
    (forall (k:Z), 1 <= k && k < index => (k > 0 && k <= z))
    */
for (int index = 1; index <= z; index++) {
        if (num % index == 0) {
            result = result + 1;
        }
    }
		return result;
}