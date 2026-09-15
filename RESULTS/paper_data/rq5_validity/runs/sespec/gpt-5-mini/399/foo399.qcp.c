#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo399(int value) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (0 <= result) &&
    ((value@pre > 0) => (value >= 0)) &&
    (value <= value@pre) &&
    ((value@pre > 0) => (result >= 0)) &&
    ((value@pre > 0) => (value == value@pre || value < value@pre || result == 0))
    */
while (value > 0) {
		value /= 10;
		result++;
	}
		return result;
}