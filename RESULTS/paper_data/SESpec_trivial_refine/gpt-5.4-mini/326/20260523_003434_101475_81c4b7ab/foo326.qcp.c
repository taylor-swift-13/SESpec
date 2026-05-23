#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (fact : Z -> Z) */

int foo326(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*0*/ 
 /*@ Inv
    (2 <= c && c <= num + 1) &&
    (first == fact(c - 1)) &&
    (first >= 1)
    */
for (int c = 2; c <= num; c++) {
			first *= c;
		}
		int result = 0;
	
 	/*1*/ 
 /*@ Inv
    (first >= 0) &&
    (0 <= result && result <= 9)
    */
while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}