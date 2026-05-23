#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo336(int num);

int foo336(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= c) &&
(result >= 0
      loop assigns c, result, num)
    */
    
    for (int c = 2; c <= num; c++) {
        /*@
          loop invariant 2 <= c;
          loop invariant result >= 0;
          loop assigns c, num, result;
        */
        while (num % c == 0) {
            result = c;
            num /= c;
        }
    }
		return result;
}