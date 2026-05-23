#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo282(int number);

int foo282(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= index && index <= number + 1) &&
(div == count_divisors(number, index - 1)) &&
(number == number@pre
      loop assigns index, div)
    */
    
    for (int index = 1; index <= number; index++) {
        if (number % index == 0) {
            div++;
        }
    }
		return div;
}