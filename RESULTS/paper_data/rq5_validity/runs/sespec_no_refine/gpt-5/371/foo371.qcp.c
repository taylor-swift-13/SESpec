#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo371(int value, int p, int z);

int foo371(int value, int p, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (z == z@pre) &&
(p == p@pre) &&
(value == value@pre
      loop assigns c, result)
    */
    
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }
		return result;
}