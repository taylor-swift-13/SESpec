#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z) */
int foo330(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (0 <= result) &&
    (result == sum_cubes(j - 1)) &&
    (max == 0) &&
    (diff == diff@pre)
    */
for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (0 <= max) &&
    (max == (j - 1) * j / 2) &&
    (forall (k:Z), 1 <= k && k < j => ((k - 1) * k / 2) <= max) &&
    ((j <= diff) => (max == (j - 1) * j / 2)) &&
    ((!(j <= diff)) => (j == diff + 1 && max == diff * (diff + 1) / 2))
    */
for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
}