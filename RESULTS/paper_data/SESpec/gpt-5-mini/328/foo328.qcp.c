#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo328(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (1 <= c && c <= diff + 1) &&
    (0 <= result) &&
    (0 <= max)
    */
for (int c = 1; c <= diff; c++) {
		result += c * c * c;
	}
	
 	/*@ Inv
    (1 <= c && c <= diff + 1) &&
    (0 <= result) &&
    (0 <= max) &&
    (max == ( (c - 1) * c / 2 )) &&
    ((c == diff + 1) => (max == (diff * (diff + 1) / 2)))
    */
for (int c = 1; c <= diff; c++) {
		max += c;
	}
		return result - max;
}