#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcount : Z -> Z -> Z -> Z) */
const char * foo282(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (num == num@pre) &&
    (0 <= result) &&
    (result == divcount(num, 1, c)) &&
    (forall (k:Z), 1 <= k && k < c => (num % k == 0 => result >= 1))
    */
for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}