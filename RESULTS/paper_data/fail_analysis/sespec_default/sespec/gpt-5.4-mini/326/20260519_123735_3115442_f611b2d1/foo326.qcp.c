#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo326(int num);

int foo326(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (num == num@pre
          loop assigns c, first)
    */
    
        for (int c = 2; c <= num; c++) {
			first *= c;
		}
		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (result == 0 || result >= 0
          loop assigns result, first)
    */
    
        while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}