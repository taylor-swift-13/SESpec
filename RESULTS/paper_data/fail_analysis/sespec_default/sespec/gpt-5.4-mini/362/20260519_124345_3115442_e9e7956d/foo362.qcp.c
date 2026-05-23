#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo362(int size);

int foo362(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c >= 1) &&
(size == size@pre) &&
(total >= 0) &&
(result >= 0
          loop assigns c, result, total)
    */
    
        for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}