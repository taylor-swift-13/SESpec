#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact : Z -> Z) */
int foo325(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Inv
    (first == fact(j - 1)) &&
    (j >= 2)
    */
for (int j = 2; j <= num; j++) {
			first *= j;
		}
		int result = 0;
	
 	/*@ Inv
    (first >= 0) &&
    (result >= 0 && result <= 9)
    */
while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}