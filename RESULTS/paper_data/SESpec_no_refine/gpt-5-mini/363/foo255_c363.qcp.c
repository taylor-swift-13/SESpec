#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo255_c363(int size);

int foo255_c363(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}