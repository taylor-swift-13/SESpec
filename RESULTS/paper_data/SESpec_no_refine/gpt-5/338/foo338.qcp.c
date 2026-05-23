#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo338(int num);

int foo338(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int j = 2; j <= num; j++) {
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}