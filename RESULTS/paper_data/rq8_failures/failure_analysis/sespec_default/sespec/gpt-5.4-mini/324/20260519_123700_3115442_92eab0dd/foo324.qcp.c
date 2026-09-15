#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo324(int number);

int foo324(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (number == number@pre
          loop assigns c, first)
    */
    
        for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (\true) &&
(0 <= result && result < 10
          loop assigns result, first)
    */
    
        while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}