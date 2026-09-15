#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors_upto : Z -> Z -> Z) */
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
    (0 <= result) &&
    (result <= c - 2) &&
    (result == count_divisors_upto(number, c)) &&
    (forall (d:Z), 2 <= d && d < c && number % d == 0 => result >= 1) &&
    (exists (d:Z), 2 <= d && d < c && number % d == 0 => result > 0) &&
    ((c <= number / c) => (result >= 0)) &&
    ((!(c <= number / c)) => (result >= 0))
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