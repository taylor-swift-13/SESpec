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
    (num == num@pre)
    */
for (int j = 2; j <= num; j++) {
        first *= j;
    }
		int result = 0;
	
 	/*@ Inv
    (result >= 0 && result <= 9) &&
    (num == num@pre) &&
    ((first == 0) => (result >= 0 && result <= 9))
    */
while (first > 0) {
        result = first % 10;
        first /= 10;
    }
		return result;
}