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
    (value == 0 => (result >= 1 || value@pre == 0)) &&
    (result == 0 => value == value@pre) &&
    (result > 0 => value < value@pre) &&
    (value > 0 => value@pre >= 1) &&
    (value > 0 => value@pre / 10 <= value@pre) &&
    ((value@pre > 0) => (0 <= value && value <= value@pre)) &&
    ((!(value@pre > 0)) => ((result == 0)&&(value == value@pre)))
    */
while (value > 0) {
        value /= 10;
        result++;
    }
		return result;
}