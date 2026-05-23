#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo316(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (number == 1)
			return 1;
	
 	/*@ Inv
    (2 <= c) &&
    (c <= number + 1) &&
    (0 <= result) &&
    (result <= c - 2) &&
    (forall (d:Z), 2 <= d && d < c => d > 0) &&
    (forall (d:Z), 2 <= d && d < c => (d <= number / d)) &&
    (result == 0 => forall (d:Z), 2 <= d && d < c => !divides(number, d)) &&
    (forall (d:Z), 2 <= d && d < c => (divides(number, d) => result >= 1))
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