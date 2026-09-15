#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo283_c374(int number);

int foo283_c374(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c) &&
(number == number@pre) &&
(0 <= div && div <= c - 1) &&
(div == count_divisors_prefix(number, c - 1)
      loop assigns c, div)
    */
    
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }
		return div;
}