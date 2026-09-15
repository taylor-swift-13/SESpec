#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cntdiv : Z -> Z -> Z -> Z) */
const char * foo282(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (num@pre < 1 => c == 1) &&
    (num@pre >= 1 => 1 <= c && c <= num@pre + 1) &&
    (num == num@pre) &&
    (result == cntdiv(num, 1, c)) &&
    (0 <= result && result <= c - 1) &&
    (result > 0 => (exists (k:Z), 1 <= k && k < c && num % k == 0))
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