#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z) */
int foo328(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (c >= 1) &&
    (diff == diff@pre) &&
    (max == 0) &&
    (result >= 0) &&
    (result == sum_cubes(c - 1)) &&
    ((c <= diff@pre) => (result == sum_cubes(c - 1))) &&
    ((c <= diff@pre) => (result >= 0)) &&
    ((!(c <= diff@pre)) => ((max == 0)&&(result >= 0)&&(diff == diff@pre)))
    */
for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
	
 	/*@ Inv
    (c >= 1) &&
    (diff == diff@pre) &&
    (result >= 0) &&
    (max >= 0) &&
    (max == ((c - 1) * c) / 2) &&
    ((c <= diff) => (max == ((c - 1) * c) / 2))
    */
for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}