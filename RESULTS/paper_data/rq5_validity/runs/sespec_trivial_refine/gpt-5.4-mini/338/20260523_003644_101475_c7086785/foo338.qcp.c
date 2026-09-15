#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo338(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    (num > 0) &&
    (result == 0 || result >= 2)
    */
for (int j = 2; j <= num; j++) {
		
 	/*1*/ 
 /*@ Inv
    (j >= 2) &&
    (num > 0) &&
    (result == 0 || result >= 2)
    */
while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}