#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo393(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*0*/ 
 /*@ Inv
    (ret >= 1) &&
    (loop >= 1)
    */
for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int remainder = (int) (ret % 100);
		return remainder;
}