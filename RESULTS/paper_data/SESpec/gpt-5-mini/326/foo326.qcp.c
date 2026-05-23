#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (factorial : Z -> Z) */
int foo326(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Inv
    (2 <= c && c <= num@pre + 1) &&
    (0 <= first) &&
    (first == factorial(c - 1)) &&
    (num == num@pre)
    */
for (int c = 2; c <= num; c++) {
		first *= c;
	}
		int result = 0;
	
 	/*@ Inv
    (0 <= result && result <= 9) &&
    (0 <= first)
    */
while (first > 0) {
		result = first % 10;
		first /= 10;
	}
		return result;
}