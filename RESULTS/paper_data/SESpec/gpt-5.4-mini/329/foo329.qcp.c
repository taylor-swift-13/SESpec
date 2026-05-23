#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cube_sum : Z -> Z) */

/*@ Extern Coq (sum_upto : Z -> Z) */
int foo329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (ret == cube_sum(j - 1)) &&
    (ret >= 0) &&
    (max == 0) &&
    (diff == diff@pre)
    */
for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
	
 	/*@ Inv
    (1 <= j && j <= diff + 1) &&
    (max == sum_upto(j - 1)) &&
    (0 <= max) &&
    (max <= sum_upto(j - 1)) &&
    (ret == cube_sum(diff)) &&
    (diff == diff@pre) &&
    (ret - max == cube_sum(diff) - sum_upto(j - 1))
    */
for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}