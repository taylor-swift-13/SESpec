#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcnt : Z -> Z -> Z) */
const char * foo280(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    ((number@pre >= 0) => (c <= number@pre + 1)) &&
    (0 <= result && result <= c - 1) &&
    (result == divcnt(number@pre, c - 1)) &&
    (forall (k:Z), 1 <= k && k < c => divcnt(number@pre, k) <= divcnt(number@pre, c - 1)) &&
    (result > 0 => exists (k:Z), 1 <= k && k < c && (number@pre % k == 0)) &&
    ((number@pre >= 0 && c == number@pre + 1) => result == divcnt(number@pre, number@pre)) &&
    (forall (k:Z), 1 <= k && k < c => (k <= c - 1)) &&
    ((c <= number@pre) => (1 <= c)) &&
    ((c <= number@pre) => ((0 <= result && result <= c - 1) && (result == divcnt(number@pre, c - 1)))) &&
    (number == number@pre)
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