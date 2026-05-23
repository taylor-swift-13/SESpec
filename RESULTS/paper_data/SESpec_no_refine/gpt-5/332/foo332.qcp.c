#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo332(int num, int c);

int foo332(int num, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
		
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c == c@pre) &&
(num == num@pre
          loop assigns var, result)
    */
    
            for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}