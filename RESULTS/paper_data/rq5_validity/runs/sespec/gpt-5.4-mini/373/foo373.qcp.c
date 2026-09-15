#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors : Z -> Z -> Z) */
int foo373(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Inv
    (1 <= index) &&
    (index >= 1) &&
    (0 <= div) &&
    (div <= index - 1) &&
    (div == count_divisors(number, index - 1)) &&
    (number == number@pre)
    */
for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
}