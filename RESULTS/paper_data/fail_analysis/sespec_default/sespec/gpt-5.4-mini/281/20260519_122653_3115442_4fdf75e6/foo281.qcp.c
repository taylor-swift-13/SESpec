#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo281(int num);

const char * foo281(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((index <= num@pre) => (num % index == 0 => result >= 0)) &&
((index <= num@pre) => (result == 0 || result > 0)) &&
(num == num@pre
          loop assigns index, result)
    */
    
            for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}