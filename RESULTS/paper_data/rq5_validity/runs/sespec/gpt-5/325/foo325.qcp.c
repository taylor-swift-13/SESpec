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
    (num == num@pre) &&
    (2 <= j) &&
    ((j <= num@pre) => (j <= num)) &&
    ((j == 2) => (first == 1)) &&
    ((j <= num@pre) => (first >= 1))
    */
for (int j = 2; j <= num; j++) {
        first *= j;
    }
		int result = 0;
	
 	/*@ Inv
    (0 <= result && result <= 9) &&
    ((first > 0) => (result >= 0 && result <= 9))
    */
while (first > 0) {
        result = first % 10;
        first /= 10;
    }
		return result;
}