#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo31(int num1, int num2);

int foo31(int num1, int num2) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1;
	 	num1 = (0 <= num1) ? num1 : -num1;
		num2 = (0 <= num2) ? num2 : -num2;

		if (num1 == 0 && num2 == 0) {
			return -1;
		}

		if (num1 == 0 || num2 == 0) {
			return (num1 > num2) ? num1 : num2;
		}

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= result) &&
(result <= num1) &&
(result <= num2) &&
(num1 % result == 0) &&
(num2 % result == 0) &&
(num1 >= 0 && num2 >= 0) &&
(1 <= i && i <= num1 + 1) &&
(result <= i
		  loop assigns i, result)
    */
    
		for (int i = 1; i <= num1 && i <= num2; i++) {
			if (num1 % i == 0 && num2 % i == 0) {
				result = i;
			}
		}
		return result;
}