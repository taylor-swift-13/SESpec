#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo302_c386(int num, int b, int r);

int foo302_c386(int num, int b, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}