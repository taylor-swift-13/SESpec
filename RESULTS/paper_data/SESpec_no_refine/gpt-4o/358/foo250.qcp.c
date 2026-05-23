#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo250(int size);

int foo250(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (size == size@pre
      loop assigns index, average, total)
    */
    
    for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }
		return average / total;
}