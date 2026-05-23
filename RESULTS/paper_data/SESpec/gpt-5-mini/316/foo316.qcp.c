#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo316(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (number == 1)
			return 1;
	
 	/*0*/ 
 /*@ Inv
    (2 <= c) &&
    (c <= number / c + 1) &&
    (0 <= result) &&
    (result <= c - 2) &&
    ((forall (d:Z), 2 <= d && d < c => (number % d == 0) => (number / d >= d))) &&
    ((c <= number / c) => result >= 0) &&
    ((!(c <= number / c)) => (c > number / c))
    */
for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}