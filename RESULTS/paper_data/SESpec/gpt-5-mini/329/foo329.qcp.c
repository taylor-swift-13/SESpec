#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z) */
int foo329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Inv
    (0 <= j-1) &&
    (0 <= ret) &&
    (ret == sum_cubes(j-1)) &&
    (max == 0) &&
    (diff == diff@pre)
    */
for (int j = 1; j <= diff; j++) {
		ret += j * j * j;
	}
	
 	/*@ Inv
    (0 <= j-1) &&
    (0 <= max) &&
    (max == ((j-1) * j) / 2) &&
    (forall (k:Z), 1 <= k && k < j => 1 <= k) &&
    ((j <= diff) => (max + j == (j * (j + 1)) / 2)) &&
    ((!(j <= diff)) => (max == (diff * (diff + 1)) / 2))
    */
for (int j = 1; j <= diff; j++) {
		max += j;
	}
		return ret - max;
}