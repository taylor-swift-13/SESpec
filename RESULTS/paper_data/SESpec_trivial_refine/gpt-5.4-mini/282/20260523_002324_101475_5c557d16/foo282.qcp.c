#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (divides : Z -> Z -> Prop) */

const char * foo282(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    (c == 1 || c <= num + 1) &&
    (0 <= result && result <= c - 1) &&
    (result == \numof int i 1 <= i && i < c && divides(num, i))
    */
for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}