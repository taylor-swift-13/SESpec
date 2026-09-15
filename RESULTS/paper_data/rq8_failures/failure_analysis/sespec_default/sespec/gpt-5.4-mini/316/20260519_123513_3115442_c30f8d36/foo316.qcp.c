#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo316(int number);

int foo316(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (number == 1)
			return 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= c) &&
(result >= 0) &&
((c <= number / c) => (result >= 0)) &&
((!(c <= number / c)) => (result >= 0)
          loop assigns c, result)
    */
    
            for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}