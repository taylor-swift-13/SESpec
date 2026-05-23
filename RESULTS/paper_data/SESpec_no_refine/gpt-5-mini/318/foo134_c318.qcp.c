#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo134_c318(int num);

int foo134_c318(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
}