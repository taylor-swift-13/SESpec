#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo369(int value, int p, int dy) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    (1 <= c) &&
    (result == 0 || (1 <= result && result < c && (result % p) == dy))
    */
for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}