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
    (2 <= j) &&
    (first == fact(j - 1)) &&
    (1 <= first) &&
    (num == num@pre)
    */
for (int j = 2; j <= num; j++) {
			first *= j;
		}
		int result = 0;
	
 	/*@ Inv
    (0 <= first) &&
    (0 <= result && result <= 9) &&
    (result == 0 || result > 0)
    */
while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}