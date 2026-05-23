#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo325(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Inv
    (2 <= j) &&
    (j <= num@pre + 1 || num@pre < 2) &&
    (1 <= first) &&
    (num == num@pre) &&
    ((j == 2) => (first == 1))
    */
for (int j = 2; j <= num; j++) {
		first *= j;
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