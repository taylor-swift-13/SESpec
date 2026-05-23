#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo251(int size);

int foo251(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (size == size@pre) &&
(size == size@pre
          loop assigns c, ret, total)
    */
    
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
}