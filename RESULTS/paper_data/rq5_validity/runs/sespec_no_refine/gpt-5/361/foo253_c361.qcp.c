#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo253_c361(int size);

int foo253_c361(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (size == size@pre
      loop assigns j, average, total)
    */
    
    for (int j = 1; j <= size; j++) {
        if (j % 2 == 0) {
            average += j;
            total++;
        }
    }
		return average / total;
}