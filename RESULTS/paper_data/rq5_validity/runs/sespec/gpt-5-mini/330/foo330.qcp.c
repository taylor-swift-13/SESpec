#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cubes_sum : Z -> Z) */

/*@ Extern Coq (sum_n : Z -> Z) */
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
    (0 <= j) &&
    (0 <= diff) &&
    (result == cubes_sum(j-1)) &&
    (max == 0) &&
    (diff == diff@pre)
    */
for (int j = 1; j <= diff; j++) {
		result += j * j * j;
	}
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (0 <= max) &&
    (0 <= j) &&
    (0 <= diff) &&
    (max == sum_n(j-1)) &&
    (forall (k:Z), 1 <= k && k < j => sum_n(k) < sum_n(k+1)) &&
    ((j > 1) => (max >= (j-1))) &&
    ((j == diff + 1) => (max == sum_n(diff)))
    */
for (int j = 1; j <= diff; j++) {
		max += j;
	}
		return result - max;
}