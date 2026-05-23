#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div : Z -> Z -> Z -> Z) */
const char * foo280(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (c <= number + 1) &&
    (number == number@pre) &&
    (0 <= result && result <= c - 1) &&
    (result == count_div(number, 1, c)) &&
    (forall (k:Z), 1 <= k && k < c => (number % k != 0 || result >= 1)) &&
    (forall (k:Z), 1 <= k && k < c => (number % k == 0 => count_div(number, 1, c) >= count_div(number, 1, k) + 1)) &&
    ((c > number) => (result == count_div(number, 1, number + 1))) &&
    ((c > number) => (number == number@pre))
    */
for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}