#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo280(int number);

const char * foo280(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= result && result <= c - 1) &&
(result == cnt_divs(number, c - 1)) &&
((c <= number@pre) => (result == cnt_divs(number@pre, c - 1))) &&
((c <= number@pre) => (result >= 0)) &&
(number == number@pre
          loop assigns c, result)
    */
    
            for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}