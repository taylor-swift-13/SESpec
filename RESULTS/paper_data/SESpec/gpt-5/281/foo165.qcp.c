#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo165(int num);

const char * foo165(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= index) &&
(0 <= result && result <= index - 1) &&
(result == count_div_up_to(num, index - 1)) &&
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