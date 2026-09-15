#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_cubes : Z -> Z) */
/*@ Extern Coq (sum_upto : Z -> Z) */

int foo328(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (result == sum_cubes(c - 1)) &&
    (c >= 1)
    */
for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
	
 	/*1*/ 
 /*@ Inv
    (max == sum_upto(c - 1)) &&
    (c >= 1)
    */
for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}