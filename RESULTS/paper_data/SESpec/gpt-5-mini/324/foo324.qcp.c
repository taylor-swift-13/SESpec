#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact : Z -> Z) */
int foo324(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Inv
    (2 <= c) &&
    (c <= number@pre + 1) &&
    (first >= 1) &&
    (number == number@pre) &&
    ((c <= number@pre) => (first == fact(c-1))) &&
    ((c <= number@pre) => (first >= 1)) &&
    ((!(c <= number@pre)) => (first == fact(number@pre)))
    */
for (int c = 2; c <= number; c++) {
        first *= c;
    }
		int result = 0;
	
 	/*@ Inv
    (0 <= result && result <= 9) &&
    (first >= 0) &&
    ((!(first > 0)) => (first == 0 && 0 <= result && result <= 9))
    */
while (first > 0) {
        result = first % 10;
        first /= 10;
    }
		return result;
}