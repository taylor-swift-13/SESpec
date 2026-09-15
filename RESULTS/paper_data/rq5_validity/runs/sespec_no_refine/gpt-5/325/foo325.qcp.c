#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo325(int num);

int foo325(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (num == num@pre
      loop assigns j, first)
    */
    
    for (int j = 2; j <= num; j++) {
        first *= j;
    }
		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (0 <= result && result <= 9
          loop assigns result, first)
    */
    
            while (first > 0) {
        result = first % 10;
        first /= 10;
    }
		return result;
}